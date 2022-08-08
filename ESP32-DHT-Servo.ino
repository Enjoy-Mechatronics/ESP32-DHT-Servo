#include <DHT.h>
#include <ESP32Servo.h>


DHT dht(26, DHT11);  // DHT Sensor (Pin, Type)

Servo TServo;        // Temperature Servo
const int TServoPin = 18;

Servo HServo;       // Humidity Servo
const int HServoPin = 19;

void setup() {
  
  dht.begin();
  TServo.attach(TServoPin);
  HServo.attach(HServoPin);
  
  Serial.begin(9600);

  // >> Comment These After Setting Up Servos 0 Position
  //TServo.write(0);
  //HServo.write(0);
  //delay(60000);
  
}

void loop() {
  
  // Wait a few seconds between measurements.
  delay(2000);

  // Read temperature as Celsius
  float t = dht.readTemperature();
  // Reading humidity
  float h = dht.readHumidity();

  //Write Values to Servos
  TServo.write(map(t, 0,60, 0,120));
  HServo.write(map(h, 0,90, 0,120));
  
  //Display Measurements on Serial Monitor
  Serial.print("Temperature: ");
  Serial.print(t);
  Serial.print("°C ");

  Serial.print("Humidity: ");
  Serial.print(h);
  Serial.println("% ");
  
}
