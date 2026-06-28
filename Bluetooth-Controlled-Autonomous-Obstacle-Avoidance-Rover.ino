#include <SoftwareSerial.h>
#include <Servo.h>

SoftwareSerial BT(2, 3);
Servo scanServo;

#define SERVO_PIN 5
#define TRIG_PIN 6
#define ECHO_PIN 7

#define IN1 8
#define IN2 9
#define IN3 10
#define IN4 11

bool autoMode = false;

void stopMotors()
{
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

void forward()
{
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void backward()
{
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void left()
{
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void right()
{
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

long getDistance()
{
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);

  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);

  digitalWrite(TRIG_PIN, LOW);

  long duration = pulseIn(ECHO_PIN, HIGH, 30000);

  long distance = duration * 0.034 / 2;

  if (distance == 0)
    distance = 400;

  return distance;
}

long lookLeft()
{
  scanServo.write(160);
  delay(500);
  return getDistance();
}

long lookRight()
{
  scanServo.write(20);
  delay(500);
  return getDistance();
}

void obstacleAvoidance()
{
  long frontDistance = getDistance();

  if (frontDistance > 25)
  {
    forward();
    return;
  }

  stopMotors();
  delay(300);

  backward();
  delay(400);

  stopMotors();
  delay(300);

  long leftDistance = lookLeft();
  delay(200);

  long rightDistance = lookRight();
  delay(200);

  scanServo.write(90);
  delay(200);

  if (leftDistance > rightDistance)
  {
    left();
    delay(500);
  }
  else
  {
    right();
    delay(500);
  }

  stopMotors();
}

void setup()
{
  BT.begin(9600);

  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  scanServo.attach(SERVO_PIN);
  scanServo.write(90);

  stopMotors();
}

void loop()
{
  while (BT.available())
  {
    char c = BT.read();

    if (c == '\r' || c == '\n')
      continue;

    if (c == 'O')
    {
      autoMode = true;
      stopMotors();
    }

    else if (c == 'M')
    {
      autoMode = false;
      stopMotors();
    }

    else if (!autoMode)
    {
      switch (c)
      {
        case 'F':
          forward();
          break;

        case 'B':
          backward();
          break;

        case 'L':
          left();
          break;

        case 'R':
          right();
          break;

        case 'S':
          stopMotors();
          break;
      }
    }
  }

  if (autoMode)
  {
    obstacleAvoidance();
  }
}