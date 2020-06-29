#include <cstdint>
#include <cstring>
class ds4{
public:
    ds4();
    void parseBT(unsigned char data[28]);
    void parseUSB(unsigned char data[64]);
    bool isPressed(const char * dStr);
private:
    /* Data Range 0-255 */
    uint8_t L2_val;
    uint8_t R2_val;
    uint8_t LY;
    uint8_t LX;
    uint8_t RX;
    uint8_t RY;
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
bool ds4::isPressed(const char* dStr){
    if ( std::strcmp(dStr,"tri") == 0)
        return this->tri;
    return false;
}
void ds4::parseBT(unsigned char data[28]){
    this->LX = data[3]; 
    this->LY = data[4];
    this->RX = data[5];
    this->RY = data[6];
    this->tri = ((data[7] & 128) >> 7) == 1 ? 1 : 0;
    this->crc = ((data[7] & 64) >> 6) == 1 ? 1 : 0;
    this->x = ((data[7] & 32) >> 5) == 1 ? 1 : 0;
    this->sqr = ((data[7] & 16) >> 4) == 1 ? 1 : 0;
    /* Make DPAD Analyzer */
    
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
void ds4::parseUSB(unsigned char data[64]){
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
ds4::ds4(){

}