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
CH32v003J4M6 LED Blink | V1.0 | 03.2024

CH32v003J4M6

     +---------+
 PD6 |1      8| PD4
 VSS |2      7| PC4
 PA2 |3      6| PC2
 VDD |4      5| PC1 --> LED --> Widerstand 220ohm --> GND
     +---------+

*/

int led = C1;

void setup() {
  Serial.begin(115200);
  pinMode(led, OUTPUT);
}

void loop() {
  digitalWrite(led, LOW);
  Serial.println("led aus");
  delay(2000);

	digitalWrite(led, HIGH);
  Serial.println("led an");
	delay(200);
}
