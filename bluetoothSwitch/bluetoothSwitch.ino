#include <BluetoothSerial.h>

#define VERM_PIN 4
#define AMAR_PIN 2

char inChar; 

BluetoothSerial SerialBT;

void echo(String serialOut){   // o parametro é é o tipo String
  Serial.println(serialOut);
  SerialBT.println(serialOut);
}

void setup() {
  pinMode(AMAR_PIN, OUTPUT);
  pinMode(VERM_PIN, OUTPUT);

  Serial.begin(9600);
  SerialBT.begin("ESP32");
  
  Serial.println("\n\n---START---");
    
}

void loop() {
  
  if(SerialBT.available()){
    inChar = SerialBT.read();
    echo(String(inChar));                    // como o parãmetro da função echo é do tipo String, a variável precisa ser convertida em String para ser usada como argumento

    if(inChar == 'v'){
      digitalWrite(VERM_PIN, LOW);
      echo(String("VERMELHO OFF"));        // como o parãmetro da função echo é do tipo String, a mensagem precisa ser convertida em String para ser usada como argumento
    }
    
    if(inChar == 'V'){
      digitalWrite(VERM_PIN, HIGH);
      echo(String("VERMELHO ON"));
    }

    if(inChar == 'a'){
      digitalWrite(AMAR_PIN, LOW);
      echo(String("AMARELO OFF"));
    }

    if(inChar == 'A'){
      digitalWrite(AMAR_PIN, HIGH);
      echo(String("AMARELO ON"));
    }
    
    delay(100);
  }



}
