#include <SoftwareSerial.h>
#include <Servo.h>
#include <HCSR04.h>

HCSR04 hc(5, 6);
Servo myservo;  // create servo object to control a servo
int pos = 0;
//Cytron_PS2Shield ps2; // HardwareSerial

#define LEDPIN 13
#define MotorDirection1 6
#define MotorSpeed1 7
#define MotorDirection2 8
#define MotorSpeed2 9
#define MotorDirection3 10
#define MotorSpeed3 11
#define MotorDirection4 12
#define MotorSpeed4 13
float target_height = 0;
float target_range = 0;
#include <SoftwareSerial.h>
float speed, angle, launch;
SoftwareSerial MyBlue(2, 3);  // RX 4 | TX 5
char flag = 0;
int SpeedVal = 0;
void setup() {
  Serial.begin(9600);
  MyBlue.begin(9600);
  //pinMode(LED, OUTPUT);
  //Serial.println("Ready to connect\nDefualt password is 1234 or 000");
  bool state_buzz = false;
  pinMode(MotorDirection1, OUTPUT);
  pinMode(MotorSpeed1, OUTPUT);

  pinMode(MotorDirection2, OUTPUT);
  pinMode(MotorSpeed2, OUTPUT);

  pinMode(MotorDirection3, OUTPUT);
  pinMode(MotorSpeed3, OUTPUT);
  pinMode(MotorDirection4, OUTPUT);
  pinMode(MotorSpeed4, OUTPUT);
}
void drive(int MD1, int MS1, int MD2, int MS2, int MD3, int MS3, int MD4, int MS4) {
  analogWrite(MotorSpeed1, MS1);
  digitalWrite(MotorDirection1, MD1);
  analogWrite(MotorSpeed2, MS2);
  digitalWrite(MotorDirection2, MD2);
  analogWrite(MotorSpeed3, MS3);
  digitalWrite(MotorDirection3, MD3);
  analogWrite(MotorSpeed4, MS4);
  digitalWrite(MotorDirection4, MD4);
}
void stop() {
  analogWrite(MotorSpeed1, 0);
  analogWrite(MotorSpeed2, 0);
  analogWrite(MotorSpeed3, 0);
  analogWrite(MotorSpeed4, 0);
}
void bp(char x) {
  MyBlue.println(flag);
  Serial.println(flag);
}
void loop() {
  if (MyBlue.available()) {
    flag = (MyBlue.read());
    Serial.println(flag);
    MyBlue.println(flag);
  }
  if (flag <= 99 && flag >= 0) speed = map(flag, 100, 200, 0, 255) ;else if (flag <= 199 && flag >= 100) launch = map(flag, 200, 300, 0, 255);
  else if (flag <= 299 && flag >= 200) angle = flag;
  else if (flag == 'front') drive(speed, 0, speed, 0, speed, 0, speed, 0); else if (flag == 'rear') drive(speed, 1, speed, 1, speed, 1, speed, 1);
   else if (flag == "right") drive(speed, 0, speed, 1, speed, 1, speed, 0);

  else if (flag == "left") drive(speed, 1, speed, 0, speed, 0, speed, 1);
  else if (flag == "lf") drive(0, 0, speed, 0, 0, 0, speed, 0);
  else if (flag == "rf") drive(speed, 0, 0, 0, speed, 0, speed, 0);
  else if (flag == "lr") drive(speed, 1, 0, 0, speed, 1, 0, 0);
  else if (flag == "rr") drive(0, 0, speed, 1, 0, 0, speed, 1);
  
  else if (flag == "rrot") drive(speed, 0, speed, 1, speed, 1, speed, 0);
  else if (flag == "lrot") drive(speed, 1, speed, 0, speed, 0, speed, 1);
  else if (flag == "a");//set target heights
   else if (flag == "b") ;
   else if (flag == "c") ;
  else if (flag == "d");
   else if (flag == "buzz") {
    if (hc.dist() < 250) Serial.println("target aligned");
    //buzz is pole is aligned, give a short beep, calculate distance, approximate speed and angle
  }
}
}
