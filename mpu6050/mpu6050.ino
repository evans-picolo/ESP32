/*
 * MPU-6050
 * 
 * Código para ler os valores do chip MPU-6050 (acel/giro/temp) e escrever 
 * no Monitor Serial.
 * 
 * Evans Picolo
 * Asthor Barden
 * fev/2021
 * 
 * Baseado no código do Filipe Flop
 * https://www.filipeflop.com/blog/tutorial-acelerometro-mpu6050-arduino/
 *    
 */

//Carrega a biblioteca Wire
#include<Wire.h>

//Endereco I2C do MPU6050
const int MPU = 0x68;  

//Variaveis para armazenar valores dos sensores
int AcX,AcY,AcZ,Tmp,GyX,GyY,GyZ;


void setup()
{
    // Inicializa comunicação serial
    Serial.begin(9600);
  
    // Inicializa comunicação I2C
    Wire.begin();
  
    //Inicializa o MPU-6050
    Wire.beginTransmission(MPU);
    Wire.write(0x6B);
    Wire.write(0); 
    Wire.endTransmission(true);

}


void loop()
{
    // Envia endereço do primeiro registrador a ser lido
    Wire.beginTransmission(MPU);
    Wire.write(0x3B);  // starting with register 0x3B (ACCEL_XOUT_H)
    Wire.endTransmission(false); 
  
    // Solicita os dados do sensor
    Wire.requestFrom(MPU,14,true);
    
    // Armazena o valor dos sensores nas variaveis correspondentes
    AcX = Wire.read() <<8 |Wire.read();  //0x3B (ACCEL_XOUT_H) & 0x3C (ACCEL_XOUT_L)     
    AcY = Wire.read() <<8 |Wire.read();  //0x3D (ACCEL_YOUT_H) & 0x3E (ACCEL_YOUT_L)
    AcZ = Wire.read() <<8 |Wire.read();  //0x3F (ACCEL_ZOUT_H) & 0x40 (ACCEL_ZOUT_L)
    Tmp = Wire.read() <<8 |Wire.read();  //0x41 (TEMP_OUT_H) & 0x42 (TEMP_OUT_L)
    GyX = Wire.read() <<8 |Wire.read();  //0x43 (GYRO_XOUT_H) & 0x44 (GYRO_XOUT_L)
    GyY = Wire.read() <<8 |Wire.read();  //0x45 (GYRO_YOUT_H) & 0x46 (GYRO_YOUT_L)
    GyZ = Wire.read() <<8 |Wire.read();  //0x47 (GYRO_ZOUT_H) & 0x48 (GYRO_ZOUT_L)
   
    // Escreve valores no serial
    Serial.print("AcX = ");    Serial.print(AcX);
    Serial.print(" | AcY = "); Serial.print(AcY);
    Serial.print(" | AcZ = "); Serial.print(AcZ);
    Serial.print(" | Tmp = "); Serial.print(Tmp/340.00+36.53);
    Serial.print(" | GyX = "); Serial.print(GyX);
    Serial.print(" | GyY = "); Serial.print(GyY);
    Serial.print(" | GyZ = "); Serial.print(GyZ);
    Serial.println();

    // Delay para estabilização
    //delay(300);
  
}
