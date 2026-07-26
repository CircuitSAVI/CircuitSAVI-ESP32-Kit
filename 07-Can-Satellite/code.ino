#include <Wire.h>
#include <Adafruit_BMP280.h>
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>

Adafruit_BMP280 bmp;
Adafruit_MPU6050 mpu;

void setup() {
  Serial.begin(115200);
  Wire.begin();

  if (!bmp.begin(0x76)) {
    Serial.println("Could not find BMP280 sensor!");
  }

  if (!mpu.begin()) {
    Serial.println("Could not find MPU6050 sensor!");
  }

  mpu.setAccelerometerRange(MPU6050_RANGE_8_G);
  mpu.setGyroRange(MPU6050_RANGE_500_DEG);
  mpu.setFilterBandwidth(MPU6050_BAND_21_HZ);
}

void loop() {
  sensors_event_t a, g, temp;
  mpu.getEvent(&a, &g, &temp);

  float tempC = bmp.readTemperature();
  float pressure = bmp.readPressure() / 100.0F;
  float altitude = bmp.readAltitude(1013.25);

  Serial.print("Altitude: "); Serial.print(altitude); Serial.print(" m | ");
  Serial.print("Pressure: "); Serial.print(pressure); Serial.print(" hPa | ");
  Serial.print("Temp: "); Serial.print(tempC); Serial.print(" C | ");
  Serial.print("Accel X: "); Serial.print(a.acceleration.x); Serial.print(" Y: "); Serial.print(a.acceleration.y); Serial.print(" Z: "); Serial.println(a.acceleration.z);

  delay(1000);
}
