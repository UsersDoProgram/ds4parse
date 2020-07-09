#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>
#include "LBL.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    /* Set All Labels that are shown when buttons are pressed to hidden */
    std::vector<QLabel*> labelVec;
    labelVec.push_back(ui->triLbl);
    labelVec.push_back(ui->sqrLbl);
    labelVec.push_back(ui->xLbl);
    labelVec.push_back(ui->crcLbl);
    for(QLabel* curr: labelVec){
        curr->setHidden(true);
    }
}
void MainWindow::vis(enum LBL target,bool opt){
    switch(target){
        case triLBL:
        ui->triLbl->setHidden(!opt);
            break;
        case sqrLBL:
        ui->sqrLbl->setHidden(!opt);
            break;
        case xLBL:
        ui->xLbl->setHidden(!opt);
            break;
        case crcLBL:
        ui->crcLbl->setHidden(!opt);
            break;
        default:
            break;
    }
}
MainWindow::~MainWindow()
{
    delete ui;
}

