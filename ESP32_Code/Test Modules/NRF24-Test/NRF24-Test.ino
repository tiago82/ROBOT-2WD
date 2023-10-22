// Receptor (RX)

#include <SPI.h>
#include <RF24.h>


//============== PCB Pinout ==============
#define RST_RFID 2
#define SDA_RFID 5
#define SCK_RFID 18
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

#define BUZZER_PIN 22
//========================================






RF24 radio(CE_NRF, CSN_NRF);  // CE, CSN

void setup() {
  Serial.begin(9600);
  radio.begin();
  radio.openReadingPipe(1, 0xF0F0F0E1LL);  // Endereço do pipe para recepção
  radio.setPALevel(RF24_PA_HIGH);           // Potência de recepção
  radio.startListening();                  // Coloca o módulo no modo de recepção
}

void loop() {
  if (radio.available()) {
    char text[32] = "";
    radio.read(&text, sizeof(text));
    Serial.println(text);
  }
}
