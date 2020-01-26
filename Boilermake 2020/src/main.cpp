#include <Arduino.h>
#include <Sensor.hh>
#include <Server.hh>

void setup() 
{
  // put your setup code here, to run once:
  Serial.begin(9600);
  initWifi();
}

void loop() 
{
  // put your main code here, to run repeatedly:
  double ph = 0;
  double soil = 0;
  // soil

  Serial.print("PH: ");
  Serial.println(readPh());

  Serial.print("Soil: ");
  Serial.println(readSoil());

  Serial.print("Rain: ");
  Serial.println(readRaindrop());
/*
  for (int i = 0; i < 100; i++)
  {
    ph += readPh();
  
    soil += readSoil();

    delay(10);
  }
*/
  sendRequest(readPh(), readSoil(),readRaindrop());

  digitalWrite(21,HIGH);
  delay(200);
  digitalWrite(21,LOW);

  delay(1000);
}