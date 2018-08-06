#ifndef MP_MP_0002_H
#define MP_MP_0002_H

#include <Arduino.h>
class MP_MP_0002
{
public:
    MP_MP_0002(uint8_t data, uint8_t clk,const String &tag);

    void init();
    void on(int red, int green, int blue, int brightness);
    void off();

private:
    void startFrame();
    void sendColor(uint8_t red, uint8_t green, uint8_t blue, uint8_t brightness = 31);
    void endFrame(uint16_t count);
    void transfer(uint8_t count);

private:
    uint8_t data;
    uint8_t clk;
    const String tag;
};

#endif
