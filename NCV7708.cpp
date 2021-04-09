

#include "NCV7708.h"
#include "arduino.h"
#include <SPI.h>




NCV7708::NCV7708(uint8_t _SS,uint8_t plytka)
{
    SS = _SS;
    pinMode(SS, OUTPUT);
    digitalWrite(SS, HIGH); //csb
    _plytka = plytka;
}
void NCV7708::silnik_prawo(uint8_t numer_silnika)
{
    silnik_start(numer_silnika, prawo);
}

void NCV7708::silnik_lewo(uint8_t numer_silnika)
{
    silnik_start(numer_silnika, lewo);
}

void NCV7708::silnik_stop(uint8_t numer_silnika)
{
    silnik_start(numer_silnika, stac);
}

void NCV7708::silnik_start(uint8_t numer_silnika, uint16_t maska)
{
    
    switch (numer_silnika)
    {
    case 1:
        // ustawianie bitów silnika na 1
        silnik |= (1 << 14);
        silnik |= (1 << 13);
        silnik |= (1 << 12);
        silnik |= (1 << 11);
        silnik = silnik ^ maska;
        wysylka();
     break;
    case 2:
        // ustawianie bitów silnika na 2
        silnik |= (1 << 10);
        silnik |= (1 << 9);
        silnik |= (1 << 8);
        silnik |= (1 << 7);
        maska = (maska >> 4);
        silnik = silnik ^ maska;
        wysylka();
        break;
    case 3:
        // ustawianie bitów silnika na 3
        silnik |= (1 << 6);
        silnik |= (1 << 5);
        silnik |= (1 << 4);
        silnik |= (1 << 3);
        maska = (maska >> 8);
        silnik = silnik ^ maska;
        wysylka();
        break;

    }

    
}



void NCV7708::wysylka()
{
    if (_plytka == 1)
    {
        SPI.begin(14, 12, 13, SS);//SCK,MISO,MOSI,ss 
        SPI.setClockDivider(SPI_CLOCK_DIV32);
        SPI.setDataMode(SPI_MODE1);
        SPI.setBitOrder(MSBFIRST);
        digitalWrite(SS, LOW);
        SPI.transfer16(silnik);
        digitalWrite(SS, HIGH);
        SPI.end();
    }

    else
    {
        pinMode(SS, OUTPUT);
        digitalWrite(SS, HIGH);
        SPI.begin();
        SPI.beginTransaction(SPISettings(1000000, MSBFIRST, SPI_MODE1));
        digitalWrite(SS, LOW);
        SPI.transfer16(silnik);
        digitalWrite(SS, HIGH);
        SPI.end();
    }
    
}



