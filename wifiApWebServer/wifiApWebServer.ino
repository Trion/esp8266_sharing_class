#include <ESP8266WiFi.h>

WiFiServer server(80);

void setup() {
  Serial.begin(115200);
  // prepare LED
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);
  // AP MODE (WiFi.softAP) // 
  bool check  = WiFi.softAP("Webserver", "12345678");
  if(check) {
    Serial.println("OK ");
  } else {
    Serial.println("ERROR");
  }
  // Start the server
 server.begin();
 Serial.println("Server Started");
  // Print the IP address
 Serial.println(WiFi.localIP());
}

void loop() {
  // -->>> 
  // Check if a client has connected
  WiFiClient client = server.available();
  
  if (!client) {
    return;
  }

  Serial.println(F("new client"));
  client.setTimeout(5000); // default is 1000

//  client.print("<h1>WEBSERVER</h1>");
 

//
//  // Read the first line of the request
  String req = client.readStringUntil('\r');
  Serial.println(F("request: "));
  Serial.println(req);

//  // Match the request
  int val;
//  if (req.indexOf(F("/gpio/0")) != -1) {
//    val = 0;
//  } else if (req.indexOf(F("/gpio/1")) != -1) {
//    val = 1;
//  } else {
//    Serial.println(F("invalid request"));
//    val = digitalRead(LED_BUILTIN);
//  }
//
//
//
//  // Set LED according to the request
//  digitalWrite(LED_BUILTIN, val);
//
//  // read/ignore the rest of the request
//  // do not client.flush(): it is for output only, see below
//  while (client.available()) {
//    client.read();
//  }
//
//  
//
//  
//
//  // Send the response to the client
//  // it is OK for multiple small client.print/write,
//  // because nagle algorithm will group them into one single packet


  client.print(F("HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n<!DOCTYPE HTML>\r\n<html>\r\nGPIO is now "));
  client.print((val) ? F("high") : F("low"));
  client.print(F("<br><br>Click <a href='http://"));
  client.print("192.168.4.1"); // http://192.168.4.1/gpio/1 --> <a>here</a>
  client.print(F("/gpio/1'>here</a> to switch LED GPIO on, or <a href='http://"));
  client.print("192.168.4.1"); // http://192.168.4.1/gpio/0 --> <a>here</a>
  client.print(F("/gpio/0'>here</a> to switch LED GPIO off.</html>"));

//  // The client will actually be *flushed* then disconnected
//  // when the function returns and 'client' object is destroyed (out-of-scope)
//  // flush = ensure written data are received by the other side
//  Serial.println(F("Disconnecting from client"));
}
