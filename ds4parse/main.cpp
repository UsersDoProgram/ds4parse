//
//  main.cpp
//  ds4parse
//
//  Created by Robert Hall on 6/26/20.
//  Copyright © 2020 Robert Hall. All rights reserved.
//

#include <iostream>
#include <hidapi/hidapi.h>
#include <cassert>

#define bt_vid 0x054C
#define bt_pid 0x05C4
#define usb_vid 0x054c
#define usb_pid 0x05c4
#define bufLen 64
class ds4{
    ds4(){
        
    }
public:
    void update();
private:
    /* Data Range 0-255 */
    uint8_t L2_val;
    uint8_t R2_val;
    uint8_t LY;
    uint8_t LX;
    uint8_t RX;
    uint8_t RY;
};
int main(int argc, const char * argv[]) {
    // insert code here...
    int res,vid,pid;
    vid = bt_vid;
    pid = bt_pid;
    unsigned char* ds4Data = (unsigned char*) malloc(sizeof(unsigned char)*64);
    unsigned char buff[bufLen];
    res = hid_init();
    assert(res!=-1);
    
    hid_device* ds4_dev = NULL;
    ds4_dev = hid_open(vid,pid,NULL);
    assert(ds4_dev!=NULL);
    
    hid_read(ds4_dev, ds4Data, bufLen);
    std::cout << "Hello, World!\n";
    return 0;
}
