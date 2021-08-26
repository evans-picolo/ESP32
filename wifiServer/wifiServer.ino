#include <WiFi.h>

// Difinição dos pinos 
#define BUTTON_PIN 27

// Definição dos dados de acesso à rede
const char* ssid     = "ASTHOR";
const char* password = "ctm13199";

// Instancia objeto para ser o servidor - a classe WiFiServer está inclusa na biblioteca WiFi.h)
WiFiServer server(80);      // porta 80 


void setup()
{
    // Configuração dos pinos 
    pinMode(BUTTON_PIN, INPUT);      

    delay(10);

    // Inicia comunicação serial (para monitoramento) 
    Serial.begin(9600);

    // Inicia conexão WiFi
    Serial.println();
    Serial.print("Tentando conectar a ");
    Serial.print(ssid);
    WiFi.begin(ssid, password);
    
    // Espera conectar - fica printando um ponto na tela enquando a conexão não estabiliza 
    while (WiFi.status() != WL_CONNECTED) { 
        delay(500);
        Serial.print(".");
    }
    Serial.println();

    // Avisa que a conexão foi estabelecida e printa o IP  
    Serial.print("Conectado a ");
    Serial.print(ssid);
    Serial.print(" com IP ");
    Serial.print(WiFi.localIP());
    Serial.println();

    // Uma vez conectado a rede, inicia o servidor 
    server.begin();

}


void loop(){

 // Instancia um objeto para representar o cliente que se conectou ao ESP  
 WiFiClient client = server.available();   

  // Se houver um cliente conectado, o esp deve escutar o que ele está dizendo linha por linha
  if (client) {                            
    Serial.println("\nNew Client.");          
    String currentLine = "";                

    while (client.connected()) {           
      
      // Lê caracter por caracter (c) e concatena na String (currentLine) até a mensagem acabar 
      if (client.available()) {             
        char c = client.read();
        Serial.write(c);        // printa o caracter no serial monitor                 
       
        // Caso o caracter seja "/n", então a linha terminou
        if (c == '\n') {                    

          // Se a linha está vazia, signifca que o cliente terminou a requisição http
          // Ou seja, o cliente já terminou de falar. Então, envia uma resposta. 
          if (currentLine.length() == 0) {

            // Respostas HTTP sempre começam com um código de resposta e um "content-type" seguidos de um "/n"
            client.println("HTTP/1.1 200 OK");                  
            client.println("Content-type:text/html");
            client.println();

            // Corpo da resposta - Neste caso, se trata de links para enviar as mensagens pro esp quando clicados
            // "texto <a href=\"/ mensagem \"> texto do link </a> texto"
            //<br> = /n
            client.print(digitalRead(BUTTON_PIN));

            // A resposta deve terminar com uma linha em branco
            client.println();
            
            // Uma vez que a mesangem foi recebida e a resposta foi enviada, o cliente pode ser encerrado saindo do loop (client.connected)
            break;

            // Se a linha não está vazia, então é só um "/n" comum. Então esvazia a String para receber a nova linha
          } else {    
            currentLine = "";
          }

          // Se o caracter não for "/n" nem "/r" então concatena na String, pois se trata de parte da mensagem 
        } else if (c != '\r') {  
          currentLine += c;      
        }
      }
    }// fim do loop (client.connected)

    // Encerra cliente
    client.stop();
    Serial.println("Client Disconnected.\n");
    Serial.println("-----");
    Serial.println();
  }
}
