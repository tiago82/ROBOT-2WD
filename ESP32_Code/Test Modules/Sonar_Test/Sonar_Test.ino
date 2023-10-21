
#include <HCSR04.h>

// ====================================================
#define RST_RFID 2
#define SDA_RFID 5
#define SCK_RFID 9
#define MISO_RFID 19
#define MOSI_RFID 23

#define CSN_NRF 15
#define MOSI_NRF 13
#define MISO_NRF 12
#define SCK_NRF 14
#define CE_NRF 27

#define EN1 4
#define EN2 25
#define IN1 16
#define IN2 3
#define IN3 26
#define IN4 1

#define M1_S1 32
#define M1_S2 33
#define M2_S1 34
#define M2_S2 35

#define TRIG_PIN 21
#define ECHO_PIN 17
// ====================================================





#include <HCSR04.h>

// Initialize sensor that uses digital pins 13 and 12.

UltraSonicDistanceSensor distanceSensor(TRIG_PIN, ECHO_PIN);

void setup () {
    Serial.begin(9600);  // We initialize serial connection so that we could print values from sensor.
}

void loop () {
    // Every 500 miliseconds, do a measurement using the sensor and print the distance in centimeters.
    float distance = distanceSensor.measureDistanceCm();
    Serial.println(distance);
    delay(500);
}
