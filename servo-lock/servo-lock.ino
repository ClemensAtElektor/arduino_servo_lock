#include <Servo.h>

/*
 * Purpose: Servo-controlled bolt.
 * Board: Arduino Uno
 * Author: Clemens at Elektor
 * History:
 * - created: 15/2/2021
 * This sketch was created with Arduino IDE 1.8.13.
 */

Servo myservo;  // create servo object to control a servo
const int servo_pin = 9;
const int left = 120; // degrees
const int right = 40; // degrees
int pos = 90; // Start halfway.

void setup(void)
{
  Serial.begin(115200);
  myservo.attach(servo_pin);
  myservo.write(pos);
}

void loop(void)
{
  if (Serial.available())
  {
    int ch = tolower(Serial.read());
    if (ch=='c') // Close
    {
      pos = left;
    }
    else if (ch=='o') // Open
    {
      pos = right;
    }
    else if (ch=='h') // Half-way
    {
      pos = 90;
    }
    else if (ch=='r') // Nudge to the right.
    {
      if (pos>right) pos--;
    }
    else if (ch=='l') // Nudge to the left.
    {
      if (pos<left) pos++;
    }
    myservo.write(pos);
    Serial.println(pos);
  }
}
