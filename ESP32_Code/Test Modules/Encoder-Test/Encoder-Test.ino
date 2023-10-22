

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


// Variáveis do Sensor Infravermelho e PID
double rpm;
volatile byte pulsos;
unsigned long timeold;
unsigned int pulsosDisco = 20;    //Altere o valor conforme disco encoder





// Função executada a cada interrupção
void IRAM_ATTR contador()
{
  pulsos++;  //Incrementa contador
  
}





void setup()
{
  // Inicia Serial
  Serial.begin(115200);




    // Configura Interrupção
  pinMode(M1_S1, INPUT);
  pinMode(M1_S2, INPUT);
  pinMode(M2_S1, INPUT);
  pinMode(M2_S2, INPUT);
  attachInterrupt(digitalPinToInterrupt(M1_S1), contador, FALLING);
   pulsos = 0;
  rpm = 0;
  timeold = 0;


}

void loop()
{

  // Calcula RPM a cada 1 Segundo
  if (millis() - timeold >= 1000)
  {
 
    timeold = millis();


    // Exibe valores no serial monitor
    Serial.println(pulsos);
    //Serial.print("2222");


  }


}


