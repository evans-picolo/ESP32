/*
 * Programa para testar saídas digitais do Arduino/ESP8266/ESP32.
 * 
 * Evans Picolo
 * Asthor Barden
 * 
 * jan/2021
 * 
 * INTRUÇÕES:
 *    1. Escolha um porta que funcione como entrada digital para ser o trigger;
 *    2. Ligue um botão em pulldown na porta do trigger;
 *    3. Insira as portas que serão testadas no vetor port[].
 *    4. Insira a porta que será usada como trigger na #define TRIGGER.
 *    5. Grave o código;
 *    6. Abra o Serial Monitor;
 *    7. Ligue um LED na porta indicada;
 *    8. Observe se o LED está piscando;
 *    9. Aperte o botão para ir pra póxima porta;
 *   10. Repita até os passos 7 a 9 até a última porta.
 */


#define BUTTON 21        // trigger para próxima porta

int cont = 0;          // porta que está sendo testada
bool buttonState;             // leitura do botao

int port[12]={36,39,34,35,32,33,25,26,27,14,12,13,
              15,02,04,16,17,05,18,19,21,03,01,22,23};     // portas que serão testadas
int onTest;                                          // porta em teste 

unsigned const int BLINK_TIME = 250;      // ms
unsigned const int DEBOUNCE_TIME = 100;   // ms

void trigger()
{
    // Verifica se o botão foi pressionado e avança para a próxima porta.

    pinMode(BUTTON, INPUT);
    buttonState = digitalRead(BUTTON);
    if(buttonState)
    {
        cont++;
        onTest = port[cont];
        pinMode(onTest, OUTPUT);
        
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
    pinMode(onTest, OUTPUT);
    
    Serial.println();
    Serial.println("Iniciando teste das saídas digitais...");
    delay(100);
    Serial.print("D");
    Serial.print(onTest);
    Serial.println();
    
}

void loop()
{
    digitalWrite(onTest, HIGH);
    delay(BLINK_TIME);
    digitalWrite(onTest, LOW);
    delay(BLINK_TIME);

    trigger();
}
