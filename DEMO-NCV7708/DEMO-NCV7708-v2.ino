/*
   
    GPIO  ESP32-SPI2   ESP32-SPI3   | NodeMCU  Name  |   Uno
   ==========================================================
                 15       5         |  D8       SS   |   D10
                 13      23         |  D7      MOSI  |   D11
                 12      19         |  D6      MISO  |   D12
                 14      18         |  D5      SCK   |   D13

   
*/
     
#include <NCV7708.h>
// the setup function runs once when you press reset or power the board
NCV7708 ster(15,ESP32); //ESP32 - only SPI2, UNO, ESP8266 for UNO NCV7708 ster(15,UNO) ster(15,ESP8266)or ;
NCV7708 ster1(19,ESP32);
NCV7708 ster2(27,ESP32);
void setup() {
 
}

// the loop function runs over and over again until power down or reset
void loop() {
  ster.silnik_prawo(1);
  ster.silnik_prawo(2);
  ster.silnik_prawo(3);
  ster1.silnik_prawo(1);
  ster1.silnik_prawo(2);
  ster1.silnik_prawo(3);

   ster2.silnik_prawo(1);
  ster2.silnik_prawo(2);
  ster2.silnik_prawo(3);
  delay(10000);
  ster.silnik_lewo(1);
  ster.silnik_lewo(2);
  ster.silnik_lewo(3);
  ster1.silnik_lewo(1);
  ster1.silnik_lewo(2);
  ster1.silnik_lewo(3);
  delay(10000);
  ster.silnik_stop(1);
  ster.silnik_stop(2);
  ster.silnik_stop(3);
  ster1.silnik_lewo(1);
  ster1.silnik_lewo(2);
  ster1.silnik_lewo(3);
  delay(10000);
  
}
