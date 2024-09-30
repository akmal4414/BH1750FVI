#include <Wire.h>
#include <BH1750.h>

BH1750 lightMeter;

void setup() {
  Serial.begin(115200);

  Wire.begin(21, 22); // Default SDA is GPIO 21 and SCL is GPIO 22 on most ESP32 boards = Wire.begin(SDA, SCL)


  // Initialize the light meter
  lightMeter.begin();

  Serial.println(F("BH1750 Test begin"));
}

void loop() {
  float lux = lightMeter.readLightLevel();
  Serial.print("Light: ");
  Serial.print(lux);
  Serial.println(" lx");
  delay(1000);
}