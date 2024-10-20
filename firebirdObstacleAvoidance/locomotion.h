/*
 *  firebirdObstacleAvoidance.ino
 *
 *  Created: 01-03-2018 19:24:33
 *  Author: Mitali Sawant(mitali0087@gmail.com)
 */

#ifndef LOCOMOTION_H
#define LOCOMOTION_H

#include "Arduino.h"

//-----------------------Defining left and right motor pins(arduino mapping) on firebird
#define left_en1 23
#define left_en2 22
#define left_pwm 46
#define right_en1 25
#define right_en2 24
#define right_pwm 45

class locomotion
{
	public:
			locomotion();
			void forward(int pwm);
			void backward(int pwm);
			void left(int pwm);
			void right(int pwm);
      void halt();
};

#endif
