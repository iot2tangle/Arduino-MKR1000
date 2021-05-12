#ifndef ARDUINO_I2T_LIB_H_
#define ARDUINO_I2T_LIB_H_

#include <stdint.h>

void init_I2T(const char*);
void init_WiFi(const char*, const char*);
void init_HTTP(const char*, int);
void init_sensors(bool);
void read_sensors();
void print_counter(int);
char* generate_json();
void send_HTTP(const char*, const char*, const char*, int);

#endif
