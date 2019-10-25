#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>


const char* ssid = "your wifi ssid";
const char* password = "your wifi password";
String order="off";

void setup() 
{
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) 
  {
    delay(1000);
    Serial.println("Connecting...");
  }
}

void loop() 
{
  if (WiFi.status() == WL_CONNECTED) 
  {
    HTTPClient http; //Object of class HTTPClient
    http.begin("http://aftermirror.ir/returnProceccedRequest");
   
    int httpCode = http.GET();
    if (httpCode > 0) 
    {
    order = http.getString();
Serial.println(order);


    }
    http.end(); //Close connection
  }
  delay(4000);
}
