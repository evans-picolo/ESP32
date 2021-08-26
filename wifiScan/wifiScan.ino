/*
 *  This sketch demonstrates how to scan WiFi networks.
 *  The API is almost the same as with the WiFi Shield library,
 *  the most obvious difference being the different file you need to include:
 */
#include "WiFi.h"

String redeSSID = "";
int intensidadeSinal = -9999;

void setup()
{
    // Instrução para inicializar o Serial, utilizaremos apenas para log no monitor.
    Serial.begin(115200);

    // configurando o modo de operação do WiFi como estação
    WiFi.mode(WIFI_STA);

    // desconecta do access point caso ele já esteja conectado
    WiFi.disconnect(); //WIFI_STA é uma constante que indica o modo estação
    delay(100);

//    Serial.println("Setup done");
}

void loop()
{
//    Serial.println("scan start");

    //realiza o escaneamento das redes disponíveis
    int n = WiFi.scanNetworks();
    Serial.println("Escaneamento realizado");

    //verifica se encontrou alguma rede
    if (n == 0) {
        Serial.println("Nenhuma rede encontrada");
    } else {
        redeSSID = "";
        intensidadeSinal= -9999;
        Serial.print(n);
        Serial.println(" redes encontradas\n");
        for (int i = 0; i < n; ++i) {
          // imprime no log cada uma das redes encontradas
          Serial.print("SSID: ");
          Serial.println(WiFi.SSID(i)); //nome da rede
          Serial.print("SINAL: ");
          Serial.print(WiFi.RSSI(i)); //intensidade do sinal
          Serial.print("\t\tcanal: ");
          Serial.print((int)WiFi.channel(i));
          Serial.print("\t\tMAC: ");
          Serial.print(WiFi.BSSIDstr(i));
          Serial.println("\n\n");
          
          
       
          if(abs(WiFi.RSSI(i)) < abs(intensidadeSinal))
          {
             intensidadeSinal = WiFi.RSSI(i);
             redeSSID = WiFi.SSID(i);
             Serial.print("REDE COM MELHOR SINAL ENCONTRADA: ( ");
             Serial.print(redeSSID);
             Serial.print(" ) - SINAL : ( ");
             Serial.print(intensidadeSinal );
             Serial.println(" )");
          }                        
         
          delay(10);
        }
    }
    Serial.println("\n------------------------------------------------------------------------------------\n");

    // deixa um intervalo de 10 segundos para fazer um novo escaneamento
    delay(5000);
}

