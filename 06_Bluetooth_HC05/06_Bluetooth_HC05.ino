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
Bluetooth with CH32v003 | V1.0 | 03.2024


                 +---------+
TX HC05-> RX/PD6 |1      8| PD4  SWDIO & RX von LINK-E
             VSS |2      7| PC4
             PA2 |3      6| PC2
             VDD |4      5| PC1 LED -> 220ohm -> GND
                 +---------+

*/

byte led = C1;


void setup() {
  Serial.begin(9600);
  pinMode(led, OUTPUT);

}

void loop() {

  static char buffer[64];  // Create a character buffer to store incoming data
  static int index = 0;    // Index to keep track of the buffer position

  while (Serial.available()) {
    char incomingChar = Serial.read();

    Serial.print(incomingChar);
    if (incomingChar == '\n') {
      // End of message reached, check if it contains "heyho"
      buffer[index] = '\0';  // Null-terminate the buffer
      if (strstr(buffer, "on") != NULL) {
        digitalWrite(led, HIGH);
      } else if (strstr(buffer, "off") != NULL) {
        digitalWrite(led, LOW);
      }

      // Reset the buffer and index for the next message
      memset(buffer, 0, sizeof(buffer));
      index = 0;
    } else {
      // Add the character to the buffer
      buffer[index] = incomingChar;
      index++;

      // Check for buffer overflow
      if (index >= sizeof(buffer)) {
        // Buffer is full, reset it
        memset(buffer, 0, sizeof(buffer));
        index = 0;
      }
    }
  }
}
