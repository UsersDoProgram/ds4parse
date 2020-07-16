#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGraphicsOpacityEffect>
#include <QPixmap>
#include <string>
#include "DS4.h"
#include "LBL.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //ui->headerLbl->setAlignment(Qt::AlignCenter);
    /* Set All Labels that are shown when buttons are pressed to hidden */
    std::vector<QLabel*> labelVec;
    labelVec.push_back(ui->triPix);
    labelVec.push_back(ui->sqrPix);
    labelVec.push_back(ui->xPix);
    labelVec.push_back(ui->crcPix);
    //Set up Label Images
    /*
    for(QLabel* curr: labelVec){
        //https://forum.qt.io/topic/75233/fit-image-into-qlabel/4
        curr->setPixmap(img.scaled(curr->height,curr->width,Qt::KeepAspectRatio));
    }
    */
}
void MainWindow::vis(enum LBL target,int data){
    //Toggle between 'UP' and 'DOWN' for buttons for labels.
    
    switch(target){
        case triLBL:
        if(data)
            ui->triState->setText("DOWN");
        else
            ui->triState->setText("UP");
        break;
        case sqrLBL:
        if(data)
            ui->sqrState->setText("DOWN");
        else
            ui->sqrState->setText("UP");
        break;
        case xLBL:
        if(data)
            ui->xState->setText("DOWN");
        else
            ui->xState->setText("UP");
        break;
        case crcLBL:
        if(data)
            ui->crcState->setText("DOWN");
        else
            ui->crcState->setText("UP");
        break;
        case DpadLBL:
        switch(data){
            case 0:
            dpadBtn = "N";
                break;
            case 1:
            dpadBtn = "NE";
                break;
            case 2:
            dpadBtn = "E";
                break;
            case 3:
            dpadBtn = "SE";
                break;
            case 4:
            dpadBtn = "S";
                break;
            case 5:
            dpadBtn = "SW";
                break;
            case 6:
            dpadBtn = "W";
                break;
            case 7:
            dpadBtn = "NW";
                break;
            case 8:
            dpadBtn = "NO BUTTON";
                break;
        }
        ui->dpadState->setText(dpadBtn.c_str());
        break;
        case L2LBL:
        bumpers = std::to_string(data);
        ui->L2State->setText(bumpers.c_str());
        break;
        case R2LBL:
        bumpers = std::to_string(data);
        ui->R2State->setText(bumpers.c_str());
        break;
        default:
            break;
    }
}
MainWindow::~MainWindow()
{
    delete ui;
}
