/*
 * Let It Go
 * 
 * Código para tocar o refrao da música Let It Go com um Buzzer. 
 * 
 * Evans Picolo
 * Asthor Barden
 * ago/2021
 * 
 */

// ===== BIBLIOTECAS ==============================================================================================

#include "ESP32Servo.h"     // Comandos de frequência para produzir as notas -- tone() e noTone()


// ===== MAPA DE PORTAS ===========================================================================================

#define BEEP  12      // Porta do beep


// ===== VARIÁVEIS GLOBAIS ========================================================================================

int tempo;    // Tempo da musica (quanto maior a valor, mais lento e vice-versa)


// ===== CONFIGURAÇÕES INICIAIS ==================================================================================

void setup()
{
    pinMode(BEEP, OUTPUT);

    tempo = 1800;     // Quanto maior o valor, mais lenta a música

    F4(8); G4(8); GS4(2); pausa(8); DS4(8); DS4(8); AS4(2); pausa(4); 
    
    GS4(4); F4(8); F4(8); F4(4); F4(4); G4(8); GS4(2); pausa(8);

    F4(8); G4(8); GS4(2); pausa(8); DS4(8); C5(8); C5(4); AS4(2);

    GS4(8); AS4(8); C5(4); C5(8); CS5(4); C5(4); AS4(4); GS4(2); pausa(4);

    DS5(4); DS5(8); C5(4); C5(8); AS4(2); 
    
    GS4(4); GS4(8); GS4(8); DS5(4); DS5(8); C5(4); C5(8); GS4(2); pausa(8);

    GS4(8); GS4(8); G4(4); G4(8); DS4(4); DS4(8); DS4(2); pausa(4); 

    C5(8); CS5(4); CS5(8); CS5(8); CS5(8); CS5(8); C5(8); CS5(8); C5(8); GS4(2); 
}


// ===== PROGRAMA PRINCIPAL ======================================================================================

void loop()
{
    // Nada a ser feito aqui...
}


// ===== FUNÇÕES AUXILIARES ======================================================================================

void pausa(int duracao)
{
    float x = tempo / duracao;
    noTone(BEEP);
    delay(x);
}

void C4(int duracao)
{
    float x = tempo / duracao;
    tone(BEEP, 262, x);
    noTone(BEEP);
    delay(x/10);
}

void CS4(int duracao)
{
    float x = tempo / duracao;
    tone(BEEP, 277, x);
    noTone(BEEP);
    delay(x/10);
}

void D4(int duracao)
{
    float x = tempo / duracao;
    tone(BEEP, 294, x);
    noTone(BEEP);
    delay(x/10);
}

void DS4(int duracao)
{
    float x = tempo / duracao;
    tone(BEEP, 311, x);
    noTone(BEEP);
    delay(x/10);
}

void E4(int duracao)
{
    float x = tempo / duracao;
    tone(BEEP, 330, x);
    noTone(BEEP);
    delay(x/10);
}

void F4(int duracao)
{
    float x = tempo / duracao;
    tone(BEEP, 349, x);
    noTone(BEEP);
    delay(x/10);
}

void FS4(int duracao)
{
    float x = tempo / duracao;
    tone(BEEP, 370, x);
    noTone(BEEP);
    delay(x/10);
}

void G4(int duracao)
{
    float x = tempo / duracao;
    tone(BEEP, 392, x);
    noTone(BEEP);
    delay(x/10);
}

void GS4(int duracao)
{
    float x = tempo / duracao;
    tone(BEEP, 415, x);
    noTone(BEEP);
    delay(x/10);
}

void a4(int duracao)    // "A4" maisculo ja esta sendo usado pela biblioteca para outra coisa
{
    float x = tempo / duracao;
    tone(BEEP, 440, x);
    noTone(BEEP);
    delay(x/10);
}

void AS4(int duracao)
{
    float x = tempo / duracao;
    tone(BEEP, 466, x);
    noTone(BEEP);
    delay(x/10);
}

void B4(int duracao)
{
    float x = tempo / duracao;
    tone(BEEP, 494, x);
    noTone(BEEP);
    delay(x/10);
}

void C5(int duracao)
{
    float x = tempo / duracao;
    tone(BEEP, 523, x);
    noTone(BEEP);
    delay(x/10);
}

void CS5(int duracao)
{
    float x = tempo / duracao;
    tone(BEEP, 554, x);
    noTone(BEEP);
    delay(x/10);
}

void D5(int duracao)
{
    float x = tempo / duracao;
    tone(BEEP, 587, x);
    noTone(BEEP);
    delay(x/10);
}

void DS5(int duracao)
{
    float x = tempo / duracao;
    tone(BEEP, 622, x);
    noTone(BEEP);
    delay(x/10);
}

void E5(int duracao)
{
    float x = tempo / duracao;
    tone(BEEP, 659, x);
    noTone(BEEP);
    delay(x/10);
}

void F5(int duracao)
{
    float x = tempo / duracao;
    tone(BEEP, 698, x);
    noTone(BEEP);
    delay(x/10);
}

void FS5(int duracao)
{
    float x = tempo / duracao;
    tone(BEEP, 734, x);
    noTone(BEEP);
    delay(x/10);
}

void G5(int duracao)
{
    float x = tempo / duracao;
    tone(BEEP, 784, x);
    noTone(BEEP);
    delay(x/10);
}

void GS5(int duracao)
{
    float x = tempo / duracao;
    tone(BEEP, 831, x);
    noTone(BEEP);
    delay(x/10);
}

void a5(int duracao)      // "A5" maisculo ja esta sendo usado pela biblioteca para outra coisa
{
    float x = tempo / duracao;
    tone(BEEP, 880, x);
    noTone(BEEP);
    delay(x/10);
}

void AS5(int duracao)
{
    float x = tempo / duracao;
    tone(BEEP, 932, x);
    noTone(BEEP);
    delay(x/10);
}

void B5(int duracao)
{
    float x = tempo / duracao;
    tone(BEEP, 988, x);
    noTone(BEEP);
    delay(x/10);
}
