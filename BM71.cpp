/*
  BM71.c - Arduino library for the BM71 Bluetooth Low Energy (BLE) module from Microchip Technology.
  Created by Leonardo Marquez, September 12, 2020.
*/

#include "BM71.h"

void BM71::setBaud(long baud)
{
  Serial1.begin(baud);
}

void BM71::readLocalInfo()
{
  byte arr[] = {0xAA, 0x00, 0x01, 0x01, 0xFE};  // Command to send to the BM71
  byte msg[MAX_MSG_LEN];                        // Buffer to store BM71's response
  int msg_len = 0;                              // Var to store length of response
  
  // Send command
  Serial1.write(arr, 5);
  
  // Wait for the first three bytes of response that include response length
  while(Serial1.available() <= 3);
  
  for (int i=0; i<3; i++)
    msg[i] = (byte)Serial1.read();
  
  msg_len = ((msg[1]<<8) | msg[2]);
  
  // Wait for the rest of the message response
  while(Serial1.available() <= msg_len);
  
  // Fill message array
  for (int i=0; i<msg_len; i++) {
    msg[i] = (byte)Serial1.read();
  }
  
  // Getting firmware Version:
  firmVersion = "1.";
  if (msg[4] == 0x06)
    firmVersion += "06";
  else if (msg[4] == 0x11)
    firmVersion += "11";
  else
    firmVersion = "unknown_ver";
  
  // Getting Mac Address:
  for (int i=0; i<6; i++) {
    macAddress[i] = msg[i+7];
  }
  
  
  /*** TO DO: Verify checksum, error codes  ***/
}