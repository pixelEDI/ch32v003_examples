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
CH32v003 UART mit Arduino UNO | V1.0 | 03.2024

CH32v003J4M6

              +---------+
          PD6 |1      8| PD4 Uno RX // SWDIO & RX von LINK-E
Uno GND-> VSS |2      7| PC4
          PA2 |3      6| PC2
          VDD |4      5| PC1 
              +---------+
*/

void setup()
{
  Serial.begin(9600);
}

void loop() {

  Serial.println("Hallo von CH32v003!"); 
  delay(500);

}
