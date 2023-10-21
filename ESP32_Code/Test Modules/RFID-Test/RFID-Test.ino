#include <SPI.h>
#include <MFRC522.h>

//========================
#define RST_RFID 2
#define SDA_RFID 5 //SS_PIN
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
//========================

MFRC522 mfrc522(SDA_RFID, RST_RFID);   // Crie um objeto MFRC522

void setup() {
  Serial.begin(9600);  // Inicialize a comunicação serial

  SPI.begin();          // Inicialize a interface SPI
  mfrc522.PCD_Init();   // Inicialize o MFRC522
}

void loop() {
  // Verifique se um cartão está presente
  if (mfrc522.PICC_IsNewCardPresent() && mfrc522.PICC_ReadCardSerial()) {
    // Mostra a ID do cartão
    Serial.print("Cartão RFID lido. ID: ");
    for (byte i = 0; i < mfrc522.uid.size; i++) {
      Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
      Serial.print(mfrc522.uid.uidByte[i], HEX);
    }
    Serial.println();
    
    mfrc522.PICC_HaltA();     // Pare a comunicação do cartão
  }
}
