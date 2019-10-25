#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>


const char* ssid = "mehran.3";
const char* password = "hogabr98";
String order="off";
int ledPin=13;
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
if(order=="on"){
pinMode(ledPin,OUTPUT);
digitalWrite(ledPin,HIGH);
}
else if(order=="off")
{
  pinMode(ledPin,OUTPUT);
digitalWrite(ledPin,LOW);
}
    }
    http.end(); //Close connection
  }
  delay(4000);
}
