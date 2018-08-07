#ifndef MP_GROVE_113020010_H
#define MP_GROVE_113020010_H

#include <Arduino.h>
#include <SoftwareSerial.h>
#include <ESP8266_Lib.h>

class MP_GROVE_113020010
{
public:
    MP_GROVE_113020010(uint8_t rx, uint8_t tx, char auth[], char ssid[], char pass[]);

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
    SoftwareSerial espSerial;
    ESP8266 wifi;
    char* auth;
    char* ssid;
    char* pass;

    unsigned long lastSendMillis;   // time of the last time we send some data to blynk server
};

#endif
