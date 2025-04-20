#include <Arduino.h>
#include <GxEPD2_3C.h>
#include "SPI.h"
#include <WiFi.h>
#include <Fonts/FreeMonoBold9pt7b.h>

#define DC    17     
#define RST   16  
#define BUSY  4 
#define POWER 2

#define line_h 11   //výška pisma


//GxEPD2_3C<GxEPD2_420c_Z21, GxEPD2_420c_Z21::HEIGHT> display(GxEPD2_420c_Z21(SS, DC, RST, BUSY)); // GDEQ042Z21 400x300, UC8276GxEPD2_3C<GxEPD2_420c_GDEY042Z98, GxEPD2_420c_GDEY042Z98::HEIGHT> display(GxEPD2_420c_GDEY042Z98(SS, DC, RST, BUSY)); // GDEY042Z98 400x300, SSD1683 (no inking)

void display_init();
void draw_border();
void display_update_holiday(String name);
void display_update_date(String date);
void display_update_weaather(int min, int max);
void display_update_timetable(String* timetable);
