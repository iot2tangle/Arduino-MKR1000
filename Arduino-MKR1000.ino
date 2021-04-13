#include <Arduino-I2T-lib.h>
#include "Config.h"

char* j;

void setup() {

  Serial.begin(115200);

  print_init_msg();
  init_WiFi(ssid_WiFi, pass_WiFi);
  init_HTTP(address, port);
  init_sensors();

}

void loop() {

  j = generate_json();

  send_HTTP(j);

  delay(interval * 1000);

}
