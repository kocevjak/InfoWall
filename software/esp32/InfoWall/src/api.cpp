#include "api.h"

String timetable_url = "https://api.golemio.cz/v2/gtfs/stoptimes/U1754Z2?date=2023-08-12&from=17%3A27%3A33&to=23%3A12%3A33&includeStop=false&limit=3&offset=0";   //vrací spoje které pojednou přes danou zastávku
String wheather_api_url = "https://api.openweathermap.org/data/2.5/forecast/daily?q=Prague&cnt=1&units=metric&lang=cz&appid=" + String(OpenWeatherApiKey); //vrací předpověd počasí na 7 dní

DynamicJsonDocument svatky(2048);
DynamicJsonDocument wheather(2048); //json pro weather api

void update_day(){
    HTTPClient http;
    String data;
    const char* holiday_url = "https://svatkyapi.cz/api/day";
    http.begin(holiday_url);
    if (http.GET() == 200)
    {
        data = http.getString();
        deserializeJson(svatky,data);
    }
}

String get_holiday(){
    return svatky["name"].as<String>();
}

String get_date(){
    /*
    todo change format of date to dd.mm.yyyy
    */
    return svatky["date"].as<String>();
}

void update_weather(){
    HTTPClient http;
    String data;
    http.begin(wheather_api_url);
    if (http.GET() == 200)
    {
        data = http.getString();
        //Serial.println(data);
        deserializeJson(wheather,data);
    }
}

int get_temperature_max(){
    return (int)(wheather["list"][0]["temp"]["max"].as<float>()+0.5);
}

int get_temperature_min(){
    return (int)(wheather["list"][0]["temp"]["min"].as<float>()+0.5);
}
