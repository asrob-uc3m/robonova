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
 
char flag=0;

byte leerID(void);

void setup() {
  // initialize both serial ports:
  Serial.begin(250000);
  Serial1.begin(19200,SERIAL_8N2);
}

void loop()
{
  delay(100);

  leerID();
  
  delay(1000);
  
//  Serial.println("FIN");
//  // read from port 0, send to port 1:
//  if (Serial.available())
//  {
//    int inByte = Serial.read();
//    Serial1.write(inByte);
//  }
//
//  // read from port 0, send to port 1:
//  if (Serial.available()) 
//  {
//    int inByte = Serial.read();
//    Serial1.write(inByte);
//  }
}


byte leerID(void)
{
  byte BYTESENT[7];
  byte BYTERECEIVED[7];
  int i;
  BYTESENT[HEADER]    =0x80;
  BYTESENT[COMMAND]   =0xE7;
  BYTESENT[DATA1]     =0X00;
  BYTESENT[DATA2]     =0x00;
  BYTESENT[CHECKSUM]  =0xFF-((BYTESENT[HEADER]+BYTESENT[COMMAND]+BYTESENT[DATA1]+BYTESENT[DATA2])%0xFF);
  BYTESENT[RECEIVED1] =0x00;
  BYTESENT[RECEIVED2] =0x00;

  for(i=0; i<=6; i++)
  {
    Serial1.write(BYTESENT[i]);
  }

  Serial1.flush(); 

  for(i=0; i<=6; i++)
  {
    BYTERECEIVED[i]=Serial1.read();
  }

//  while(flag==0);
//
//  Serial.println("Recibo cosas");
//
//  Serial1.write(0x00);
//  Serial1.flush() ;
//  while(!Serial1.available());
//  if (Serial1.available()) 
//  {
//    BYTE[RECEIVED1] = Serial1.read();

//  }

//  while(!Serial1.available());

//    Serial1.write(0x00);
//    Serial1.flush() ;
//  while(!Serial1.available());
//  if (Serial1.available()) 
//  {
//    BYTE[RECEIVED2] = Serial1.read();
    
    Serial.print("Version= ");
    Serial.println((int) BYTERECEIVED[RECEIVED1]);
    Serial.print("ID= ");
    Serial.println((int) BYTERECEIVED[RECEIVED2]);

//  }
  return BYTERECEIVED[RECEIVED2];
}
