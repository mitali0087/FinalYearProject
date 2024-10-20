/*
 *  firebirdObstacleAvoidance.ino
 *
 *  Created: 18-04-2018 00:54:27
 *  Author: Mitali Sawant(mitali0087@gmail.com)
 */ 

#include <LiquidCrystal.h>
#include "locomotion.h"

//--------------------Initializing lcd and locomotion class
LiquidCrystal lcd(37, 35, 33, 32, 31, 30);
locomotion bot = locomotion();

//---------------------Defining encoder and sharp sensor pins
#define RIGHT_ENCODER 3
#define LEFT_ENCODER 2

#define sharp_pin1 A9
#define sharp_pin2 A10
#define sharp_pin3 A11
#define sharp_pin4 A12
#define sharp_pin5 A13

int left_count , right_count;

//-----------------------ISR for left and right encoder
void increment_right()
{
  ++right_count;
}

void increment_left()
{
  ++left_count;
}

void setup()
{
  //-------------Intitializing Interrupt pins
  attachInterrupt(digitalPinToInterrupt(RIGHT_ENCODER) , increment_right , RISING);
  attachInterrupt(digitalPinToInterrupt(LEFT_ENCODER) , increment_left , RISING);
  
  //-------------Initializing LCD pin
  pinMode(36, OUTPUT);
  digitalWrite(36, LOW);
  lcd.begin(16, 2);
  
  //-------------Initializing sharp sensor pins as input pins
  pinMode(sharp_pin1, INPUT);
  pinMode(sharp_pin2, INPUT);
  pinMode(sharp_pin3, INPUT);
  pinMode(sharp_pin4, INPUT);
  pinMode(sharp_pin5, INPUT);
  
  //-------------Initializing Serial communication at 115200 baud rate
  Serial.begin(115200);
}

void loop()
{
  //---------------Transmitting encoder readings and bot number through Xbee
  Serial.print(left_count);
  Serial.print(" ");
  Serial.print(right_count);
  Serial.print(" ");
  Serial.print("1");
  Serial.print("\n");
  
  //----------------Reading sharp sensor data
  int sharp_val1 = analogRead(sharp_pin1);
  int sharp_val2 = analogRead(sharp_pin2);
  int sharp_val3 = analogRead(sharp_pin3);
  int sharp_val4 = analogRead(sharp_pin4);
  int sharp_val5 = analogRead(sharp_pin5);
  
  //----------------Printing sharp sensor data on LCD
  lcd.setCursor(0 , 0);
  lcd.print(sharp_val1);
  lcd.setCursor(4 , 0);
  lcd.print(sharp_val2);
  lcd.setCursor(8 , 0);
  lcd.print(sharp_val3);
  lcd.setCursor(0 , 1);
  lcd.print(sharp_val4);
  lcd.setCursor(4 , 1);
  lcd.print(sharp_val5);
  
  //----------------Obstacle detection conditions and avoidance actions
  if(sharp_val3 > 420 && sharp_val3 < 520){
    bot.halt();
    delay(200);
    sharp_val2 = analogRead(sharp_pin2);
    sharp_val4 = analogRead(sharp_pin4);
    sharp_val1 = analogRead(sharp_pin1);
    sharp_val5 = analogRead(sharp_pin5);

    if(sharp_val2 > sharp_val4){
           bot.right(255);
           delay(250);
    }
    else if(sharp_val1 > sharp_val5){
           bot.right(255);
           delay(250);
    }
    else{
          bot.left(255);
          delay(250);
    }
  }
  else if(sharp_val2 > 450 && sharp_val2 < 600){
    bot.halt();
    delay(200);
    bot.right(200);
    delay(250);
  }
  else if(sharp_val4 > 450 && sharp_val4 < 600){
    bot.halt();
    delay(200);
    bot.left(200);
    delay(250);
  }
  else if(sharp_val1 > 300 && sharp_val1 < 380){
    bot.halt();
    delay(200);
    bot.right(200);
    delay(250);
  }
  else if(sharp_val5 > 300 && sharp_val5 < 380){
    bot.halt();
    delay(200);
    bot.left(200);
    delay(250);
  }
  bot.forward(100);
  delay(10);
  lcd.clear();
}

