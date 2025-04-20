#include <Arduino.h>
#include <ArduinoJson.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>
#include "password.h"

String get_holiday();
String get_date();
void update_day();
void update_weather();
int get_temperature_max();
int get_temperature_min();
void update_timetable();
String* get_timetable();
String parse_timetable_time(String timestamp);
