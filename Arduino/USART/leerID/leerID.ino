/*
  Mega multple serial test

 Receives from the main serial port, sends to the others.
 Receives from serial port 1, sends to the main serial (Serial 0).

 This example works only on the Arduino Mega

 The circuit:
 * Any serial device attached to Serial port 1
 * Serial monitor open on Serial port 0:

 created 30 Dec. 2008
 modified 20 May 2012
 by Tom Igoe & Jed Roach

 This example code is in the public domain.

 */
#define HEADER    0
#define COMMAND   1
#define DATA1     2
#define DATA2     3
#define CHECKSUM  4
#define RECEIVED1 5
#define RECEIVED2 6
 
byte BYTE[7];

byte leerID(void);

void setup() {
  // initialize both serial ports:
  Serial.begin(9600);
  Serial1.begin(19200,SERIAL_8N2);
  Serial.print((int) leerID());
}

void loop()
{
  
  // read from port 0, send to port 1:
  if (Serial.available())
  {
    int inByte = Serial.read();
    Serial1.write(inByte);
  }

  // read from port 0, send to port 1:
  if (Serial.available()) 
  {
    int inByte = Serial.read();
    Serial1.write(inByte);
  }
}

byte leerID(void)
{
  byte BYTE[7];
  int i;
  BYTE[HEADER]    =0x80;
  BYTE[COMMAND]   =0xE7;
  BYTE[DATA1]     =0X00;
  BYTE[DATA2]     =0x00;
  BYTE[CHECKSUM]  =0xFF-BYTE[HEADER]-BYTE[COMMAND]-BYTE[DATA1]-BYTE[DATA2];
  
  for(i=0; i<=4; i++)
  {
    Serial1.write(BYTE[i]):
  }
  if (Serial1.available()) 
  {
    BYTE[RECEIVED1] = Serial.read();
    Serial.print("Version= ");
    Serial.print((int) BYTE[RECEIVED1]);
  }
  if (Serial1.available()) 
  {
    BYTE[RECEIVED2] = Serial.read();
    Serial.print("ID= ");
    Serial.print((int) BYTE[RECEIVED2]);
  }
  return BYTE[RECEIVED2];
}
