#include "api.h"

String timetable_url = "https://api.golemio.cz/v2/gtfs/stoptimes/U1754Z2?date=2023-08-12&from=17%3A27%3A33&to=23%3A12%3A33&includeStop=false&limit=3&offset=0";   //vrací spoje které pojednou přes danou zastávku
const char* timetableKey = "eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJlbWFpbCI6Impha3Via29jZXZAZ21haWwuY29tIiwiaWQiOjIwNTEsIm5hbWUiOm51bGwsInN1cm5hbWUiOm51bGwsImlhdCI6MTY5MDQ5MjE3MCwiZXhwIjoxMTY5MDQ5MjE3MCwiaXNzIjoiZ29sZW1pbyIsImp0aSI6IjQ3YzUyMDIyLWM5MjEtNDRlOC04MzliLTI4YWI1NzdmMDg4MSJ9.BjIE0KtL8MyvA6yvJkhArLx5O8IQSQllpT9E41zev4I";

String get_holiday(){
    /*
    funkce vrací jméno kdo má svátek
    data se tahají ze stránky https://svatkyapi.cz/
    */
    HTTPClient http;
    DynamicJsonDocument in(2048);
    String data;
    const char* holiday_url = "https://svatkyapi.cz/api/day";
    http.begin(holiday_url);
    if (http.GET() == 200)
    {
        data = http.getString();
        deserializeJson(in,data);
    }
    
    return in["name"].as<String>();
}
