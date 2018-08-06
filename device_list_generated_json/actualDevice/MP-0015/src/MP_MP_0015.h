#ifndef MP_MP_0015_H
#define MP_MP_0015_H

#include <Arduino.h>
#include <ESP8266_Lib.h>

class MP_MP_0015 
{
public:
    MP_MP_0015(char auth[], char ssid[], char pass[],const String &tag);

    void init();
    void update(unsigned long time);

    int readVirtualPin(uint8_t pin);   // pin = 0-7
    void writeVirtualPin(char pin[], double value);   // pin = 0-7

    // high level function use by maker playground
    bool checkVirtualPinValue(char pin[], int value);
    int getVirtualPin0();
    int getVirtualPin1();
    int getVirtualPin2();
    int getVirtualPin3();
    int getVirtualPin4();
    int getVirtualPin5();
    int getVirtualPin6();
    int getVirtualPin7();

    // TODO: find alternate implementation as these may be dangerous
    static double value[8];
    static uint8_t valueChanged; // flag indicated that the data has changed

private:
    void wifiInit();
    bool testConnection();

    void ledOn();
    void ledOff();

    String recvString(String target1, String target2, uint32_t timeout);

    ESP8266 wifi;
    char* auth;
    char* ssid;
    char* pass;
    const String tag;

    unsigned long lastSendMillis;   // time of the last time we send some data to blynk server
    unsigned long lastPingMillis;   // time of the last time we ping world's DNS server
};

#endif
