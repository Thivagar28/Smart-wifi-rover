# Smart-wifi-rover
Wi-Fi controlled car using ESP32 with Blynk IOT app
[Demo Video](https://youtu.be/1mtEYH4Gpf0)

📘 Project Summary

This project demonstrates an IoT-based Wi-Fi-controlled car using the ESP32 microcontroller.
The car can be operated through a smartphone app or web interface using Wi-Fi communication.
It integrates motor driver (L298N), ESP32, and IR sensor to control motion in all directions.

🔌 Here the Circuit Diagram for the project 

[circuit diagram](https://github.com/Thivagar28/Smart-wifi-rover/blob/main/circuit-diagram/car-ckt.png)

⚙️ Working Principle

1. The ESP32 connects to Wi-Fi and links with the Blynk Cloud.

2. When you press a virtual button in the Blynk App, a command is sent to ESP32.

3. The microcontroller reads the virtual pin’s value and drives the L298N motor driver accordingly.

4. If someone's is standing behind the car the IR sensor detects automatically and the car moves from the obstacles.
   
5. Each button corresponds to Forward, Backward, Left, Right, or Stop motion.

📱 Blynk IoT App Configurations

here the data streams and dashboard connection

[web console](https://github.com/Thivagar28/Smart-wifi-rover/blob/main/app-interface/data-streams.png)

[web dashboard](https://github.com/Thivagar28/Smart-wifi-rover/blob/main/app-interface/web-dash-board.png)

💻 Arduino / ESP32 Code:

[code](https://github.com/Thivagar28/Smart-wifi-rover/blob/main/code/car-org/car-org.ino)

📷 Design pictures:

[photo](https://github.com/Thivagar28/Smart-wifi-rover/blob/main/output/Screenshot%202025-09-12%20030253.png)


🙌 Credits

Developed by Thivagar Mugil

Department of Electronics and Communication Engineering

National Engineering College


