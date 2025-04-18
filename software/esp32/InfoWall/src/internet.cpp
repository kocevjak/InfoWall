#include "internet.h"

void connectToWiFi(){
    const char* ssid = "moto g31";
    const char* password = "11111111";

    WiFi.mode(WIFI_STA);
    WiFi.begin(ssid,password);
    Serial.print("\nConnecting");
    while (WiFi.status() != WL_CONNECTED)
    {
        Serial.print(".");
        delay(100);
    }
    Serial.print("Connected");
}
