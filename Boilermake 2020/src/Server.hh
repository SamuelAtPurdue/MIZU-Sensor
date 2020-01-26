#include "Arduino.h"
#include "WiFi.h"
#include "HTTPClient.h"

#define SSID "BoilerMake24"
#define PASSWORD "boilermake2020"

#define SERVER "https://luzcode.com/MIZU/store-sensor-data.php"

void initWifi();
void sendRequest(double, double, double);
