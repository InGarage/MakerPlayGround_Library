#include "MP_MP_0002.h"

MP_MP_0002::MP_MP_0002(uint8_t data, uint8_t clk,const String &tag)
    : data(data)
    , clk(clk)
    , tag(tag)
{
}

void MP_MP_0002::init() 
{
    digitalWrite(data, LOW);
    pinMode(data, OUTPUT);
    digitalWrite(clk, LOW);
    pinMode(clk, OUTPUT);
}

void MP_MP_0002::on(int red, int green, int blue, int brightness)
{
    startFrame();
    sendColor(red, green, blue, ((float) brightness / 100.0) * 31);
    endFrame(1);
}

void MP_MP_0002::startFrame()
{
    digitalWrite(data, LOW);
    digitalWrite(clk, LOW);
    transfer(0);
    transfer(0);
    transfer(0);
    transfer(0);
}

void MP_MP_0002::sendColor(uint8_t red, uint8_t green, uint8_t blue, uint8_t brightness)
{
    transfer(0b11100000 | brightness);
    transfer(blue);
    transfer(green);
    transfer(red);
}

void MP_MP_0002::endFrame(uint16_t count)
{
    transfer(0xFF);
    for (uint16_t i = 0; i < 5 + count / 16; i++)
    {
        transfer(0);
    }
}

void MP_MP_0002::transfer(uint8_t b)
{
    digitalWrite(data, b >> 7 & 1);
    digitalWrite(clk, HIGH);
    digitalWrite(clk, LOW);
    digitalWrite(data, b >> 6 & 1);
    digitalWrite(clk, HIGH);
    digitalWrite(clk, LOW);
    digitalWrite(data, b >> 5 & 1);
    digitalWrite(clk, HIGH);
    digitalWrite(clk, LOW);
    digitalWrite(data, b >> 4 & 1);
    digitalWrite(clk, HIGH);
    digitalWrite(clk, LOW);
    digitalWrite(data, b >> 3 & 1);
    digitalWrite(clk, HIGH);
    digitalWrite(clk, LOW);
    digitalWrite(data, b >> 2 & 1);
    digitalWrite(clk, HIGH);
    digitalWrite(clk, LOW);
    digitalWrite(data, b >> 1 & 1);
    digitalWrite(clk, HIGH);
    digitalWrite(clk, LOW);
    digitalWrite(data, b >> 0 & 1);
    digitalWrite(clk, HIGH);
    digitalWrite(clk, LOW);
}

void MP_MP_0002::off()
{
    startFrame();
    sendColor(0, 0, 0, 0);
    endFrame(1);
}
