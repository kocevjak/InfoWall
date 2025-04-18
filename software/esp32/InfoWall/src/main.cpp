// eink datasheet: https://cz.mouser.com/datasheet/2/1089/1P233_00_02_E2417JS0D1_20211108-3132823.pdf
// ein library: GxEPD2 - https://github.com/ZinggJM/GxEPD2

#include <Arduino.h>
//#include <WiFi.h>
//#include <GxEPD2_3C.h>
//#include "SPI.h"
#include "eink.h"
#include "internet.h"
#include "api.h"



void setup() {
  Serial.begin(9600);
  display_init();
  connectToWiFi();
  update_holiday(get_holiday());
  draw_border();
}


void loop() {
  //draw_border();
}