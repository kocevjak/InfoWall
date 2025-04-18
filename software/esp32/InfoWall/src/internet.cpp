#include "internet.h"

void connectToWiFi(){
    WiFi.mode(WIFI_STA);
    WiFi.begin(SSID,PASSWORD);
    Serial.print("\nConnecting");
    while (WiFi.status() != WL_CONNECTED)
    {
        Serial.print(".");
        delay(100);
    }
    Serial.print("Connected");
}
