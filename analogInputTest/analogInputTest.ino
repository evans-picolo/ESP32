/*
 * Programa para testar entradas analogicas do Arduino/ESP8266/ESP32.
 * 
 * Evans Picolo
 * Asthor Barden
 * 
 * jan/2021
 * 
 * INTRUÇÕES:
 *    1. Escolha uma porta que funcione como entrada digital para ser o trigger;
 *    2. Ligue um botão em pulldown na porta do trigger;
 *    3. Identifique a porta que possui um LED integrado e configure no código;
 *    4. Insira as portas que serão testadas no vetor port[];
 *    5. Grave o código;
 *    6. Abra o Serial Monitor;
 *    7. Ligue um botão com pulldown na porta indicada;
 *    8. Prtessione o botão e observe se o LED integrado (D2) responde;
 *    9. Aperte o botão para ir pra póxima porta;
 *   10. Repita até os passos 5 a 7 até a última porta.
 *    
 * OBSERVAÇÕES: 
 *    - A porta que possue o LED integrado deve ser testada separadamente.
 *    
 */


#define BUTTON 21        // trigger para próxima porta

int cont = 0;          // porta que está sendo testada
bool buttonState;             // leitura do botao

int port[12]={36,39,34,35,32,33,25,26,27,14,12,13,
              15,02,04};                              // portas que serão testadas
int onTest;                                          // porta em teste 

unsigned const int DEBOUNCE_TIME = 100;   // ms
unsigned const int READ_TIME = 500;       // ms

void trigger()
{
    // Verifica se o botão foi pressionado e avança para a próxima porta.

    pinMode(BUTTON, INPUT);
    buttonState = digitalRead(BUTTON);
    if(buttonState)
    {
        cont++;
        onTest = port[cont];
        pinMode(onTest, INPUT);
        
        Serial.println();
        Serial.print("D");
        Serial.print(onTest);
        Serial.println();
        
        
        while(buttonState)
        {
            buttonState = digitalRead(BUTTON);
            delay(DEBOUNCE_TIME);
        }
    }
}

void setup()
{
    Serial.begin(9600);
    
    onTest = port[cont];
    pinMode(onTest, INPUT);
    
    Serial.println();
    Serial.println("Iniciando teste das entradas analógicas...");
    delay(100);
    Serial.print("D");
    Serial.print(onTest);
    Serial.println();
    
}

void loop()
{
    Serial.println(analogRead(onTest));
    trigger();
    delay(READ_TIME);
    
    
}
