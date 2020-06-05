#include<SoftwareSerial.h>
int LED = D4;
char BT = 0;
SoftwareSerial BLUE(D5, D7);

void setup(){
  Serial.begin(9600);
  BLUE.begin(9600);
  pinMode(LED, OUTPUT);
}
void loop(){
  if(BLUE.available()){
    BT = BLUE.read();
    Serial.write(BT);
    switch(BT)
    {
      case '1' : digitalWrite(LED, HIGH); break;
      case '0' : digitalWrite(LED, LOW); break;
    }
}
if(Serial.available())
BLUE.write(Serial.read());
delay(1);
}
