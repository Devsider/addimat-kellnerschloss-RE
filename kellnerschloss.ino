#include <OneWire.h>


// DS18S20 Temperature chip i/o

OneWire ds(5);
// on pin 10


void setup(void) {

  // initialize inputs/outputs

  // start serial port

  Serial.begin(9600);
}

String convertToNominalForm(byte arr[8]) {
  String hex_str = "";
  for (int i = 7; i >= 0; i--) {
    String byte_str = String(arr[i], HEX);
    if (byte_str.length() == 1) {
      byte_str = "0" + byte_str;
    }
    hex_str += byte_str;
  }
  hex_str.toUpperCase();
  return hex_str;
}

String currentKEY = "";

void loop(void) {

  byte i;

  byte present = 0;
  byte data[12];
  byte addr[8];


  ds.reset_search();
  if (!ds.search(addr)) {
    // Serial.print("No more addresses.\n");
    if (currentKEY != "OUT") {
      currentKEY = "OUT";
      Serial.println("OUT");
    }
    ds.reset_search();
    return;
  }


  // Serial.print("RRRRR=");
  // Serial.print(convertToNominalForm(addr));


  if (currentKEY != convertToNominalForm(addr)) {
    currentKEY = convertToNominalForm(addr);
    Serial.print(currentKEY);
    Serial.println("OUT");
  }

  ds.reset();

  // ds.select(addr);

  // ds.write(0x44, 1);


  // delay(1000);
}