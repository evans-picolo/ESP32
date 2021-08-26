#include <WiFi.h>

// Difinição dos pinos 
#define VERM_PIN 4
#define AMAR_PIN 2

// Definição dos dados de acesso à rede
const char* ssid     = "ASTHOR";
const char* password = "ctm13199";

// Instancia objeto para ser o servidor - a classe WiFiServer está inclusa na biblioteca WiFi.h)
WiFiServer server(80);      // porta 80 


void setup()
{
    // Configuração dos pinos 
    pinMode(AMAR_PIN, OUTPUT);      
    pinMode(VERM_PIN, OUTPUT);      

    delay(10);

    // Inicia comunicação serial (para monitoramento) 
    Serial.begin(9600);

    // Inicia conexão WiFi
    Serial.print("\n\nTentando conectar a ");
    Serial.print(ssid);
    WiFi.begin(ssid, password);
    
    // Espera conectar - fica printando um ponto na tela enquando a conexão não estabiliza 
    while (WiFi.status() != WL_CONNECTED) { 
        delay(500);
        Serial.print(".");
    }

    // Avisa que a conexão foi estabelecida e printa o IP  
    Serial.print("\n\nConectado a ");
    Serial.println(ssid);
    Serial.print("IP address: ");
    Serial.println(WiFi.localIP());

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
            client.print("<br>LED vermelho <a href=\"/v1\">ON </a> <br>");
            client.print("<br>LED vermelho <a href=\"/v0\">OFF</a> <br>");
            client.print("<br>LED amarelo  <a href=\"/a1\">ON </a> <br>");
            client.print("<br>LED amarelo  <a href=\"/a0\">OFF</a> <br>");

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


        // Analisa a mensagem recebida e verifica qual é a ação a ser tomada
        // Nesse caso está sendo avaliado somente os últimos caracteres de cada string, pois a mesagens recebidas serão algo do tipo "GET /v1" ou "GET /v0" (via http) ou simplesmente "v1" ou "v0" via wifi terminal
        if (currentLine.endsWith("v1")) {
          digitalWrite(VERM_PIN, HIGH);               // acender led vermelho
        }
        if (currentLine.endsWith("v0")) {
          digitalWrite(VERM_PIN, LOW);                // apagar led vermelho
        }
        if (currentLine.endsWith("a1")) {
          digitalWrite(AMAR_PIN, HIGH);               // acender led amarelo
        }
        if (currentLine.endsWith("a0")) {
          digitalWrite(AMAR_PIN, LOW);                // apagar led amarelo
        }
      }
    }// fim do loop (client.connected)

    // Encerra cliente
    client.stop();
    Serial.println("Client Disconnected.\n");
  }
}
