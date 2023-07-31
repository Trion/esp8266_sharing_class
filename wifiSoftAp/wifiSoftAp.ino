#include <ESP8266WiFi.h>

void setup() {
 Serial.begin(9600);
 

boolean result = WiFi.softAP("ESP8266");

if(result) {
  Serial.println("OK");
}
else {
  Serial.println("Failed");
}

}

void loop() {
  // put your main code here, to run repeatedly:

}
