# Arduino MKR1000 - IOT2TANGLE

***Arduino MKR1000*** is the cheapest *WiFi Arduino Development Board*. Being an *Arduino*, it has all the benefits of this system, thus, very simple to make it work.

This Repository contains the source code and the steps to follow to be able to make *Arduino MKR1000* read sensor data and send it, in an organized way, to the *Tangle (DLT)* of the *IOTA Network* through the *Streams* layer.

# Setting up your Arduino MKR1000 with the I2T Sensors Stack

This is the list of Sensors/Modules that you can connect and it will be recognized immediately.
- ***BME280*** (*Bosch*) - Temperature, Humidity and Pressure sensor. -> Connected by *I2C Bus* via: *GPIO11/SDA* and *GPIO12/SCL* --- Be careful with the supply of this sensor, the BM280 is powered with 3.3V, if your module does not have a voltage regulator (some modules do not have it) the sensor can be damaged if you supply 5V.
- ***MPU6050*** (*InvenSense-TDK*) - Acelerometer and Gyroscope 6-axis. -> Connected by *I2C Bus* via: *GPIO11/SDA* and *GPIO12/SCL*.
- ***BH1750*** (*ROHM*) - Ambient Light Sensor. -> Connected by *I2C Bus* via: *GPIO11/SDA* and *GPIO12/SCL*.
- ***Generic Adjustable Sound Sensor with digital output*** (like *KY038 Module*) - -> Digital Signal on *GPIO4*, *GPIO5* to GND (to enable sound data collection).
- Also, you can connect a ***Green LED*** in *GPIO0* that blink when the data is sent to the Tangle, and a ***Red LED*** in *GPIO1* that will Blink in a certain way when it detects certain errors (totally optional)

## Connecting the sensors

The following diagram explains how each sensor of our stack must be connected to the pins. The *Arduino MKR1000 development board* has been used in this diagram.

![I2T Sensors Stack on MKR1000](https://i.postimg.cc/d1DRs4Zr/MKR1000-diagram.png)

**It is not necessary to have all the sensors listed here**, the code is able to detect which sensors were connected. In the case of not connecting any sensor, the only real data that will be displayed on the Tangle will be the Internal Temperature of *Arduino MKR1000*.


# Download Firmware on Arduino MKR1000
This repository uses many external dependencies / libraries, we recommend using the ones you will find in this repository, since we are sure that these versions of dependencies work without problems.

## 1) Open Arduino IDE
Arduino IDE Normal Version (*Windows, Linux* or *macOS*)

## 2) Install support for MKR1000 board from 'Board Manager'
```Tools``` -> ```Boards: XXXX``` -> ```Board Manager ...```, then select and install ***Arduino SAMD Boards (32-bits ARM Cortex-M0+)***.

## 3) Install all the dependencies
We recommend copying all the folders found in the ***'/dependencies'*** folder of this repository in the ***Arduino IDE library path***:

In Windows:
```Documents/My Documents/Arduino/Libraries```

In Linux:
```~/snap/arduino/XX/Arduino/libraries```

In macOS:
```~/Documents/Arduino/libraries/```

### 4) Edit configuration in 'Config.h' file:
The *Config.h* file must be opened and modified, this file is in the directory *'Arduino-MKR1000/http-sender'* of the repository.

This step is very important if you want to make a connection to the gateway. Your *WiFi Credentials*, the *address* and *port* that will have the *I2T Streams HTTP Gateway* or *Keepy* running, the *Device Id*, and others configurations. The *Id Name Device* you define here must be between the devices you set in on the *Gateway configuration file*. 
```
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
```

### 5) Open Project and 'Upload' in your Board:

```File``` -> ```Open```, then select the project ***http-sender.ino***.

Make sure you have chosen *Arduino MKR1000* in *Board Configuration*.

```Sketch``` -> ```Upload```

### 6) Open Serial Monitor:

```Tools``` -> ```Serial Monitor```

Make sure to set Serial Monitor to 115200 bps


Upon completion, the firmware is Uploaded to your *Arduino MKR1000*. If the *I2T Streams HTTP Gateway* is configured correctly (we will explain this next), ***you will be sending data to Tangle via Streams***.

The following screenshot is a reading of the *Serial Port*, you should see something like this:

![Arduino MKR1000 sending data to the Tangle](https://i.postimg.cc/xjy4yVmd/Screenshot-from-2021-05-06-10-32-35.png)


# Setting up the Streams HTTP Gateway

## Preparation

Install Rust if you don't have it already. More info about Rust here https://www.rust-lang.org/tools/install

```
curl --proto '=https' --tlsv1.2 -sSf https://sh.rustup.rs | sh
```

Make sure you also have the build dependencies installed, if not run:  

```
sudo apt update
sudo apt install build-essential pkg-config libssl-dev  
```

## Installing the Streams Gateway
Get the Streams Gateway repository
https://github.com/iot2tangle/Streams-http-gateway

```
git clone https://github.com/iot2tangle/Streams-http-gateway
```

Navigate to the root of **Streams-http-gateway** directory and edit the **config.json** file to define yours *device names*, *endpoint*, *port*, you can also change the IOTA Full Node used, among others.

## Start the Streams Server

### Sending messages to the Tangle

Run the Streams Gateway:  

```
cargo run --release  
```
This will compile and start the *Streams HTTP Gateway*. Note that the compilation process may take from 3 to 25 minutes (Pi3 took us around 15/25 mins, Pi4 8 mins and VPS or desktop machines will generally compile under the 5 mins) depending on the device you are using as host.
You will only go through the compilation process once and any restart done later will take a few seconds to have the Gateway working.

Once started, the ***Channel Id*** will be displayed, and the gateway will be open waiting for data to send to the Tangle.

![Streams Gateway receiving data](https://i.postimg.cc/zfz0tbWz/Screenshot-from-2020-10-16-11-44-59.png)
*The Channel Id that will allow subscribers to access the channel data.*

### Reading messages from the Tangle

You can read the received messages directly from the **I2T Explorer**: https://explorer.iot2tangle.io/ using the Channel Id printed by the Gateway in shell.   

![I2T Explorer](https://i.postimg.cc/wTNf7dgp/Screenshot-from-2020-10-16-11-46-16.png)


*For inquiries, improvements or errors detected, please start an issue in this repository.*
