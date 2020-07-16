
#include "mainwindow.h"
#include <QApplication>
#include "DS4.h"
#include "LBL.h"
#include <hidapi/hidapi.h>
#include <cassert>
#include <future>
#include <cstdio>

static void collect(MainWindow* QtWin){
    int res = hid_init();
    assert(res != -1);
    int vid = 0x054C; 
    int pid = 0x05C4;

    hid_device* dev;
    dev = hid_open(vid,pid,NULL);
    assert(dev != NULL);
    short bufLen = 12;
    DS4 ds4Dev;
    unsigned char* data = (unsigned char*) malloc(sizeof(unsigned char)*bufLen);
    printf("Holo\n");
    int c = 0;//Debug int delete this later...
    while(true){
        (c==0) ? printf("1 time\n") : 1; //Debug String... Delete this later.
        c++;
        hid_read(dev,data,bufLen);
        ds4Dev.read(false,data);
        /* Determine if button is pressed or not */
        (ds4Dev.isPressed(TRI)) ? QtWin->vis(triLBL,1) : QtWin->vis(triLBL,0);
        (ds4Dev.isPressed(X)) ? QtWin->vis(xLBL,1) : QtWin->vis(xLBL,0);
        (ds4Dev.isPressed(CRC)) ? QtWin->vis(crcLBL,1) : QtWin->vis(crcLBL,0);
        (ds4Dev.isPressed(SQR)) ? QtWin->vis(sqrLBL,1) : QtWin->vis(sqrLBL,0);
        /* Get DPAD DATA */
        QtWin->vis(DpadLBL,ds4Dev.isPressed(DPAD));
        /* L2 and R2 Intensity */
        QtWin->vis(L2LBL,ds4Dev.isPressed(L2Val));
        QtWin->vis(R2LBL,ds4Dev.isPressed(R2Val));
    }
    hid_set_nonblocking(dev,0);    
}
int main(int argc, char *argv[]){
    std::vector<std::future<void>> mFutures;
    QApplication a(argc, argv);
    MainWindow w;
    mFutures.push_back(std::async(std::launch::async,collect,&w));
    w.show();
    return a.exec();
}
