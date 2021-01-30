/*
 * Programa para testar saídas analógicas do Arduino/ESP8266/ESP32.
 * 
 * Evans Picolo
 * Asthor Barden
 * 
 * jan/2021
 * 
 * INTRUÇÕES:
 *    1. Escolha uma porta que funcione como entrada digital para ser o trigger;
 *    2. Ligue um botão em pulldown na porta do trigger;
 *    3. Insira as portas que serão testadas no vetor port[].
 *    4. Grave o código;
 *    5. Abra o Serial Monitor;
 *    6. Ligue um LED na porta indicada;
 *    7. Observe se o LED está variando o brilho gradualmente;
 *    8. Aperte o botão para ir pra póxima porta;
 *    9. Repita até os passos 5 a 7 até a última porta.
 */



#define BUTTON 21        // trigger para próxima porta

int cont = 0;          // porta que está sendo testada
bool buttonState;             // leitura do botao

int port[12]={36,39,34,35,32,33,25,26,27,14,12,13,
              15,02,04,16,17,05,18,19,21,03,01,22,23};     // portas que serão testadas
int onTest;

int duty = 0;
int pace = 30;          // Esse valor deve ser divisor de MAX
const int MAX = 1020;   // Esse valor deve ser múltiplo de pace
void trigger()
{
    // Verifica se o botão foi pressionado e avança para próxima porta válida.

    pinMode(BUTTON, INPUT);
    buttonState = digitalRead(BUTTON);
    if(buttonState)
    {
        cont++;
        onTest = port[cont];
        pinMode(onTest, OUTPUT);
        ledcAttachPin(onTest, 0);
        ledcSetup(0, 1000, 10);
        
        Serial.print("D");
        Serial.print(onTest);
        Serial.println();
        
        while(buttonState)
        {
            buttonState = digitalRead(BUTTON);
            delay(200);
        }
    }
}

void setup()
{
    Serial.begin(9600);

    onTest = port[cont];
    pinMode(onTest, OUTPUT);
    ledcAttachPin(onTest, 0);
    ledcSetup(0, 1000, 10);
    
    Serial.println();
    Serial.println("Iniciando teste das saídas analógicas...");
    delay(100);
    Serial.print("D");
    Serial.print(onTest);
    Serial.println();
    
}

void loop()
{
    ledcWrite(0, duty);
    delay(100);
    duty+=pace;

    if(duty>=MAX || duty<=0)
    {
        pace = 0-pace;
    }

    trigger();
}
