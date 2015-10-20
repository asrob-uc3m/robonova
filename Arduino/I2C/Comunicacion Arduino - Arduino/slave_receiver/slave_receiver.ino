// Wire Slave Receiver
// by Nicholas Zambetti <http://www.zambetti.com>

// Demonstrates use of the Wire library
// Receives data as an I2C/TWI slave device
// Refer to the "Wire Master Writer" example for use with this

// Created 29 March 2006

// This example code is in the public domain.


#include <Wire.h>
#include <Servo.h>

Servo Servo3;
Servo Servo4;
Servo Servo5;
Servo Servo6;
Servo Servo7;
Servo Servo8;
Servo Servo9;
Servo ServoA;


byte *registro[8];

void setup()
{
  Servo3.attach(3);
  Servo4.attach(4);
  Servo5.attach(5);
  Servo6.attach(6);
  Servo7.attach(7);
  Servo8.attach(8);
  Servo9.attach(9);
  ServoA.attach(10);
  Wire.begin(4);                // join i2c bus with address #4
  Wire.onReceive(receiveEvent); // register event
  Serial.begin(9600);           // start serial for output
}

void loop()
{
  Servo3.write(*registro[0]);
  Servo4.write(*registro[1]);
  Servo5.write(*registro[2]);
  Servo6.write(*registro[3]);
  Servo7.write(*registro[4]);
  Servo8.write(*registro[5]);
  Servo9.write(*registro[6]);
  ServoA.write(*registro[7]);
  delay(100);
}

// function that executes whenever data is received from master
// this function is registered as an event, see setup()
void receiveEvent(int howMany)
{
  int N_Info = Wire.available();
  byte Reg_Acceso = Wire.read(); // receive byte as a character
  int i=0;
  
  Serial.print("Recibido: ");
  while (Wire.available()) // loop through all but the last
  {
    if((Reg_Acceso+i)<7)
    {
      *registro[Reg_Acceso+i] = Wire.read();
      Serial.print(*registro[Reg_Acceso+i]);
      i++;
    }
  }

  Serial.println("");         // print the integer
}
