/*
  BM71.h - Arduino library for the BM71 Bluetooth Low Energy (BLE) module from Microchip Technology.
  Created by Leonardo Marquez, September 10, 2020.
*/

#ifndef BM71_h
#define BM71_h

#include "Arduino.h"

#define MAX_MSG_LEN 60

class BM71
{
  public:
    void setBaud(long baud);
    void readLocalInfo();
    
    byte macAddress[6] = {0, 0, 0, 0, 0};
    String firmVersion;
};



#endif //BM71_h