/*
   Columbia University DIY Ventilator Challenge
   Arduino Script v0.0.1
   
   MIT Open Source License
   (c) 2019 - 2020.
   All Rights Reserved. 
   Contact: 
  
*/


#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#include "Adafruit_MPRLS.h"

const float VCC = 5.0; //check measured voltage
const float R_DIV = 220; //check measured resistance
const int potPin = A3;
const int alarmButton = 2;
const int buzzer = 3;
const int rel1 = 8;
const int rel2 = 9;
const int rel3 = 10;

// Adafruit pressure sensor
#define RESET_PIN  -1  // set to any GPIO pin # to hard-reset on begin()
#define EOC_PIN    -1  // set to any GPIO pin to read end-of-conversion by pin
Adafruit_MPRLS mpr = Adafruit_MPRLS(RESET_PIN, EOC_PIN);

// declare the LCD screen. 
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup(){
  Serial.begin(9600);
  
  // initialize LCD screen.
  lcd.begin();
  lcd.backlight();
  lcd.clear();

  lcd.setCursor(0, 0);
  lcd.print("DIY Ventilator");
  delay(500);
  lcd.clear();
  
  // set the pin modes
  pinMode(buzzer, OUTPUT);
  pinMode(rel1, OUTPUT);
  pinMode(rel2, OUTPUT);
  pinMode(rel3, OUTPUT);
  pinMode(display, OUTPUT);
  pinMode(alarmButton, INPUT);
  
  // perform system checks
  
}

void loop(){

  //turns off buzzer alarm if button is pressed
  buttonState = digitalRead(alarmButton);
  if(buttonState == HIGH){
  digitalWrite(buzzer, LOW);
  }
  
  // read knob state, adjust inflation speed.
  potState = analogRead(potPin); 
  
  //use Wire Library for i2c
  float pressure_hPa = mpr.readPressure();
}

