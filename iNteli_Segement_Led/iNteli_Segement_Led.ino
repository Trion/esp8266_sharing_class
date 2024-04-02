#include <LedControl.h>

// Include the libraries we need
#include <OneWire.h>
#include <DallasTemperature.h>

// Data wire is plugged into port 2 on the Arduino
#define ONE_WIRE_BUS D4
#define BUZZER_PIN D3

// Setup a oneWire instance to communicate with any OneWire devices (not just Maxim/Dallas temperature ICs)
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);
// Pass our oneWire reference to Dallas TemperatureDallasTem

// Define the number of MAX7219 devices in your setup
#define MAX_DEVICES 1

// Define the pins connected to the MAX7219
#define CLK_PIN   D5
#define DATA_PIN  D7
#define CS_PIN    D8


int offsetvalue = 4;
// Create a LedControl object
LedControl lc = LedControl(DATA_PIN, CLK_PIN, CS_PIN, MAX_DEVICES);
const unsigned int NUMBER_OF_DIGITS = 4;

void displayFloat(int value, unsigned int row = 0, unsigned int decimalPlaces = 1, unsigned int digitOffset = 0) {
  unsigned int total_length = NUMBER_OF_DIGITS;
  if (NUMBER_OF_DIGITS < decimalPlaces) {
    return;
  };

  if (value < 0) {
    lc.setChar(row, offsetvalue + 3, '-', false);
    total_length--;
  };
  Serial.print("toatal legth");
  Serial.print("\t");
  Serial.print(total_length);
  //  for (unsigned int i = 0; i < decimalPlaces; i ++) {
  //    value *= 10.0f;
  //  }
  Serial.print("\t");
  Serial.print("Value");
  Serial.print("\t");
  Serial.print(value);
  unsigned int v = (unsigned int) (value < 0 ? -value : value);


  Serial.print("\t");
  Serial.print("v = ");
  Serial.print("\t");
  Serial.println(v);
  if (value < 0) {
    for (unsigned int i = 0; i <= 2; i++) {
      offsetvalue = offsetvalue + 1;
      Serial.print("OFFsetValue = ");
      Serial.print("\t");
      Serial.print(offsetvalue);
      Serial.print("\t");
      Serial.print("V % 10 = ");
      Serial.print("\t");
      Serial.println(v % 10);
      lc.setDigit(row, offsetvalue , v % 10, false);
      if (v % 10 == 0) {
        lc.setChar(row, offsetvalue, '-', false);
      }
      if (offsetvalue == 7) offsetvalue = 4;

      v /= 10;
      Serial.println(v / 10);

    }

  } else {
    for (unsigned int i = 0; i <= 2; i++) {
      offsetvalue = offsetvalue + 1;
      Serial.print("OFFsetValue = ");
      Serial.print("\t");
      Serial.print(offsetvalue);
      Serial.print("\t");
      Serial.print("V % 10 = ");
      Serial.print("\t");
      Serial.println(v % 10);

      if (offsetvalue == 7) offsetvalue = 4;
      lc.setDigit(row, offsetvalue, v % 10, false);
      //  if (offsetvalue == 7) offsetvalue = 4;
      v /= 10;
      Serial.println(v / 10);

    }
  }
}

int temp = -30.5;
void setup() {
  Serial.begin(9600);
  // Initialize the MAX7219 device
  lc.shutdown(0, false);       // Wake up the display
  lc.setIntensity(0, 8);       // Set brightness level (0 is min, 15 is max)
  lc.clearDisplay(0);          // Clear the display
  Serial.println(sizeof(temp));
  pinMode(BUZZER_PIN,OUTPUT);

  // Start up the library
  sensors.begin();
}

char data[4];
float value;
void loop() {

  Serial.print("Requesting temperatures...");
  sensors.requestTemperatures(); // Send the command to get temperatures
  Serial.println("DONE");
  int tempC = sensors.getTempCByIndex(0);

  if (tempC != DEVICE_DISCONNECTED_C)
  {
    Serial.print("Temperature for the device 1 (index 0) is: ");
    Serial.println(tempC);
  }
  else
  {
    Serial.println("Error: Could not read temperature data");
  }

  Serial.println(tempC);
  Serial.println(sizeof(tempC));
  displayFloat(tempC, 0, 1);






}
