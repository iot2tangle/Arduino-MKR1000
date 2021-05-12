#include <Arduino-I2T-lib.h>
#include "Config.h"

char* j;
int count = 0;

void setup() {

  Serial.begin(115200);

  delay(3000);
  Serial.println("\t\t\t----  Arduino MKR1000  --  IOT2TANGLE  --  HTTP  ----");
  init_I2T(id_name);
  init_WiFi(ssid_WiFi, pass_WiFi);
  init_HTTP(address, port);
  init_sensors(true);
}

void loop() {

  print_counter(++count);

  init_sensors(false);  // Reinit Sensors

  read_sensors();

  j = generate_json();

  send_HTTP(j, address, endpoint, port);

  delay(interval * 1000);

}
