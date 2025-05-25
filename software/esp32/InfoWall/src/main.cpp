// eink datasheet: https://cz.mouser.com/datasheet/2/1089/1P233_00_02_E2417JS0D1_20211108-3132823.pdf
// ein library: GxEPD2 - https://github.com/ZinggJM/GxEPD2
// podpora češtiny https://github.com/petrbrouzda/fontconvert8-iso8859-2

#include <Arduino.h>
//#include <WiFi.h>
//#include <GxEPD2_3C.h>
//#include "SPI.h"
#include "eink.h"
#include "internet.h"
#include "api.h"

hw_timer_t *timer = NULL; // Create a timer
bool timer_update_display = false;


void update_display(){
  display_clear();
  update_day();
  display_update_holiday(get_holiday());
  display_update_date(get_date());
  update_weather();
  display_update_weaather(get_temperature_min(),get_temperature_max());
  update_timetable();
  display_update_timetable(get_timetable());
  draw_border();
}

void IRAM_ATTR onTimer(){
  timer_update_display = true; // Set the flag to update the display
  //timerAlarmDisable(timer); // Disable the timer to prevent re-entrance
}

void set_Timer(int minutes){
  timerAlarmWrite(timer, minutes * 60 * 1000000ULL, false); // Set alarm to trigger every X seconds
  timerAlarmEnable(timer); // Enable the alarm
  Serial.print("timer set to: ");
  Serial.println(minutes); // Print the timer value in seconds
}

void setup() {
  Serial.begin(9600);
  display_init();
  connectToWiFi();
  update_display();
  Serial.println("Display updated");
  timer = timerBegin(0, 80, true); // Timer 0, prescaler 80 (1us)
  timerAttachInterrupt(timer, &onTimer, true); // Attach the interrupt function
  set_Timer(get_next_update()); // Set the timer to trigger every 1 minute
}

void loop() {
  if (timer_update_display)
  {
    Serial.println("Updating display...");
    timer_update_display = false;
    set_Timer(get_next_update()); // Reset the timer for the next update
    update_display();
    Serial.println(get_next_update());
  }
}