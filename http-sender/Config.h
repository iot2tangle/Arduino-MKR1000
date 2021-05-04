#ifndef _CONFIG_H
#define _CONFIG_H

/* ----- CONFIG FILE ----- */

/* Device */
const char* id_name = "Arduino-MKR1000";

/* WiFi Network Configuration */
const char* ssid_WiFi = "mySSID";
const char* pass_WiFi = "myPASS";

/* HTTP Configuracion */
const char* address = "192.168.1.XXX";  /* Endpoint address (HTTP), must NOT include 'http://xxx' or 'tcp://xxx' */
int port = 8080;

/* Interval of time */
long interval = 20;    /* Time in seconds between collect data */

#endif
