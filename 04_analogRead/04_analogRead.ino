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
CH32v003 AnalogRead | V1.0 | 03.2024

# ADC Enable
  Stand 1.0.4 CH32 MCU EVT Boards muss ADC aktiviert werden
  * https://github.com/openwch/arduino_core_ch32/issues/43
  * https://github.com/openwch/arduino_core_ch32/blob/4b3d37e537fa9a68032419864c224d641c72feec/variants/CH32V00x/CH32V003F4/variant_CH32V003F4.h#L16

  on linux
  * home/yourusername/.arduino15/packages/WCH/hardware/ch32v/1.0.4/variants/CH32V00x/CH32V003F4


# CH32v003F4P6 / WCH Core

                        +---------+
                    PD4 1      20 PD3
        RX LinkEP   PD5 2      19 PD2
                    PD6 3      18 PD1 -> SWIDO LinkE
                    PD7 4      17 PC7 
                    PA1 5      16 PC6
                    PA2 6      15 PC5
                    VSS 7      14 PC4/A2 -> Poti
                    PD0 8      13 PC3
                    VDD 9      12 PC2
                    PC0 10     11 PC1 
                        +---------+

# ADC 
  * 10 Bit Auflösung von ADC = 2¹⁰ = 1024
 
*/

int poti = A2; 

void setup() {
  Serial.begin(115200);
  pinMode(poti, INPUT);
  pinMode(led, OUTPUT);
  Serial.println("Messung startet:");
}

void loop() {
  int val = analogRead(poti);
  Serial.println(val);
}
