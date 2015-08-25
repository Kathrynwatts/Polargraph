/**
*  Polargraph Server. - CORE
*  Written by Sandy Noble
*  Released under GNU License version 3.
*  http://www.polargraph.co.uk
*  http://code.google.com/p/polargraph/

Configuration.

This is one of the core files for the polargraph server program.  
It sets up the motor objects (AccelSteppers), and has default
values for the motor, sprocket and microstepping combinations used
by polargraphs so far.

Comment out the blocks of code you don't need.

*/
// motor configurations for the various electrical schemes

// =================================================================
// BEGIN REMOVED BY BILL
// 1. Adafruit motorshield 

//#include <AFMotor.h>
//const int stepType = INTERLEAVE;

//AF_Stepper afMotorA(motorStepsPerRev, 1);
//AF_Stepper afMotorB(motorStepsPerRev, 2);

//void forwarda() { afMotorA.onestep(FORWARD, stepType); }
//void backwarda() { afMotorA.onestep(BACKWARD, stepType); }
//AccelStepper motorA(forwarda, backwarda);

//void forwardb() { afMotorB.onestep(FORWARD, stepType); }
//void backwardb() { afMotorB.onestep(BACKWARD, stepType); }
//AccelStepper motorB(forwardb, backwardb);

//void configuration_motorSetup()
//{
  // no initial setup for these kinds of motor drivers
//}
// END REMOVED BY BILL
// =================================================================
// =================================================================
//
// BEGIN ADDED BY BILL
// 2. Adafruit motorshield V2 - testing
//For use with the Adafruit Motor Shield v2 
//---->	http://www.adafruit.com/products/1438
//
#include <AccelStepper.h>
#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_PWMServoDriver.h"
const int stepType = INTERLEAVE;

// Create the motor shield object with the default I2C address
Adafruit_MotorShield AFMS = Adafruit_MotorShield();

Adafruit_StepperMotor *afMotorA = AFMS.getStepper(motorStepsPerRev, 1);
Adafruit_StepperMotor *afMotorB = AFMS.getStepper(motorStepsPerRev, 2);

void forwarda() { afMotorA->onestep(FORWARD, stepType);  }
void backwarda() { afMotorA->onestep(BACKWARD, stepType);  }
AccelStepper motorA(forwarda, backwarda);

void forwardb() { afMotorB->onestep(FORWARD, stepType); }
void backwardb() { afMotorB->onestep(BACKWARD, stepType); }
AccelStepper motorB(forwardb, backwardb);

void configuration_motorSetup()
{
    AFMS.begin();
    afMotorA->setSpeed(10);  // 10 rpm  
    afMotorB->setSpeed(10);  // 10 rpm  
  // no initial setup for these kinds of motor drivers
}
//
// END ADDED BY BILL
// =================================================================
// =================================================================
// 1a. Arduino 328 sized board (eg UNO, Duemilanove)

//void configuration_setup()
//{
//  defaultMachineWidth = 650;
//  defaultMachineHeight = 650;
//  defaultMmPerRev = 95;
//  defaultStepsPerRev = 400;
//  defaultStepMultiplier = 1;
//  delay(500);
//}

// =================================================================
// 1b. Arduino 2560 sized board (eg Mega)

void configuration_setup()
{
  defaultMachineWidth = 650;
  defaultMachineHeight = 650;
  defaultMmPerRev = 95;
  defaultStepsPerRev = 400;
  defaultStepMultiplier = 1;
  sd_initSD();
  delay(500);
}
// end of Adafruit motorshield definition
// =================================================================


// =================================================================
// 2. Polarshield motor driver board
// This uses stepstick-format stepper drivers on arduino pins 3 to 8.

//const byte motoraEnablePin = 3;
//const byte motoraStepPin = 4;
//const byte motoraDirPin = 5;
//
//const byte motorbEnablePin = 6;
//const byte motorbStepPin = 7;
//const byte motorbDirPin = 8;
//
//AccelStepper motorA(1,motoraStepPin, motoraDirPin); 
//AccelStepper motorB(1,motorbStepPin, motorbDirPin); 
//
//void configuration_motorSetup()
//{
//  pinMode(motoraEnablePin, OUTPUT);
//  digitalWrite(motoraEnablePin, HIGH);
//  pinMode(motorbEnablePin, OUTPUT);
//  digitalWrite(motorbEnablePin, HIGH);
//  motorA.setEnablePin(motoraEnablePin);
//  motorA.setPinsInverted(false, false, true);
//  motorB.setEnablePin(motorbEnablePin);
//  motorB.setPinsInverted(true, false, true); // this one turns the opposite direction to A, hence inverted.
//}
//
//void configuration_setup()
//{
//  defaultMachineWidth = 650;
//  defaultMachineHeight = 650;
//  defaultMmPerRev = 95;
//  defaultStepsPerRev = 400;
//  defaultStepMultiplier = 8;
//
//  // init SD card
//  sd_initSD();
//  lcd_initLCD();
//  delay(1000);
//  attachInterrupt(INTERRUPT_TOUCH_PIN, lcd_touchInput, FALLING);
//  
//  // calibration pins
//  pinMode(ENDSTOP_X_MIN, INPUT);
//  pinMode(ENDSTOP_Y_MIN, INPUT);
//  pinMode(ENDSTOP_X_MAX, INPUT);
//  pinMode(ENDSTOP_Y_MAX, INPUT);
//  // do a write to turn on the internal pull up resistors
//  digitalWrite(ENDSTOP_X_MIN, HIGH);
//  digitalWrite(ENDSTOP_Y_MIN, HIGH);
//  digitalWrite(ENDSTOP_X_MAX, HIGH);
//  digitalWrite(ENDSTOP_Y_MAX, HIGH);
//  
//  lcd_displayFirstMenu();
//  
//  releaseMotors();
//}

// end of Polarshield definition
// =================================================================


