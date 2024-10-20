/*
 *  firebirdObstacleAvoidance.ino
 *
 *  Created: 01-03-2018 19:24:33
 *  Author: Mitali Sawant(mitali0087@gmail.com)
 */

#include "locomotion.h"

//----------------------Constructor of the class to initialize motor pins
locomotion :: locomotion()
{
	pinMode(left_en1 , OUTPUT);
	pinMode(left_en2 , OUTPUT);
	pinMode(left_pwm , OUTPUT);
	pinMode(right_en1 , OUTPUT);
	pinMode(right_en2 , OUTPUT);
	pinMode(right_pwm , OUTPUT);
}

//-----------------------Forward motion of firebird at pwm being passed
void locomotion :: forward(int pwm)
{
	digitalWrite(left_en1 , HIGH);
	digitalWrite(left_en2 , LOW);
	analogWrite(left_pwm , pwm);
	digitalWrite(right_en1 , LOW);
	digitalWrite(right_en2 , HIGH);
	analogWrite(right_pwm , pwm);
}

//-----------------------Backward motion of firebird at pwm being passed
void locomotion :: backward(int pwm)
{
	digitalWrite(left_en1 , LOW);
	digitalWrite(left_en2 , HIGH);
	analogWrite(left_pwm , pwm);
	digitalWrite(right_en1 , HIGH);
	digitalWrite(right_en2 , LOW);
	analogWrite(right_pwm , pwm);
}

//-----------------------Soft right turn of firebird at pwm being passed
void locomotion :: right(int pwm)
{
	digitalWrite(left_en1 , HIGH);
	digitalWrite(left_en2 , LOW);
	analogWrite(left_pwm , pwm);
	digitalWrite(right_en1 , LOW);
	digitalWrite(right_en2 , LOW);
	analogWrite(right_pwm , pwm);
}

//-----------------------Soft left turn of firebird at pwm being passed
void locomotion :: left(int pwm)
{
	digitalWrite(left_en1 , LOW);
	digitalWrite(left_en2 , LOW);
	analogWrite(left_pwm , pwm);
	digitalWrite(right_en1 , LOW);
	digitalWrite(right_en2 , HIGH);
	analogWrite(right_pwm , pwm);
}

//-----------------------Halt firebird
void locomotion :: halt()
{
  digitalWrite(left_en1 , LOW);
  digitalWrite(left_en2 , LOW);
  analogWrite(left_pwm , 0);
  digitalWrite(right_en1 , LOW);
  digitalWrite(right_en2 , LOW);
  analogWrite(right_pwm , 0);
}
