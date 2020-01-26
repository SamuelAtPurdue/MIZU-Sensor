#include <Server.hh>

void initWifi()
{
  WiFi.begin("BoilerMake24", "boilermake2020");

  while (WiFi.status() != WL_CONNECTED)
  {
    delay(1000);
    Serial.println("Connecting...");
    digitalWrite(22,HIGH);
    delay(200);
    digitalWrite(22,LOW);
  }
  Serial.println("Connected");
}

void sendRequest(double ph, double soil, double rain)
{
  if(WiFi.status() == WL_CONNECTED)
  {
    HTTPClient http;

    http.begin(SERVER);
    http.addHeader("Content-Type", "application/x-www-form-urlencoded");

    char req[100];
    char tmp[9];
    strcpy(req, "{\"pH\":");
    dtostrf(ph * 10, 1,0,tmp);
    strcat(req, tmp);
    strcat(req, ",\"SoilMoisture\":");
    dtostrf(soil * 10, 1, 0, tmp);
    strcat(req, tmp);
    strcat(req, ",\"Raindrop\":");
    dtostrf(rain, 1, 0, tmp);
    strcat(req, tmp);
    strcat(req,"}");

    Serial.println(req);

    int res = http.POST(req);
    //int res = http.POST("{\"pH\":65,\"SoilMoisture\":80,\"Raindrop\":87}");
    
    if (res < 0)
      digitalWrite(22, HIGH);
  }
}