/*
This example shows how to retrieve a button status on PS2 Controller.

Function:
  readButton(button); // Read button status, it will return corresponding data
                      // Digital button: 0 = pressed, 1 = released
                      // Analog button: return a value

  Digital button:
    PS2_SELECT
    PS2_JOYSTICK_LEFT
    PS2_JOYSTICK_RIGHT
    PS2_START
    PS2_UP
    PS2_RIGHT
    PS2_DOWN
    PS2_LEFT
    PS2_LEFT_2
    PS2_RIGHT_2
    PS2_LEFT_1
    PS2_RIGHT_1
    PS2_TRIANGLE
    PS2_CIRCLE
    PS2_CROSS
    PS2_SQUARE

  Analog button:
    PS2_JOYSTICK_LEFT_X_AXIS
    PS2_JOYSTICK_LEFT_Y_AXIS
    PS2_JOYSTICK_RIGHT_X_AXIS
    PS2_JOYSTICK_RIGHT_Y_AXIS
    PS2_JOYSTICK_LEFT_UP
    PS2_JOYSTICK_LEFT_DOWN
    PS2_JOYSTICK_LEFT_LEFT
    PS2_JOYSTICK_LEFT_RIGHT
    PS2_JOYSTICK_RIGHT_UP
    PS2_JOYSTICK_RIGHT_DOWN
    PS2_JOYSTICK_RIGHT_LEFT
    PS2_JOYSTICK_RIGHT_RIGHT

Product page:
  Cytron PS2 Shield: http://www.cytron.com.my/p-shield-ps2
  PS2 Controller: http://www.cytron.com.my/p-ps-gp-1
  CT-UNO: http://www.cytron.com.my/p-ct-uno

Original written by:
            Cytron Technologies

Modified:
  29/06/15  Idris, Cytron Technologies
*/

#include <SoftwareSerial.h>
#include <Cytron_PS2Shield.h>
#include <Servo.h>
Servo myservo; // create servo object to control a servo
int pos = 0; 
Cytron_PS2Shield ps2(2, 3); // SoftwareSerial: Rx and Tx pin
//Cytron_PS2Shield ps2; // HardwareSerial

#define LEDPIN  13
#define MotorDirection1 8
#define MotorSpeed1 9
#define MotorDirection2 6
#define MotorSpeed2 7
#include <SoftwareSerial.h> 
SoftwareSerial MyBlue(4, 5); // RX 4 | TX 5 
int flag = 0; 
int SpeedVal = 0;
void setup()
{
  Serial.begin(9600);
 MyBlue.begin(9600); 
 //pinMode(LED, OUTPUT); 
 Serial.println("Ready to connect\nDefualt password is 1234 or 000"); 

  pinMode(MotorDirection1, OUTPUT);
  pinMode(MotorSpeed1, OUTPUT);
  
  pinMode(MotorDirection2, OUTPUT);
  pinMode(MotorSpeed2, OUTPUT);
}

void loop()
{
  delay(500);
   if (MyBlue.available()) 
   flag = MyBlue.read(); 
   Serial.print(flag);
  if(PS2_RIGHT) // 0 = pressed, 1 = released
  {
    digitalWrite(MotorDirection2, LOW);
    analogWrite(MotorSpeed2,255);
       
    digitalWrite(MotorDirection1, HIGH);                  //Loop increases the speed slowly until it reaches max speed.
    analogWrite(MotorSpeed1,255);
    Serial.println(" right lmao"); 
    MyBlue.println(" right lmao"); 
   
  }
  MyBlue.println("  lmao");
  
  if(ps2.readButton(PS2_LEFT) == 0) // 0 = pressed, 1 = released
  {
    digitalWrite(MotorDirection2, HIGH);
    analogWrite(MotorSpeed2,255);
       
    digitalWrite(MotorDirection1, LOW);                  //Loop increases the speed slowly until it reaches max speed.
    analogWrite(MotorSpeed1,255);
    Serial.println(" left lmao"); 
  }
  
  if(ps2.readButton(PS2_LEFT_1) == 0) // 0 = pressed, 1 = released
  {
    myservo.write(pos+=3);
  }
  if(ps2.readButton(PS2_RIGHT_1) == 0) // 0 = pressed, 1 = released
  {
    myservo.write(pos-=3); 
  }
  
  if(ps2.readButton(PS2_DOWN) == 0) // 0 = pressed, 1 = released
  {
    digitalWrite(MotorDirection2, LOW);
    analogWrite(MotorSpeed2,255);
       
    digitalWrite(MotorDirection1, LOW);                  //Loop increases the speed slowly until it reaches max speed.
    analogWrite(MotorSpeed1,255);
   
    Serial.println(" down lmao"); 
  }
   if(ps2.readButton(PS2_SELECT) == 0) // 0 = pressed, 1 = released
  {
    digitalWrite(LEDPIN, HIGH);
    Serial.println(" select lmao"); 
  }
   if(ps2.readButton(PS2_CROSS) == 0) // 0 = pressed, 1 = released
  {
    digitalWrite(MotorDirection2, LOW);
    analogWrite(MotorSpeed2,0);
       
    digitalWrite(MotorDirection1, LOW);                  //Loop increases the speed slowly until it reaches max speed.
    analogWrite(MotorSpeed1,0);
    Serial.println(" CROSS lmao"); 
  }
   if(ps2.readButton(PS2_CIRCLE) == 0) // 0 = pressed, 1 = released
  {
    digitalWrite(LEDPIN, HIGH);
    Serial.println(" circle lmao"); 
  }
   if(ps2.readButton(PS2_TRIANGLE) == 0) // 0 = pressed, 1 = released
  {
    digitalWrite(LEDPIN, HIGH);
    Serial.println(" triangle lmao"); 
  }
   if(ps2.readButton(PS2_LEFT_2) == 0) // 0 = pressed, 1 = released
  {
    digitalWrite(LEDPIN, HIGH);
    Serial.println(" PS2_LEFT_2 lmao"); 
  }
   if(ps2.readButton(PS2_LEFT_1) == 0) // 0 = pressed, 1 = released
  {
    digitalWrite(LEDPIN, HIGH);
    Serial.println(" PS2_LEFT_1 lmao"); 
  }
   if(ps2.readButton(PS2_RIGHT_2) == 0) // 0 = pressed, 1 = released
  {
    digitalWrite(LEDPIN, HIGH);
    Serial.println(" PS2_RIGHT_2 lmao"); 
  }
   if(ps2.readButton(PS2_RIGHT_1) == 0) // 0 = pressed, 1 = released
  {
    digitalWrite(LEDPIN, HIGH);
    Serial.println(" right 1 lmao"); 
  }
  if(ps2.readButton(PS2_SQUARE) == 0) // 0 = pressed, 1 = released
  {
    digitalWrite(LEDPIN, HIGH);
    Serial.println(" square lmao"); 
  }
  

  if(ps2.readButton(PS2_UP) == 0) // 0 = pressed, 1 = released
  {
    digitalWrite(MotorDirection2, HIGH);
    analogWrite(MotorSpeed2,255);
       
    digitalWrite(MotorDirection1, HIGH);                  //Loop increases the speed slowly until it reaches max speed.
    analogWrite(MotorSpeed1,255);
  }
  if(ps2.readButton(PS2_UP) == 1&&ps2.readButton(PS2_RIGHT) == 1&&ps2.readButton(PS2_DOWN) == 1&&ps2.readButton(PS2_LEFT) == 1) // 0 = pressed, 1 = released
  {
    analogWrite(MotorSpeed2,0);
    analogWrite(MotorSpeed1,0);
  }
 Serial.println(" hi lmao");
  if(ps2.readButton(PS2_START) == 0) // 0 = pressed, 1 = released
  {
    digitalWrite(LEDPIN, HIGH);
    Serial.println(" start lmao"); 
  }

  
}