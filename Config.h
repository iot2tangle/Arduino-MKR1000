#ifndef _CONFIG_H
#define _CONFIG_H

/* ----- ARCHIVO CONFIGURACION ----- */

/* Device */
const char* id_name = "ESP-ROBOT-CINTRA";

/* WiFi Network Configuracion */
const char* ssid_WiFi = "FTTH-BELBRUNO.M";
const char* pass_WiFi = "redbba12";

/* HTTP Configuracion */
const char* address = "192.168.1.115";  /* Endpoint address (HTTP), must NOT include 'http://xxx' or 'tcp://xxx' */
int port = 8080;

/* Intervalo de tiempo entre toma-envio de datos */
long interval = 20;    /* Tiempo en segundos */

#endif
