//
//  main.cpp
//  ds4parse
//
//  Created by Robert Hall on 6/26/20.
//  Copyright © 2020 Robert Hall. All rights reserved.
//

#include <iostream>
#include <ctype.h>
#include <hidapi/hidapi.h>
#include <cassert>
#include "ds4.h"


#define bt_vid 0x054C
#define bt_pid 0x05C4
#define usb_vid 0x054C
#define usb_pid 0x05C4
int main(int argc, const char * argv[]) {
    ds4 myds4;
    bool isUSB;
    if (argc > 2 && isdigit(*argv[1]))
    {
        std::cout<< "Provide 0 for USB\nANY other digit for BT..."<<std::endl;
        return -1;
    }
    isUSB = (atoi(argv[1]) == 0) ? true: false; 
    /*
        size of report:
            64 if usb
            28 if bt
        Only 28 bytes of Bluetooth Report are useful
    */

    int bufLen = (isUSB) ? 64 : 28;
    //wchar_t* serial = (wchar_t *)"CUH-ZCT1x";
    int res,vid,pid;
    vid = (isUSB) ? usb_vid : bt_vid;
    pid = (isUSB) ? usb_pid : bt_pid;
    printf("VID:0x%X \tPID:0x%X\nBuffer Length:%d\t Mode:%s\n",vid,pid,bufLen,
    (isUSB) ? (const char *)"USB" : (const char *)"Bluetooth");
    unsigned char* ds4Data = (unsigned char*) malloc(sizeof(unsigned char)*bufLen);
    unsigned char buff[bufLen];
    
    res = hid_init();
    assert(res!=-1);
    
    hid_device* ds4_dev = NULL;
    ds4_dev = hid_open(vid,pid,NULL);
    assert(ds4_dev!=NULL);

    for(int bNum=0;bNum<bufLen;bNum++) //allocate report array
        buff[bNum] = *(ds4Data+bNum);
    
    hid_set_nonblocking(ds4_dev,0);
    hid_read(ds4_dev,ds4Data,bufLen);
    
    if(isUSB)
        myds4.parseUSB(buff);
    else
        myds4.parseBT(buff);

    std::cout << "Tri Pressed: " << myds4.isPressed("tri")<<std::endl;
    free(ds4Data);
    hid_close(ds4_dev);
    res = hid_exit();
    assert(res!=-1);
    
    return 0;
}
