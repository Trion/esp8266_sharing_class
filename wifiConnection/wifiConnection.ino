#include <ESP8266WiFi.h>

void setup() {
 Serial.begin(9600);

WiFi.begin("admin-client","nyeinchanko2@"); // to connect home wifi

Serial.println("Connecting to ");

while(WiFi.status() !=WL_CONNECTED)
{
  delay(500);
  Serial.print(".");
}

Serial.println("Connected IP : ");
Serial.println(WiFi.localIP());

}

void loop() {
 

}
