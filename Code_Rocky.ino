#define CUSTOM_SETTINGS
#define INCLUDE_GAMEPAD_MODULE

#include <Dabble.h>
#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include <Servo.h>

Adafruit_MotorShield AFMS = Adafruit_MotorShield();
Adafruit_DCMotor *motor1 = AFMS.getMotor(3);
Adafruit_DCMotor *motor2 = AFMS.getMotor(4);

Servo pince;
Servo bras;

void setup() {
  AFMS.begin();
  Dabble.begin(9600);
  pince.attach(9);
  bras.attach(10);
  bras.write(164);
  pince.write(50);
  motor1->setSpeed(130);
  motor2->setSpeed(130);
}

void loop() {
  Dabble.processInput();            
  if (GamePad.isUpPressed()){
    motor1->run(FORWARD);
    motor2->run(FORWARD);
  } else if (GamePad.isDownPressed()){
      motor1->run(BACKWARD);
      motor2->run(BACKWARD);
  } else if (GamePad.isRightPressed()){
      motor1->run(FORWARD);
      motor2->run(BACKWARD);
  } else if (GamePad.isLeftPressed()){
      motor1->run(BACKWARD);
      motor2->run(FORWARD);
  } else if (GamePad.isTrianglePressed()){
      for (int pos_bras = 164; pos_bras >= 120; pos_bras = pos_bras - 5){
        bras.write(pos_bras);
        delay(15);
      }
      delay(1000);
  } else if (GamePad.isCirclePressed()){
      pince.write(50);
      delay(1000);
  } else if (GamePad.isCrossPressed()){
      for (int pos_bras = 120; pos_bras <= 164; pos_bras = pos_bras + 1){
        bras.write(pos_bras);
        delay(15);
      }
      delay(1000);
  } else if (GamePad.isSquarePressed()){
      pince.write(0);
      delay(1000);
  } else {
      motor1->run(RELEASE);
      motor2->run(RELEASE);
  } 
}




