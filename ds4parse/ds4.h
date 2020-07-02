#include <cassert>
#include <hidapi/hidapi.h>
#include <string>
#include <stdio.h>
#include <cstdint>
#include <cstring>
#include <cmath>
enum e_dpadKeys {N,NE,E,SE,S,SW,W,NW};
typedef enum e_dpadKeys dpadKeys;

enum ds4keys {
    Lx,Ly,
    Rx,Ry,
    TRI,CRC,X,SQR,DPAD,
    keyR3,keyL3,OPTIONS,keySHARE,btnR2,btnL2,keyR1,keyL1,
    L2Val,R2Val
    };

class ds4{
public:
    ds4(int vid, int pid, bool isUSB);
    ~ds4();
    int isPressed(ds4keys key);
    void getDPAD(char* retStr/*return string*/);
    void read();
private:
    int bufLen;
    hid_device* dev;
    void parseBT();
    void parseUSB();
    unsigned char* dataPtr = NULL;
    unsigned char data[12];
    int vid,pid;
    bool isUSB;
    unsigned char dpadBits[4];
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
/*  Returns: 
    -1 if String passed isn't recognized as a valid button on DS4
    0 if String passed wasn't pressed
    1 if String passed was pressed
*/
int ds4::isPressed(ds4keys key){
    switch (key)
    {
    case Lx:
        return this->LX; 
    case Ly:
        return this->LY;
    case Rx:
        return this->RX;
    case Ry:
        return this->RY;
    case TRI:
        return this->tri; 
    case CRC:
        return this->crc;
    case X:
        return this->x;
    case SQR:
        return this->sqr;
    case DPAD:
        return this->dpad;
    case keyR3:
        return this->R3;
    case keyL3:
        return this->L3;
    case OPTIONS:
        return this->OPTS;
    case keySHARE:
        return this->SHARE;
    case btnR2:
        return this->R2;
    case btnL2:
        return this->L2;
    case keyR1:
        return this->R1;
    case keyL1:
        return this->L1;
    case L2Val:
        return this->L2_val;
    case R2Val:
        return this->R2_val;
    default:
        return -1;
    }
}
void ds4::parseBT(){
    this->LX = data[3]; 
    this->LY = data[4];
    this->RX = data[5];
    this->RY = data[6];
    this->tri = ((data[7] & 128) >> 7) == 1 ? 1 : 0;
    this->crc = ((data[7] & 64) >> 6) == 1 ? 1 : 0;
    this->x = ((data[7] & 32) >> 5) == 1 ? 1 : 0;
    this->sqr = ((data[7] & 16) >> 4) == 1 ? 1 : 0;
    /*DPAD Analyzer*/
    dpadBits[3] = (data[7] & 8) >> 3;
    dpadBits[2] = (data[7] & 4) >> 2;
    dpadBits[1] = (data[7] & 2) >> 1;
    dpadBits[0] = (data[7] & 1);
    sprintf(dpadBits_bin,"%d%d%d%d",dpadBits[3],dpadBits[2],dpadBits[1],dpadBits[0]);
    this->dpad = std::stoi(dpadBits_bin,0,2);
    //printf("DPAD BITS:0b%s\tDecimal:%d\n",dpadBits_bin,this->dpad); //convert binary string to decimal
    this->R3 = ((data[8] & 128) >> 7) == 1 ? 1 : 0;
    this->L3 = ((data[8] & 64)>>6) == 1 ? 1 : 0;
    this->OPTS = ((data[8] & 32) >> 5 == 1) ? 1 : 0;
    this->SHARE = ((data[8] & 16) >> 4 == 1) ? 1 : 0;
    this->R2 = ((data[8] & 8) >> 3 == 1) ? 1 : 0;
    this->L2 = ((data[8] & 4) >> 2 == 1) ? 1 : 0;
    this->R1 = ((data[8] & 2) >> 1) == 1 ? 1 : 0;
    this->L1 = ((data[8] & 1) == 1) ? 1 : 0;
    /* Get Bumper Intensity */
    this->L2_val = data[10];
    this->R2_val = data[11];
}
void ds4::parseUSB(){
    printf("USB Parse\n");
    /* Get Axis */
    this->LX = data[1];
    this->LY = data[2];
    this->RX = data[3];
    this->RY = data[4];
    /* Get 4 Fundamentals */
    this->tri = (((data[5] & 128) >> 7) == 1) ? 1 : 0; 
    this->crc = (((data[5] & 64) >> 6) == 1) ? 1 : 0;
    this->x = ((data[5] & 32) >> 5 == 1) ? 1 : 0;
    this->sqr = ((data[5] & 16) >> 4 == 1) ? 1 : 0;
    /*DPAD Analyzer*/
    dpadBits[3] = (data[5] & 8) >> 3;
    dpadBits[2] = (data[5] & 4) >> 2;
    dpadBits[1] = (data[5] & 2) >> 1;
    dpadBits[0] = (data[5] & 1);
    sprintf(dpadBits_bin,"%d%d%d%d",dpadBits[3],dpadBits[2],dpadBits[1],dpadBits[0]);
    this->dpad = std::stoi(dpadBits_bin,0,2);
    //printf("DPAD BITS:0b%s\tDecimal:%d\n",dpadBits_bin,this->dpad); //convert binary string to decimal
    /* Get Others */
    this->R3 = ((data[6] & 128) >> 7 == 1) ? 1 : 0;
    this->L3 = ((data[6] & 64) >> 6 == 1) ? 1 : 0;
    this->OPTS = ((data[6] & 32) >> 5 == 1) ? 1 : 0;
    this->SHARE = ((data[6] & 16) >> 4 == 1) ? 1 : 0;
    this->R2 = ((data[6] & 8) >> 3 == 1) ? 1 : 0;
    this->L2 = ((data[6] & 4) >> 2 == 1) ? 1 : 0;
    this->R1 = ((data[6] & 2) >> 1) == 1 ? 1 : 0;
    this->L1 = ((data[6] & 1) == 1) ? 1 : 0;
    /* Get Bumper Intensity */
    this->R2_val = data[8];
    this->R2_val = data[9];
}
/* Returns 1-2 character string representing direction of DPAD
    -1 should never be returned but who knows 
*/
void ds4::getDPAD(char *retStr){
    switch(this->dpad){
        case 0:
            strcpy(retStr,"N");
            break;
        case 1:
            strcpy(retStr,"NE");
            break;
        case 2:
            strcpy(retStr,"E");
            break;
        case 3:
            strcpy(retStr,"SE");
            break;
        case 4:
            strcpy(retStr,"S");
            break;
        case 5:
            strcpy(retStr,"SW");
            break;
        case 6:
            strcpy(retStr,"W");
            break;
        case 7:
            strcpy(retStr,"NW");
            break;
        default:
            strcpy(retStr,"-1");
            break;
    }
}

void ds4::read(){
    hid_read(dev,dataPtr,bufLen);
    for(int byte=0;byte<bufLen;byte++)
        data[byte] = * (dataPtr+byte);
    (isUSB) ? parseUSB() : parseBT();
}

ds4::ds4(int vid,int pid,bool isUSB){
    this->dpad = -1;
    assert( hid_init() != -1 ); 
    this->vid = vid;
    this->pid = pid;
    this->isUSB = isUSB;
    this->dpadBits_bin = (char *) malloc(sizeof(char)*6);
    bufLen = (isUSB) ? 10 : 12;
    this->dev = hid_open(vid,pid,NULL);
    assert (dev!=NULL);
    hid_set_nonblocking(dev,0);
    this->dataPtr = (unsigned char*) malloc(sizeof(unsigned char)*bufLen);
}
ds4::~ds4(){
    free(dataPtr);
    hid_close(dev);
    hid_exit();
    free(this->dpadBits_bin);
}