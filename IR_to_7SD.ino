#include <IRremote.h>

#define BUT_0 0xFF6897
#define BUT_1 0xFF30CF
#define BUT_2 0xFF18E7
#define BUT_3 0xFF7A85
#define BUT_4 0xFF10EF
#define BUT_5 0xFF38C7
#define BUT_6 0xFF5AA5
#define BUT_7 0xFF42BD
#define BUT_8 0xFF4AB5
#define BUT_9 0xFF52AD

//get each connected pin og the 7 segment display (7SD)
int aPin = 2;
int bPin = 3;
int cPin = 4;
int dPin = 5;
int ePin = 6;
int fPin = 7;
int gPin = 8;

//IR recieve pin
int RECV_PIN = 11;
IRrecv irrecv(RECV_PIN);
decode_results results;


void setup() {
  Serial.begin(9600);
  Serial.println("Press any number on the remote ...");
  Serial.println("");
  irrecv.enableIRIn();
  
  //initalise pins to output
  pinMode(aPin,OUTPUT);
  pinMode(bPin,OUTPUT);
  pinMode(cPin,OUTPUT);
  pinMode(dPin,OUTPUT);
  pinMode(ePin,OUTPUT);
  pinMode(fPin,OUTPUT);
  pinMode(gPin,OUTPUT);
  
  //turn all lights on 7SD to off
  digitalWrite(aPin,HIGH);
  digitalWrite(bPin,HIGH);
  digitalWrite(cPin,HIGH);
  digitalWrite(dPin,HIGH);
  digitalWrite(ePin,HIGH);
  digitalWrite(fPin,HIGH);
  digitalWrite(gPin,HIGH);
}

void writeCode(int code){
    switch(code){
    case BUT_0: 
        Serial.println("0");
        delay(500);
        digitalWrite(aPin,LOW);
        digitalWrite(bPin,LOW);
        digitalWrite(cPin,LOW);
        digitalWrite(dPin,LOW);
        digitalWrite(ePin,LOW);
        digitalWrite(fPin,LOW);
        digitalWrite(gPin,HIGH);
        delay(500);             
        break;
    case BUT_1: 
        Serial.println("1");
        delay(500);
        digitalWrite(aPin,HIGH);
        digitalWrite(bPin,LOW);
        digitalWrite(cPin,LOW);
        digitalWrite(dPin,HIGH);
        digitalWrite(ePin,HIGH);
        digitalWrite(fPin,HIGH);
        digitalWrite(gPin,HIGH);
        delay(500);             
        break;
    case BUT_2: 
        Serial.println("2");
        delay(500);
        digitalWrite(aPin,LOW);
        digitalWrite(bPin,LOW);
        digitalWrite(cPin,HIGH);
        digitalWrite(dPin,LOW);
        digitalWrite(ePin,LOW);
        digitalWrite(fPin,HIGH);
        digitalWrite(gPin,LOW);
        delay(500);             
        break;
    case BUT_3: 
        Serial.println("3");
        delay(500);
        digitalWrite(aPin,LOW);
        digitalWrite(bPin,LOW);
        digitalWrite(cPin,LOW);
        digitalWrite(dPin,LOW);
        digitalWrite(ePin,HIGH);
        digitalWrite(fPin,HIGH);
        digitalWrite(gPin,LOW);
        delay(500);             
        break;
    case BUT_4: 
        Serial.println("4");
        delay(500);
        digitalWrite(aPin,HIGH);
        digitalWrite(bPin,LOW);
        digitalWrite(cPin,LOW);
        digitalWrite(dPin,HIGH);
        digitalWrite(ePin,HIGH);
        digitalWrite(fPin,LOW);
        digitalWrite(gPin,LOW);
        delay(500);             
        break;
    case BUT_5: 
        Serial.println("5");
        delay(500);
        digitalWrite(aPin,LOW);
        digitalWrite(bPin,HIGH);
        digitalWrite(cPin,LOW);
        digitalWrite(dPin,LOW);
        digitalWrite(ePin,HIGH);
        digitalWrite(fPin,LOW);
        digitalWrite(gPin,LOW);
        delay(500);             
        break;
    case BUT_6: 
        Serial.println("6");
        delay(500);
        digitalWrite(aPin,LOW);
        digitalWrite(bPin,HIGH);
        digitalWrite(cPin,LOW);
        digitalWrite(dPin,LOW);
        digitalWrite(ePin,LOW);
        digitalWrite(fPin,LOW);
        digitalWrite(gPin,LOW);
        delay(500);             
        break;
    case BUT_7: 
        Serial.println("7");
        delay(500);
        digitalWrite(aPin,LOW);
        digitalWrite(bPin,LOW);
        digitalWrite(cPin,LOW);
        digitalWrite(dPin,HIGH);
        digitalWrite(ePin,HIGH);
        digitalWrite(fPin,HIGH);
        digitalWrite(gPin,HIGH);
        delay(500);             
        break;
    case BUT_8: 
      Serial.println("8");
      delay(500);
      digitalWrite(aPin,LOW);
      digitalWrite(bPin,LOW);
      digitalWrite(cPin,LOW);
      digitalWrite(dPin,LOW);
      digitalWrite(ePin,LOW);
      digitalWrite(fPin,LOW);
      digitalWrite(gPin,LOW);
      delay(500);
      break;
    case BUT_9: 
      Serial.println("9");
      delay(500);
      digitalWrite(aPin,LOW);
      digitalWrite(bPin,LOW);
      digitalWrite(cPin,LOW);
      digitalWrite(dPin,LOW);
      digitalWrite(ePin,HIGH);
      digitalWrite(fPin,LOW);
      digitalWrite(gPin,LOW);
      delay(500);
     default :Serial.println("unknown");
    }
}

void loop() {
  if (irrecv.decode(&results)) {
    unsigned int value = results.value;
    writeCode(value);
    irrecv.resume(); // Receive the next value
  }
}
