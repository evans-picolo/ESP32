/*
 * Giroscópio
 * 
 * Código para ler ângulos do giroscópio do chip MPU-6050 com a 
 * a biblioteca MPU6050_tockn
 * 
 * Evans Picolo
 * Asthor Barden
 * fev/2021
 * 
 * Baseado no código exemplo da própria biblioteca MPU6050_tockn
 * https://github.com/tockn/MPU6050_tockn
 * 
 * *Obs: A biblioteca MPU6050_tockn pode ser instalada diretamente pelo
 * gerenciador de bibliotecas.
 *    
 */

// Bibliotecas utilizadas
#include <MPU6050_tockn.h>     // Leitura do MPU e conversão para ângulo
#include <Wire.h>              // Comunicação I2C


// Variáveis para guardar os ângulos
int giroX, giroY, giroZ;


// Instancia o giroscópio
MPU6050 mpu6050(Wire);


// Configurações iniciais
void setup() 
{
    // Incializa comunicação serial
    Serial.begin(9600);

    // Inicializa comunicação I2C
    Wire.begin();

    // Inicializa giroscopio
    mpu6050.begin();
    mpu6050.calcGyroOffsets(true);    // Calibração automática
    
}

// Loop infinito
void loop()
{
    // Atualiza dados do giroscópio
    mpu6050.update();

    // Guarda os valores lidos
    giroX = mpu6050.getAngleX();
    giroY = mpu6050.getAngleY();
    giroZ = mpu6050.getAngleZ();

    // Escreve valores no serial
    Serial.print("X = ");
    Serial.print(giroX);
    Serial.print("\t");
    
    Serial.print("Y = ");
    Serial.print(giroY);
    Serial.print("\t");

    Serial.print("Z = ");
    Serial.print(giroZ);
    Serial.println();

    // Delay para facilitar a leitura do monitor serial
    delay(250);
    
}
