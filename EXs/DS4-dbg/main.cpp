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
#include "DS4.h"


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

    int res,vid,pid;
    vid = (isUSB) ? usb_vid : bt_vid;
    pid = (isUSB) ? usb_pid : bt_pid;
    int bufLen = (isUSB) ? 10 : 12;
    unsigned char* dPoint = (unsigned char*) malloc(sizeof(unsigned char)*bufLen);
    hid_device* ds4Dev;

    res = hid_init();
    assert(res!=-1);

    printf("VID:0x%X \tPID:0x%X\tMode:%s\n",vid,pid,
    (isUSB) ? (const char *)"USB" : (const char *)"Bluetooth");

    ds4Dev = hid_open(vid,pid,NULL);
    hid_set_nonblocking(ds4Dev,0);
    hid_read(ds4Dev,dPoint,bufLen);
    /* Initialize Array From Data Pointer */


    /* Analysis */
    DS4 myds4;
    myds4.read(isUSB,dPoint);

    printf("△: %s\t\tO: %s\t\tX: %s\t\t□: %s\n", 
    (myds4.isPressed(TRI)) ? "true" : "false", (myds4.isPressed(CRC) == 1) ? "true" : "false",
    (myds4.isPressed(X)) ? "true" : "false", (myds4.isPressed(SQR) == 1) ? "true" : "false");

    printf("R2:%u\tL2:%u\n",(unsigned int)myds4.isPressed(R2Val),(unsigned int)myds4.isPressed(L2Val));
    char* dpadStr = (char *) malloc(sizeof(char)*2);
    myds4.getDPAD(dpadStr);
    printf("DPAD:%s,%d\n",dpadStr,myds4.isPressed(DPAD));
    
    free(dPoint);
    hid_close(ds4Dev);
    hid_exit();
    return 0;
    /* Add Serialization via JSON or Protobuff for sending through sockets*/
    /* Determine a GUI */
}
