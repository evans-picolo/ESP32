/*
 * Arduino Json
 * 
 * Código para mostrar como criar um Json com a biblioteca ArduinoJson.
 * 
 * Evans Picolo
 * Asthor Barden
 * ago/2021
 * 
 * Esse código foi baseado no exemplo da própria biblioteca ArduinoJson.
 * Mais informações no link abaixo:
 * https://arduinojson.org/?utm_source=meta&utm_medium=library.properties
 * 
 */

// ===== BIBLIOTECAS ======================================================================

#include <ArduinoJson.h>      // Comandos para criar o Json


// ===== OBJETOS ==========================================================================

StaticJsonDocument<200> doc;      // Objeto Json para guardas os valores do sensor


// ===== CONFIGURAÇÕES INICIAIS ==========================================================

void setup() {
  
  // Inicia comunicação serial
  Serial.begin(9600);

  // Adiciona os valores no Json
  doc["giroX"] = 30;
  doc["giroY"] = -100;

  // Pula umas linhas para facilitar a visualização
  Serial.println();
  Serial.println();

  // Envia o Json para um buffer de saída
  // Neste caso, to enviando para Serial
  // Se eu quiser enviar para um cliente wifi,
  // usaria serializeJson(doc, client)
  serializeJson(doc, Serial);

  // O resultado será:
  // {"sensor":"gps","time":1351824120}

}


// ===== PROGRAMA PRINCIPAL ==============================================================

void loop() {
  // Nada a ser feito aqui...
}
