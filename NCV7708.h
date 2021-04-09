
#include "arduino.h"
#include <SPI.h>
#ifndef _NCV7708_h
#define _NCV7708_h


class NCV7708
{
public:
    NCV7708(uint8_t _SS, uint8_t plytka);
    uint16_t silnik = 0b1000000000000000;
    void begin();
    void silnik_prawo(uint8_t numer_silnika);
    void silnik_lewo(uint8_t numer_silnika);
    void silnik_stop(uint8_t numer_silnika);
#define ESP32 1
#define ESP8266 2
#define UNO 3
private:
    uint8_t SS;
    uint8_t _plytka;
#define prawo 0b100100000000000
#define lewo 0b011000000000000
#define stac 0b111100000000000
    void silnik_start(uint8_t numer_silnika, uint16_t maska);
    void wysylka();
};


#endif
