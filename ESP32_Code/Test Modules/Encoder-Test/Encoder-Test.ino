

//============================
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
//===============================



int motor_c_ENA=9;  
int motor_c_IN1=6;
int motor_c_IN2=7;

#define STBY 8
#define ENCODER_A_PIN  2   
#define ENCODER_B_PIN  3   
long pulse_number=0;   
int rpm;

#include <MsTimer2.h> 

void setup()
{
    pinMode(STBY, OUTPUT);       
    digitalWrite(STBY, 1);
    pinMode(motor_c_ENA,OUTPUT);  
    pinMode(motor_c_IN1,OUTPUT);   
    pinMode(motor_c_IN2,OUTPUT);  

    MsTimer2::set(500, send);     
    MsTimer2::start();        

    pinMode(ENCODER_A_PIN, INPUT);
     pinMode(ENCODER_B_PIN, INPUT);
     attachInterrupt(0, read_quadrature, FALLING);  
    Serial.begin(9600);    
}

void loop()
{
   digitalWrite(motor_c_IN1,0);
    digitalWrite(motor_c_IN2,1);
    for (int a=100;a<=255;a++)
     {
        analogWrite(motor_c_ENA,a);
        delay(200);
     }


   digitalWrite(motor_c_IN1,0);
    digitalWrite(motor_c_IN2,1);
    for (int a=255;a>0;a--)
    {
        analogWrite(motor_c_ENA,a);
        delay(200);
     }
}

void send()    
{
     rpm=int(pulse_number/5.3);
     Serial.print("rpm: ");
     Serial.println(rpm, DEC);
     pulse_number = 0;
}

void read_quadrature()    
{
  if (digitalRead(ENCODER_A_PIN) == LOW)
  {
    if (digitalRead(ENCODER_B_PIN) == LOW)
    { pulse_number ++; }
    if (digitalRead(ENCODER_B_PIN) == HIGH)   
    { pulse_number --; }
  }
}
