
#include <ESP32Servo.h>

Servo myservo;  

int i=0;

void setup() {
  Serial.begin(9600);
  
  myservo.attach(23);  

  myservo.write(0);

  delay(1000);

  Serial.println("INICIO");
  
}

void loop() {
  for (i=0; i<=90; i=i+5) {
    myservo.write(i); 
    delay(50);                  
  }
  delay(1000);
  for (i=90; i>=0; i=i-5) {
    myservo.write(i);  
    delay(50);                
  }
  delay(1000);
}

