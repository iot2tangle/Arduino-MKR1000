#ifndef _CONFIG_H
#define _CONFIG_H

/* ----- CONFIG FILE ----- */

/* Device */
const char* id_name = "Arduino-MKR1000";

/* WiFi Network Configuration */
const char* ssid_WiFi = "mySSID";
const char* pass_WiFi = "myPASS";

/* HTTP Configuracion */
const char* address = "192.168.1.XXX";  /* Address (HTTP), must NOT include 'http://xxx' or 'tcp://xxx' */
const char* endpoint = "/sensor_data";  /* Endpoint (HTTP) */
int port = 8080;

/* Interval of time */
long interval = 15;    /* Time in seconds between collect data */

#endif
