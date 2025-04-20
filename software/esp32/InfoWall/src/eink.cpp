#include "eink.h"
GxEPD2_3C<GxEPD2_420c_Z21, GxEPD2_420c_Z21::HEIGHT> display(GxEPD2_420c_Z21(SS, DC, RST, BUSY)); //400x300

void display_init(){
    pinMode(POWER,OUTPUT);
    digitalWrite(POWER,HIGH);
    display.init();
    delay(100);
    display.clearScreen();
    display.fillScreen(GxEPD_WHITE);
    display.setFont(&FreeMonoBold9pt7b);
    display.setTextColor(GxEPD_BLACK);
}

void draw_border(){
    display.drawRect(0,0,400,300,GxEPD_BLACK);
    display.drawLine(0,10+line_h,400,10+line_h,GxEPD_BLACK);
    display.drawLine(120,0,120,300,GxEPD_BLACK);
    //update_date();
    //update_holiday();
    //display_update_weaather();
    //display_update_timetable();
    display.display();
}

void display_update_holiday(String name){
    display.setCursor(125,5+line_h);
    display.print("Svatek ma: ");
    display.print(name);
}

void display_update_date(String date){
    display.setCursor(5,5+line_h);
    display.print(date);
}

void display_update_weaather(int min, int max){
    display.drawCircle(60,80,50,GxEPD_RED);
    display.setCursor(5,135+line_h);
    display.print("min: " + String(min) + " C");
    display.setCursor(5,135+2*line_h+5);
    display.print("max: " + String(max) + " C");
}

void display_update_timetable(String timetable){
    display.setCursor(125,10+line_h+5+line_h);
    display.print(timetable);
}
