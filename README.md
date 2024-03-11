[![Open Source Love](https://badges.frapsoft.com/os/v1/open-source.svg?style=flat)](https://github.com/ellerbrock/open-source-badges/)
[![License: MIT](https://img.shields.io/badge/License-MIT-blue.svg?logo=github&color=%23F7DF1E)](https://opensource.org/licenses/MIT)
![GitHub last commit](https://img.shields.io/github/last-commit/devancakra/IoT-based-Soil-Moisture-Monitoring-System-using-HTTP-and-UART-communication-protocols)
![Project](https://img.shields.io/badge/Project-Internet%20of%20Things-light.svg?style=flat&logo=arduino&logoColor=white&color=%23F7DF1E)

# IoT-based-Soil-Moisture-Monitoring-System-using-HTTP-and-UART-communication-protocols
<strong>Solo Project: IoT-based Soil Moisture Monitoring System using HTTP and UART communication protocols</strong><br><br>
ESP-01-based IoT systems generally use AT commands to be able to perform actions in a network. These AT commands are known to be many. In addition, the combination of commands is difficult to understand for a beginner. Therefore, this project was created to improve the convenience of the ESP-01-based IoT system. In this case, the author used the UART protocol on the development board side. This project has been implemented and took approximately 2 weeks. Two types of development boards were used. Arduino Uno R3 is used to retrieve soil moisture data from the sensor which is then sent to ESP-01S via UART communication: Serial Software. Meanwhile, ESP-01S is used to receive data from Arduino Uno via UART communication: Hardware Serial and then send the data to Ubidots via HTTP protocol.

<br><br>

## Project Requirements
| Part | Description |
| --- | --- |
| Development Board | • Arduino Uno R3<br>• ESP-01S |
| Code Editor | Arduino IDE |
| Programmer Tools | CH340 USB TO ESP-01 |
| Driver | USB-Serial CH340 |
| IoT Platform | Ubidots |
| Communications Protocol | • Hypertext Transfer Protocol (HTTP)<br>• Universal Asynchronous Receiver-Transmitter (UART) |
| IoT Architecture | 3 Layer |
| Programming Language | C/C++ |
| Arduino Library | • SoftwareSerial (default)<br>• Ubidots-ESP8266 |
| Sensor | Capacitive Soil Moisture Sensor (x1) |
| Other Components | • USB type B cable - USB type A (x1)<br>• Jumper cable (1 set)<br>• ESP-01 Adapter (x1) |

<br><br>

## Download & Install
1. Arduino IDE

   <table><tr><td width="810">
         
   ```
   https://www.arduino.cc/en/software
   ```

   </td></tr></table><br>
   
2. USB-Serial CH340

   <table><tr><td width="810">
   
   ```
   https://bit.ly/CH340_Driver
   ```
   
   </td></tr></table>
   
<br><br>

## Project Designs
<table>
<tr>
<th width="420">Block Diagram</th>
<th width="420">Infrastructure</th>
</tr>
<tr>
<td><img src="https://github.com/devancakra/IoT-based-Soil-Moisture-Monitoring-System-using-HTTP-and-UART-communication-protocols/assets/54527592/36612e47-62b8-4eab-8232-b0616c47d8a6" alt="Block-Diagram"></td>
<td><img src="https://github.com/devancakra/IoT-based-Soil-Moisture-Monitoring-System-using-HTTP-and-UART-communication-protocols/assets/54527592/6327e020-3576-42ce-a801-83a1ed5ca29b" alt="Infrastructure"></td>
</tr>
</table>
<table>
<tr>
<th width="420">Pictorial Diagram</th>
<th width="420">Wiring</th>
</tr>
<tr>
<td><img src="https://github.com/devancakra/IoT-based-Soil-Moisture-Monitoring-System-using-HTTP-and-UART-communication-protocols/assets/54527592/e0458ee4-b685-4296-b3fc-d4bb20823891" alt="Pictorial-Diagram"></td>
<td><img src="https://github.com/devancakra/IoT-based-Soil-Moisture-Monitoring-System-using-HTTP-and-UART-communication-protocols/assets/54527592/2ec91826-9f04-4548-9ac5-9db08d28738d" alt="Wiring"></td>
</tr>
</table>

<br><br>

## Basic Knowledge
• <strong>Serial Communication</strong>

Basically, a device can be communicated with other devices either wirelessly or by cable. Communication between commonly used hardware is ``` Serial Communication ```. It can be known that there are three types of ``` Serial Communication ```, which include: ``` UART (Universal Asynchronous Receiver-Transmitter) ```, ``` SPI (Serial Peripheral Interface) ```, and ``` I2C (Inter Integrated Circuit) ```. ``` Serial UART communication ``` allows each device to act as a ``` master ``` or ``` slave ``` in a limited way. ``` Master ``` is the primary device that has full authority over the control of the Slave, while the ``` Slave ``` is the secondary device that is under the authority of the Master device. There are two kinds of ``` UART Serial Communication ```, namely ``` Hardware Serial ``` and ``` Software Serial ```. ``` Hardware serial communication ``` can be done by connecting the ``` TX ``` and ``` RX ``` pins ``` crosswise ``` on each development board, for example: ``` RX-TX ```, then ``` TX-RX ```. The ``` TX ``` pin is for ``` sending data ```, while the ``` RX ``` pin is for ``` receiving data ```. ``` Serial Software Communication ``` is more or less the same as ``` Serial Hardware Communication ``` in terms of cabling, but there are differences in terms of coding. By using this ``` Serial Software ``` you can overcome the constraints of the limitations of ``` RX ``` and ``` TX ``` pins on the development board. To communicate with this ``` Serial Software ``` is quite easy, namely by using certain ``` Digital Pins ``` as a ``` substitute for TX pins and RX pins ```.<br><br>

• <strong>Internet of Things</strong>

Internet of Things (IoT) is a concept where things connected to a network can perform one or more actions in achieving a goal. These actions include data collection, data transmission, data reception, or data processing. Every IoT project requires devices that can connect to WiFi such as ESP. ESP consists of 2 types, namely ESP8266 and ESP32. This is on the market very diverse models, for that you need to readjust to the needs in the project so as not to cause disappointment.

<br><br>

## Arduino IDE Setup
1. Open the ``` Arduino IDE ``` first, then open the project by clicking ``` File ``` -> ``` Open ``` :

   <table><tr><td width="810">
   
      • ``` Master.ino ```
      
      • ``` Slave.ino ```

   </td></tr></table><br>
   
2. Fill in the ``` Additional Board Manager URLs ``` in Arduino IDE

   <table><tr><td width="810">
      
      Click ``` File ``` -> ``` Preferences ``` -> enter the ``` Boards Manager Url ``` by copying the following link :
   
      ```
      http://arduino.esp8266.com/stable/package_esp8266com_index.json
      ```

   </td></tr></table><br>
   
3. ``` Board Setup ``` in Arduino IDE

   <table>
      <tr><th>
         
      i
         
      </th><th width="780">
            
      How to setup the ``` Arduino Uno ``` board
   
      </th></tr>
      <tr><td colspan="2">

      Click ``` Tools ``` -> ``` Board ``` -> ``` Arduino AVR Boards ``` -> ``` Arduino Uno ```
              
      </td></tr>
   </table><br><table>
      <tr><th>
         
      ii
         
      </th><th width="775">

      How to setup the ``` ESP-01S ``` board
            
      </th></tr>
      <tr><td colspan="2">

      • Click ``` Tools ``` section -> ``` Board ``` -> ``` Boards Manager ``` -> Install ``` esp8266 ```.

      • Then click ``` Tools ``` -> ``` Board ``` -> ``` ESP8266 Boards ``` -> ``` Generic ESP8266 Module ```.
            
      </td></tr>
   </table><br>
   
4. ``` Change the Board Speed ``` in Arduino IDE

   <table>
      <tr><th>
         
      i
         
      </th><th width="780">
            
      How to change the speed of ``` Arduino Uno ``` board
   
      </th></tr>
      <tr><td colspan="2">

      Click ``` Tools ``` -> ``` Upload Speed ``` -> ``` 9600 ```
              
      </td></tr>
   </table><br><table>
      <tr><th>
         
      ii
         
      </th><th width="775">

      How to change the speed of ``` ESP-01S ``` board
            
      </th></tr>
      <tr><td colspan="2">

      Click ``` Tools ``` -> ``` Upload Speed ``` -> ``` 9600 ```
            
      </td></tr>
   </table><br>
   
5. ``` Install Library ``` in Arduino IDE

   <table><tr><td width="810">
         
      Download all the library zip files. Then paste it in the: ``` C:\Users\Computer_Username\Documents\Arduino\libraries ```

   </td></tr></table><br>

6. ``` Port Setup ``` in Arduino IDE

   <table><tr><td width="810">
         
      Click ``` Port ``` -> Choose according to your device port ``` (you can see in device manager) ```

   </td></tr></table><br>

7. Change the ``` WiFi Name ```, ``` WiFi Password ```, and so on according to what you are currently using.<br><br>

8. Before uploading the program please click: ``` Verify ```.<br><br>

9. If there is no error in the program code, the next step is to use the ``` ESP-01 ``` programming tool according to the procedure. Then click: ``` Upload ```. While ``` Arduino Uno ``` can be done directly without using programming tools.<br><br>

10. If there is still a problem when uploading the program, then try checking the ``` driver ``` / ``` port ``` / ``` programmer tool ``` / ``` others ``` section.

<br><br>

## Programmer Tools Setup: CH340 USB TO ESP-01
1. ``` Programming Mode ``` :
      
   • Attach the ``` ESP-01 ``` to the ``` CH340 USB TO ESP-01 ```.

   • Press and hold the button on the ``` CH340 USB TO ESP-01 ```, and plug it into computer/laptop.
   
   • Release the button when the device is recognized by the computer/laptop.
   
   • Please ``` upload ``` the program.<br><br><br>
   
2. ``` Operating Mode ``` :
   
   • Disconnect the ``` CH340 USB TO ESP-01 ``` from the computer/laptop.

   • Attach the ``` ESP-01 ``` to the ``` ESP-01 Adapter ```.
   
   • The program code that has been embedded in this ``` ESP-01 board ``` is ready for operation (no more programming activities).<br><br><br>

<strong>Notes :</strong>

<table><tr><td width="840">
   
   • To upload the program, besides using the ``` CH340 USB TO ESP-01 ```, you can also use other programming tools such as: ``` FTDI FT232RL ``` or ``` USB PL2303 ```.

   • Based on experience, I admit that using the ``` CH340 USB TO ESP-01 ``` is much better than the ``` FTDI FT232RL ``` as well as ``` USB PL2303 ``` because it does not require a cable to be connected to a computer/laptop.

</td></tr></table><br><br>

## Ubidots Setup
1. Getting started with Ubidots :

   <table><tr><td width="810">
   
      • Please <a href="https://industrial.ubidots.com/accounts/signin/">Log in</a> to access the ``` Ubidots ``` service.
      
      • If you don't have a ``` Ubidots ``` account yet, please create one.

   </td></tr></table><br>

2. Creating devices : 

   <table><tr><td width="810">
   
      • After logging into the account -> click ``` Devices ```.
   
      • Click ``` + (Create a device) ``` -> then select ``` Blank Device ```.
   
      • ``` Device name ``` customize according to your needs.

      • ``` Device label ``` customize what was on Ubidots when it successfully sent the data the first time, in which case it will usually be an ID.

      • Select ``` ✅ Checklist ``` to save.

   </td></tr></table><br>

3. Creating dashboards : 

   <table><tr><td width="810">
   
      • Click ``` Data ``` -> then select ``` Dashboards ```.
   
      • Click ``` Add new Dashboard ```.
   
      • ``` Name ```, ``` Tags ```, ``` Default time range ``` -> customize it to your needs.

      • ``` Dynamic Dashboard ``` -> change it to ``` Dynamic (Single Device) ```.

      • ``` Default Device ``` -> select the device you want to display.

      • Leave the other settings alone -> then click ``` SAVE ```.

   </td></tr></table><br>

4. Creating widget : 

   <table><tr><td width="810">
   
      • Make sure you are in the ``` Dashboards ``` menu.
   
      • Click ``` + Add new widget ```.
   
      • Please choose according to your needs. In this project, the author uses ``` Line chart ``` for data visualization.
   
      • Please set the variables that you want to display on the widget by clicking ``` + Add Variables ```, then click ``` ✅ Checklist ``` to save.
   
      • If you want to change the content of the widget, please click the ``` pencil ``` symbol -> if so, then click ``` ✅ Checklist ``` to save.

   </td></tr></table><br>

5. Firmware configuration : 

   <table><tr><td width="810">
   
      • Click the ``` User ``` section in the top right corner -> then select ``` API Credentials ```.
   
      • Copy the ``` Default token ``` -> paste it into the firmware code. An example is as follows:

      <table><tr><td width="780">
   
      ```ino
      const String token = "BBUS-aRZvtYRMM7IWbrKFcICR30YYP7dh5Q"; // define ubidots token
      ```

      </td></tr></table>

   </td></tr></table>

<br><br>

## Get Started
1. Download and extract this repository.<br><br>
   
2. Make sure you have the necessary electronic components.<br><br>
   
3. Make sure your components are designed according to the diagram.<br><br>
   
4. Configure your device according to the settings above.<br><br>

5. Please enjoy [Done].

<br><br>

## Highlights
<table>
<tr>
<th width="420">Hardware</th>
<th width="420">Serial Monitor & IoT Platform: Ubidots</th>
</tr>
<tr>
<td><img src="https://github.com/devancakra/IoT-based-Soil-Moisture-Monitoring-System-using-HTTP-and-UART-communication-protocols/assets/54527592/41a13e11-7acd-4943-abb9-d551a63073f8" alt="hardware"></td>
<td><img src="https://github.com/devancakra/IoT-based-Soil-Moisture-Monitoring-System-using-HTTP-and-UART-communication-protocols/assets/54527592/998a5e4b-c96d-4a4e-863b-3f28d0f92023" alt="serialmonitor-iotplatform"></td>
</tr>
</table>

<br><br>

## Appreciation
If you find this work useful, please support it as a token of appreciation to the author by clicking the ``` ⭐Star ``` button.

<br><br>

## Disclaimer
This application has been created by including third-party sources. Third parties here are service providers, whose services are in the form of libraries, frameworks, and others. I thank you very much for the service. It has proven to be very helpful and implementable.

<br><br>

## LICENSE
MIT License - Copyright © 2024 - Devan C. M. Wijaya, S.Kom

Permission is hereby granted without charge to any person obtaining a copy of this software and the software-related documentation files to deal in them without restriction, including without limitation the right to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons receiving the Software to be furnished therewith on the following terms:

The above copyright notice and this permission notice must accompany all copies or substantial portions of the Software.

IN ANY EVENT, THE AUTHOR OR COPYRIGHT HOLDER HEREIN RETAINS FULL OWNERSHIP RIGHTS. THE SOFTWARE IS PROVIDED AS IS, WITHOUT WARRANTY OF ANY KIND, EITHER EXPRESS OR IMPLIED, THEREFORE IF ANY DAMAGE, LOSS, OR OTHERWISE ARISES FROM THE USE OR OTHER DEALINGS IN THE SOFTWARE, THE AUTHOR OR COPYRIGHT HOLDER SHALL NOT BE LIABLE, AS THE USE OF THE SOFTWARE IS NOT COMPELLED AT ALL, SO THE RISK IS YOUR OWN.
