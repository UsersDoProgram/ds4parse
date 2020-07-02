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
    printf("DS4 BT ADDR:%s\n","1C:96:5A:67:BC:7F");
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

    int vid,pid;
    vid = (isUSB) ? usb_vid : bt_vid;
    pid = (isUSB) ? usb_pid : bt_pid;
    printf("VID:0x%X \tPID:0x%X\tMode:%s\n",vid,pid,
    (isUSB) ? (const char *)"USB" : (const char *)"Bluetooth");
    /* Analysis */
    ds4 myds4(vid,pid,isUSB);
    myds4.read();
    printf("△: %s\t\tO: %s\t\tX: %s\t\t□: %s\n", 
    (myds4.isPressed(TRI)) ? "true" : "false", (myds4.isPressed(CRC) == 1) ? "true" : "false",
    (myds4.isPressed(X)) ? "true" : "false", (myds4.isPressed(SQR) == 1) ? "true" : "false");

    char* dpadStr = (char *) malloc(sizeof(char)*2);
    myds4.getDPAD(dpadStr);
    printf("DPAD:%s\n",dpadStr);

    return 0;
}
