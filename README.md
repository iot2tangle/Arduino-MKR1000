# Arduino MKR1000 - IOT2TANGLE

***Arduino*** is an open-source platform used for building electronics projects. Arduino consists of both a *physical programmable circuit board* (often referred to as a microcontroller) and a piece of *software*, or IDE (Integrated Development Environment) that runs on your computer, used to write and upload computer code to the physical board.

The *Arduino* platform has become quite popular among people who are just starting with electronics, due to the simplicity that its environment offers, especially the junction between *Hardware-Software* in electronics used to be very problematic, *Arduino* solved this by bringing a fairly simple solution and generic.



## MKR1000

The main problem that the most popular *Arduino Development Boards* have is that they do not have a *built-in wireless connection* and must be added by external modules (wireless connection is very necessary for our objective). However in recent years Arduino has presented a series of ***Development Boards with TCP/IP - WiFi Connection***. The most popular and cheapest of these boards is ***Arduino MKR1000***.

## Objective

In this repository you will find explanations and step by step for the development of a system that every certain time interval (which you will set) will collect data from 5 sensors (including internal sensor), this data package will be sent to a special gateway designed by *IOT2TANGLE* that you will have on the local network. This gateway will be in charge of adding these packages to **Tangle Network of IOTA**, through *Streams*.

## I2T Sensors Stack

*IOT2TANGLE* provides with code to integrate the *Arduino MKR1000* and a give set of generic sensors (I2T sensor's stack). These are just suggested sensors and you can always add some other peripherals required by your project, however the sensors listed here are fully compatible and will be automatically detected when you connect them.

**It is not necessary to have all the sensors listed here**, the code is able to detect which sensors were connected. In the case of not connecting any sensor, the only real data that will be displayed on the Tangle will be the **Internal Temperature** of Arduino MKR1000.

This is the list of Sensors/Modules that you can connect and it will be recognized immediately:
- ***BME280*** (Bosch) - Temperature, Humidity and Pressure sensor.
- ***MPU6050*** (InvenSense-TDK) - Acelerometer and Gyroscope 6-axis.
- ***BH1750*** (ROHM) - Ambient Light Sensor.
- ***Generic Adjustable Sound Sensor with digital output*** (like *KY038 Module*)
- Also, you can connect a ***Green LED*** that blink when the data is sent to the Tangle, and a ***Red LED*** that will Blink in a certain way when it detects certain errors (totally optional).

## Available connectivity
- **[HTTP-sender](https://github.com/iot2tangle/Arduino-MKR1000/tree/main/http-sender)** -- Arduino MKR1000 will send the sensors data through HTTP to **[I2T HTTP Gateway](https://github.com/iot2tangle/Streams-http-gateway)** or **[Keepy](https://github.com/iot2tangle/Keepy)**
