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
          PD6 |1      8| PD4 UNO RX // SWDIO & RX von LINK-E
Uno GND-> VSS |2      7| PC4
          PA2 |3      6| PC2
          VDD |4      5| PC1 
              +---------+
*/

#include <SoftwareSerial.h>
SoftwareSerial mySerial(2,3); // RX, TX


void setup() {
  mySerial.begin(9600);
  Serial.begin(9600);
}

void loop() {
  if(mySerial.available()){
    String receiveData = mySerial.readStringUntil('\n');
    Serial.println(receiveData);
  }
}





