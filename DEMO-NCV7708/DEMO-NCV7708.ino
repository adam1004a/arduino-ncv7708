/*
   
    GPIO  ESP32-SPI2   ESP32-SPI3   | NodeMCU  Name  |   Uno
   ==========================================================
                 15       5         |  D8       SS   |   D10
                 13      23         |  D7      MOSI  |   D11
                 12      19         |  D6      MISO  |   D12
                 14      18         |  D5      SCK   |   D13

   EPS32 - edit ncv7708 and change SPI.begin in void wysylka()
*/
     
#include <NCV7708.h>
// the setup function runs once when you press reset or power the board
NCV7708 ster(D8);
void setup() {
  
}

// the loop function runs over and over again until power down or reset
void loop() {
  ster.silnik_prawo(1);
  ster.silnik_prawo(2);
  ster.silnik_prawo(3);
  delay(10000);
  ster.silnik_lewo(1);
  ster.silnik_lewo(2);
  ster.silnik_lewo(3);
  delay(10000);
  ster.silnik_stop(1);
  ster.silnik_stop(2);
  ster.silnik_stop(3);
  delay(10000);
  
}
