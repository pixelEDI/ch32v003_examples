/*
        _          _ ______ _____ _____ 
       (_)        | |  ____|  __ \_   _|
  _ __  ___  _____| | |__  | |  | || |  
 | '_ \| \ \/ / _ \ |  __| | |  | || |  
 | |_) | |>  <  __/ | |____| |__| || |_ 
 | .__/|_/_/\_\___|_|______|_____/_____|
 | |                                    
 |_|                                    
                             
https://links.pixeledi.eu
CH32V003 ADC Test | V1.0 | 07.2023

  pinout
  https://github.com/cnlohr/ch32v003fun

*/

#include <stdio.h>
#include <Arduino.h>

uint8_t adc_pins[] = {
    A2,         // A0
    A1,         // A1
    C4,         // A2
    D2,         // A3
    D3,         // A4
    D5,         // A5
    D6,         // A6
    D4,         // A7
    ADC_CH_REF, // A8
    ADC_CH_CAL, // A9
};

uint8_t potiPin = D6;
int potiVal = 0;

void setup()
{
  Serial.begin(115200);
}

void loop()
{

  potiVal = analogRead(potiPin);
  Serial.print(potiVal);
  Serial.println("  ---------");
  delay(100);
  
}
