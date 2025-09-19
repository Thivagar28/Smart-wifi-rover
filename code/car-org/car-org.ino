#define BLYNK_TEMPLATE_ID "your template id"
#define BLYNK_TEMPLATE_NAME "your template name"
#define BLYNK_AUTH_TOKEN "your blynk token"

#define BLYNK_PRINT Serial
#include <WiFi.h>
#include <BlynkSimpleEsp32.h>
#include <ESP32Servo.h>


Servo servo1;
const char* ssid = "your wifi name";
const char* password = "your wifi password";

// Motor driver pins
#define IN3  32
#define IN4  33

// IR sensor pin (OUT pin connected to ESP32)
#define IR_SENSOR 4   // connect OUT pin of IR module here

BlynkTimer timer;

void setup() {
  Serial.begin(115200);

  pinMode(IR_SENSOR, INPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  servo1.attach(13);
  stopMotors(); // Stop at startup

  // Run IR check every 200 ms
  timer.setInterval(200L, checkIR);

  // Connect to WiFi and Blynk
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, password);
}

void loop() {
  Blynk.run();
  timer.run();
}

// Function to check IR sensor
void checkIR() {
  int irValue = digitalRead(IR_SENSOR);

  if (irValue == LOW) {   // LOW means obstacle detected
    
    Serial.println("Obstacle detected");
    moveForward();
    delay(200);
    stopMotors();
  }
  else {
    Serial.println("Path clear");
  }
}

// Servo control from Blynk slider (V2)
BLYNK_WRITE(V2) {
  int angle = param.asInt();        // Read slider value (0-180)
  servo1.write(angle);              // Rotate servo to that angle
  Serial.print("Servo angle: ");
  Serial.println(angle);
}

// Forward control (V0 button)
BLYNK_WRITE(V0) {
  if (param.asInt()) 
    moveForward();
  else 
    stopMotors();
}

// Backward control (V1 button)
BLYNK_WRITE(V1) {
  if (param.asInt()) 
    moveBackward();
  else 
    stopMotors();
}

// Movement functions
void moveForward() {
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  Serial.println("Moving Forward");
}

void moveBackward() {
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  Serial.println("Moving Backward");
}

void stopMotors() {
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  Serial.println("Motors Stopped");
}
