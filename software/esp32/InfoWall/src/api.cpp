#include "api.h"

String timetable_api_url = "https://api.golemio.cz/v2/gtfs/stoptimes/U1754Z2?date=2025-04-20&from=13%3A41%3A00&includeStop=false&limit=3&offset=0";   //vrací spoje které pojednou přes danou zastávku
String wheather_api_url = "https://api.openweathermap.org/data/2.5/forecast/daily?q=Prague&cnt=1&units=metric&lang=cz&appid=" + String(OpenWeatherApiKey); //vrací předpověd počasí na 7 dní

DynamicJsonDocument svatky(2048);
DynamicJsonDocument wheather(2048); //json pro weather api
DynamicJsonDocument timetable(2048); //json pro timetable api

String api_data;

HTTPClient http;

void update_day(){
    const char* holiday_url = "https://svatkyapi.cz/api/day";
    http.begin(holiday_url);
    if (http.GET() == 200)
    {
        api_data = http.getString();
        deserializeJson(svatky,api_data);
    }
    http.end();
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
    http.begin(wheather_api_url);
    if (http.GET() == 200)
    {
        api_data = http.getString();
        //Serial.println(data);
        deserializeJson(wheather,api_data);
    }
    http.end();
}

int get_temperature_max(){
    return (int)(wheather["list"][0]["temp"]["max"].as<float>()+0.5);
}

int get_temperature_min(){
    return (int)(wheather["list"][0]["temp"]["min"].as<float>()+0.5);
}

void update_timetable(){
    http.begin(timetable_api_url);
    http.addHeader("X-Access-Token",GolemioApiKey);
    if (http.GET() == 200)
    {
        api_data = http.getString();
        //Serial.println(api_data);
        deserializeJson(timetable,api_data);
    }
    http.end();
}

String get_timetable(){
    return timetable[1]["departure_time"].as<String>();
}
