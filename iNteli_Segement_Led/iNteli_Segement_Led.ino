#include <LedControl.h>

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
  for (unsigned int i = 0; i <=2; i++) {
    offsetvalue = offsetvalue + 1;
    Serial.print("OFFsetValue = ");
    Serial.print("\t");
    Serial.print(offsetvalue);
    Serial.print("\t");
    Serial.print("V % 10 = ");
    Serial.print("\t");
    Serial.println(v % 10);
    //    if (offsetvalue > 5) {
    //      Serial.print("V % 10 = ");
    //      Serial.print("\t");
    //      Serial.println(v % 10);
    //      Serial.print("offset Value = ");
    //      Serial.print(offsetvalue -1);
    //      lc.setDigit(row, offsetvalue - 1, v % 10, i == decimalPlaces);
    //    } else

    lc.setDigit(row, offsetvalue - 1 , v % 10, false);
    if (offsetvalue >7) offsetvalue = 4;

    v /= 10;
    Serial.println(v/10);
  
  }
}

int temp = -23;
void setup() {
  Serial.begin(9600);
  // Initialize the MAX7219 device
  lc.shutdown(0, false);       // Wake up the display
  lc.setIntensity(0, 8);       // Set brightness level (0 is min, 15 is max)
  lc.clearDisplay(0);          // Clear the display
  Serial.println(sizeof(temp));
}

char data[4];
float value;
void loop() {
temp = temp - 1;
Serial.println(temp);
  Serial.println(sizeof(temp));
  displayFloat(temp, 0, 1);
  delay(1000);
  displayFloat(-34,0,1);
  



  ////
  ////  // Display "HELLO" on the segment LED display
  ////  lc.setChar(0, 0, 'H', true); // Display 'H' at position 0
  ////  lc.setChar(0, 1, 'E', true); // Display 'E' at position 1
  ////  lc.setChar(0, 2, 'L', true); // Display 'L' at position 2
  ////  lc.setChar(0, 3, 'L', true); // Display 'L' at position 3
  ////  lc.setChar(0, 4, 'O', true); // Display 'O' at position 4
  //  lc.setChar(0, 5, 'L', true); // Display 'H' at position 0
  //  lc.setChar(0, 6, 'E', true); // Display 'E' at position 1
  //  lc.setChar(0, 7, 'H', true); // Display 'L' at position 2
  ////  lc.setChar(0, 8, 'H', true); // Display 'L' at position 3
  ////  lc.setChar(0, 9, 'O', true); // Display 'O' at position 4
  ////  delay(1000);
  //
  //  // Test the display
  //  for (int i = 0; i < 8; i++) {
  //    lc.setDigit(0, i, i, false); // Display numbers 0 to 7 sequentially
  //    delay(500);
  //  }
  //   lc.clearDisplay(0);
  //    for (int i = 8; i > 0; i--) {
  //    lc.setDigit(0, i-8, i, false); // Display numbers 0 to 7 sequentially
  //    delay(500);
  //  }

}
