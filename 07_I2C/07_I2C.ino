/*
        _          _ ______ _____ _____ 
       (_)        | |  ____|  __ \_   _|
  _ __  ___  _____| | |__  | |  | || |  
 | '_ \| \ \/ / _ \ |  __| | |  | || |  
 | |_) | |>  <  __/ | |____| |__| || |_ 
 | .__/|_/_/\_\___|_|______|_____/_____|
 | |                                    
 |_|  
www.pixeledi.eu | https://links.pixeledi.eu
CH32v003 I2C mit BH1750 | V1.0 | 03.2024

CH32v003A4M6
                      +---------+
    SDA BH1750    PC1 |1     16| PC0
    SCL BH1750    PC2 |2     15| VDD
                  PC3 |3     14| VSS
                  PC4 |4     13| PA2
                  PC6 |5     12| PA1
                  PC7 |6     11| PD7
    SWIO          PD1 |7     10| PD6
                  PD4 |8      9| PD5   RX LinkE
                      +---------+



1011100 1 ACK HIGH BYTE ACK low byte
in Pulseview Aufnahme kommt bei highbyte = 36
36 / 1,2 (lt Datensheet) = 30 lux


Bei 00000001 und 00010000
(1 x 256) + 16
272 / 1,2 = 227

*/
#include "hal/wch-hal-i2c.h"

int BH1750address = 0x23; // I2C address
byte buff[2];
unsigned long previousMillis = millis();
uint8_t read_data[10] = { 0 };


void setup()
{
  Serial.begin(115200);
  // Initialize I2C
  i2c_init(80000, I2C_DutyCycle_16_9, 0x02, I2C_Ack_Enable, I2C_AcknowledgedAddress_7bit);
  Serial.println("setup finished");
}

void loop()
{

  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= (3000 * 1))
  {
    previousMillis = currentMillis;

    uint8_t dataToSend1 = 0x10;// 1lx reolution 120ms H-Resolution Mode Seite 5
    i2c_write(BH1750address, &dataToSend1, 1);
    delay(200);

    i2c_read(BH1750address, buff, 2);

    Serial.print(buff[0], BIN); // MSB
    Serial.print(" | ");
    Serial.print(buff[1], BIN); // LSB

    Serial.println();

    // Seite 7 - Berechnung der Beleuchtungsstärke
    // (MSB x 256 + LSB) / 1.2 --> ergibt die nächste Zeile
    int val = ((buff[0] << 8) | buff[1]) / 1.2;

    Serial.print(val);
    Serial.println("lx");
  }
}
