
void setup() {
  // initialize both serial ports:
  Serial.begin(250000);
  Serial1.begin(19200);
}
byte inByte;
byte outByte;
void loop() {
  if(Serial1.available())
  {
    inByte=Serial1.read();
    while(Serial1.available()>0);Serial1.read();
    Serial.write(inByte);
  }
  Serial.write("Final de recepcion\n");
  Serial.write("Inicio de transmision\n");
  while(Serial.available()==0);
  if(Serial.available())
  {
    outByte=Serial.read();
    while(Serial.available()>0)Serial.read();
  }
  
  Serial2.begin(19200);
  
  Serial2.write(outByte);
  delay(50);
  Serial2.end();

  pinMode(16, OUTPUT);
  digitalWrite(16,LOW);
  Serial.write("Final de transmision\n");
  delay(1000);
  Serial.write("Inicio de recepcion\n");
  while(Serial1.available()==0);
}
