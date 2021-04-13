#ifndef _CONFIG_H
#define _CONFIG_H

/* ----- ARCHIVO CONFIGURACION ----- */

/* Device */
const char* id_name = "ESP-ROBOT-CINTRA";

/* WiFi Network Configuracion */
const char* ssid_WiFi = "FTTH-BELBRUNO.M";
const char* pass_WiFi = "redbba12";

//bool isEnable_IPfija = true;		/*   Setear en True en caso de necesitar IP Fija   */
//IPAddress ip_WiFi(192,168,1,160); 		
//IPAddress gateway_WiFi(192,168,1,1); 	/*   En caso de NO utilizar IP Fija ignore los valores ya que no seran tenidos en cuenta  */
//IPAddress subnet_WiFi(255,255,255,0);

/* MQTT Broker Configuracion */
const char* address = "192.168.1.115";  /* Broker address (MQTT), No debe incluir 'http://xxx' o 'tcp://xxx' */
int port = 1883;
const char* user = "";			/* MQTT user */			/* En caso de que el Broker necesite autenticación */
const char* password = "";	/* MQTT password */

/* Intervalo de tiempo entre toma-envio de datos */
long interval = 8;    /* Tiempo en segundos */


#endif
