#ifndef DS4_H
#define DS4_H

#include <string>
#include <stdio.h>
#include <cstdint>
#include <cstring>
enum e_dpadKeys {N,NE,E,SE,S,SW,W,NW,NO_DPAD};
typedef enum e_dpadKeys dpadKeys;

enum ds4keys {
    Lx,Ly,
    Rx,Ry,
    TRI,CRC,X,SQR,DPAD,
    keyR3,keyL3,OPTIONS,keySHARE,btnR2,btnL2,keyR1,keyL1,
    L2Val,R2Val
};

class DS4{
public:
    DS4();
    ~DS4();
    void read(int isUSB,unsigned char* buff);
    int isPressed(ds4keys key);
    void getDPAD(char* retStr/*return string*/);
private:
    void parseBT();
    void parseUSB();
    unsigned char dpadBits[4];
    unsigned char* data;
    char* dpadBits_bin; 
    /* Data Range 0-255 */
    uint8_t L2_val;
    uint8_t R2_val;
    uint8_t LY;
    uint8_t LX;
    uint8_t RX;
    uint8_t RY;
    uint8_t dpad;
    bool tri;
    bool crc;
    bool x;
    bool sqr;
    bool R3;
    bool L3;
    bool OPTS;
    bool SHARE;
    bool R2;
    bool L2;
    bool R1;
    bool L1;
};

#endif