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
    update_date();
    //update_holiday();
    update_weaather();
    update_timetable();
    display.display();
}

void update_holiday(String name){
    display.setCursor(125,5+line_h);
    display.print("Svatek ma: ");
    display.print(name);
}

void update_date(){
    display.setCursor(5,5+line_h);
    display.print("28.1.2025");
}

void update_weaather(){
    display.drawCircle(60,80,50,GxEPD_RED);
    display.setCursor(5,135+line_h);
    display.print("min: 10°C");
    display.setCursor(5,135+2*line_h+5);
    display.print("max: 20°C");
}

void update_timetable(){
    display.setCursor(125,10+line_h+5+line_h);
    display.print("timetable");
}
