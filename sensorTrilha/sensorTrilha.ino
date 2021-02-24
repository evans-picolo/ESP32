/*
 * SENSOR DE TRILHA
 * 
 * Código para detectar a faixa em robôes seguidores de faixa
 * 
 * Evans Picolo
 * Asthor Barden
 * fev/2021
 * 
 * 
 */


#define SENSOR_ESQUERDA A0
#define SENSOR_DIREITA  A6

int leituraDireita, leituraEsquerda;

void setup() 
{
    Serial.begin(9600);
    
    pinMode(SENSOR_ESQUERDA, INPUT);
    pinMode(SENSOR_DIREITA, INPUT);

}

void loop() 
{
    leituraDireita = analogRead(SENSOR_DIREITA);
    leituraEsquerda = analogRead(SENSOR_ESQUERDA);

    Serial.print(leituraEsquerda);
    Serial.print("\t");
    Serial.print(leituraDireita);
    Serial.print("\t");

    /*
     0 = Sensor fora da faixa / Motor desligado
     1 = Sensor na faixa / Motor ligado
    
     Se | Sd | Me | Md
     0  | 0  | 1  | 1 
     0  | 1  | 1  | 0
     1  | 0  | 0  | 1
     1  | 1  | 0  | 0

    Md = Sd'
    
    Me = Se'

    *Obs: Note que estou utilizando um sensor analógico, 
    então a variável leitura guarda um valor inteiro, em que
    "0" representa "Fora da faixa" e ">0" representa "Na faixa".
    Por isso, é necessário utilizar um "if" ao invés de simplesmente
    jogar o valor direto da variável para o motor correspondente.
    Se estivesse utilizando um sensor digital, isso seria possível.
    
    */

    
    if(leituraDireita == 0)
    {
        Serial.print("DIREITO");
        Serial.print("\t");
    }

    if(leituraEsquerda == 0)
    {
        Serial.print("ESQUERDO");
        Serial.print("\t");
    }

    Serial.println();

    delay(200);

}
