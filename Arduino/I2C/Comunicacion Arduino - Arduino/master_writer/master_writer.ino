// Wire Master Writer
// by Nicholas Zambetti <http://www.zambetti.com>

// Demonstrates use of the Wire library
// Writes data to an I2C/TWI slave device
// Refer to the "Wire Slave Receiver" example for use with this

// Created 29 March 2006

// This example code is in the public domain.

byte REGISTRO_INICIAL=0x00;
byte ANGULO_SERVO3=10;
byte ANGULO_SERVO4=30;
byte ANGULO_SERVO5=50;
byte ANGULO_SERVO6=70;
byte ANGULO_SERVO7=90;
byte ANGULO_SERVO8=110;
byte ANGULO_SERVO9=130;
byte ANGULO_SERVOA=150;

#include <Wire.h>

void setup()
{
  Wire.begin(); // join i2c bus 
  Serial.begin(9600);
}

void loop()
{
  Wire.beginTransmission(4); // transmit to device #4
  Wire.write(REGISTRO_INICIAL);
  Wire.write(ANGULO_SERVO3++);
  Wire.write(ANGULO_SERVO4++);
  Wire.write(ANGULO_SERVO5++);
  Wire.write(ANGULO_SERVO6++);
  Wire.write(ANGULO_SERVO7--);
  Wire.write(ANGULO_SERVO8--);
  Wire.write(ANGULO_SERVO9--);
  Wire.write(ANGULO_SERVOA--);
  Wire.endTransmission();    // stop transmitting
  Serial.println("Enviado");
  delay(500);
}
