/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout_2;
    QGridLayout *core4;
    QLabel *xState;
    QLabel *sqrState;
    QLabel *dpadState;
    QLabel *dpabPix;
    QLabel *sqrPix;
    QLabel *crcPix;
    QLabel *triState;
    QLabel *crcState;
    QLabel *xPix;
    QLabel *triPix;
    QLabel *R2pix;
    QLabel *R2State;
    QLabel *L2pix;
    QLabel *L2State;
    QLabel *headerLbl;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1286, 800);
        MainWindow->setMaximumSize(QSize(1920, 1080));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(220, 90, 788, 751));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        core4 = new QGridLayout();
        core4->setObjectName(QString::fromUtf8("core4"));
        xState = new QLabel(verticalLayoutWidget);
        xState->setObjectName(QString::fromUtf8("xState"));
        QFont font;
        font.setBold(true);
        font.setItalic(true);
        font.setWeight(75);
        xState->setFont(font);

        core4->addWidget(xState, 3, 3, 1, 1);

        sqrState = new QLabel(verticalLayoutWidget);
        sqrState->setObjectName(QString::fromUtf8("sqrState"));
        sqrState->setFont(font);

        core4->addWidget(sqrState, 3, 1, 1, 1);

        dpadState = new QLabel(verticalLayoutWidget);
        dpadState->setObjectName(QString::fromUtf8("dpadState"));
        dpadState->setFont(font);

        core4->addWidget(dpadState, 1, 1, 1, 1);

        dpabPix = new QLabel(verticalLayoutWidget);
        dpabPix->setObjectName(QString::fromUtf8("dpabPix"));
        dpabPix->setMaximumSize(QSize(165, 150));
        dpabPix->setAutoFillBackground(true);
        dpabPix->setPixmap(QPixmap(QString::fromUtf8(":/img/img/dpad.jpg")));
        dpabPix->setScaledContents(true);
        dpabPix->setAlignment(Qt::AlignCenter);

        core4->addWidget(dpabPix, 1, 0, 1, 1);

        sqrPix = new QLabel(verticalLayoutWidget);
        sqrPix->setObjectName(QString::fromUtf8("sqrPix"));
        sqrPix->setMaximumSize(QSize(165, 100));
        sqrPix->setPixmap(QPixmap(QString::fromUtf8(":/img/img/sqr.png")));
        sqrPix->setScaledContents(true);
        sqrPix->setAlignment(Qt::AlignCenter);

        core4->addWidget(sqrPix, 3, 0, 1, 1);

        crcPix = new QLabel(verticalLayoutWidget);
        crcPix->setObjectName(QString::fromUtf8("crcPix"));
        crcPix->setMaximumSize(QSize(165, 150));
        crcPix->setAutoFillBackground(true);
        crcPix->setPixmap(QPixmap(QString::fromUtf8(":/img/img/crc.png")));
        crcPix->setScaledContents(true);

        core4->addWidget(crcPix, 2, 2, 1, 1);

        triState = new QLabel(verticalLayoutWidget);
        triState->setObjectName(QString::fromUtf8("triState"));
        triState->setFont(font);
        triState->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        core4->addWidget(triState, 2, 1, 1, 1);

        crcState = new QLabel(verticalLayoutWidget);
        crcState->setObjectName(QString::fromUtf8("crcState"));
        crcState->setFont(font);

        core4->addWidget(crcState, 2, 3, 1, 1);

        xPix = new QLabel(verticalLayoutWidget);
        xPix->setObjectName(QString::fromUtf8("xPix"));
        xPix->setMaximumSize(QSize(165, 100));
        xPix->setPixmap(QPixmap(QString::fromUtf8(":/img/img/xbtn.jpeg")));
        xPix->setScaledContents(true);

        core4->addWidget(xPix, 3, 2, 1, 1);

        triPix = new QLabel(verticalLayoutWidget);
        triPix->setObjectName(QString::fromUtf8("triPix"));
        triPix->setMaximumSize(QSize(165, 150));
        triPix->setAutoFillBackground(true);
        triPix->setFrameShape(QFrame::NoFrame);
        triPix->setPixmap(QPixmap(QString::fromUtf8(":/img/img/triangle.png")));
        triPix->setScaledContents(true);
        triPix->setAlignment(Qt::AlignCenter);

        core4->addWidget(triPix, 2, 0, 1, 1, Qt::AlignHCenter);

        R2pix = new QLabel(verticalLayoutWidget);
        R2pix->setObjectName(QString::fromUtf8("R2pix"));
        R2pix->setMaximumSize(QSize(165, 150));
        R2pix->setPixmap(QPixmap(QString::fromUtf8(":/img/img/r2.png")));
        R2pix->setScaledContents(true);

        core4->addWidget(R2pix, 0, 0, 1, 1);

        R2State = new QLabel(verticalLayoutWidget);
        R2State->setObjectName(QString::fromUtf8("R2State"));
        R2State->setFont(font);

        core4->addWidget(R2State, 0, 1, 1, 1);

        L2pix = new QLabel(verticalLayoutWidget);
        L2pix->setObjectName(QString::fromUtf8("L2pix"));
        L2pix->setMaximumSize(QSize(165, 150));
        L2pix->setPixmap(QPixmap(QString::fromUtf8(":/img/img/L2.jpeg")));
        L2pix->setScaledContents(true);

        core4->addWidget(L2pix, 0, 2, 1, 1);

        L2State = new QLabel(verticalLayoutWidget);
        L2State->setObjectName(QString::fromUtf8("L2State"));
        L2State->setFont(font);

        core4->addWidget(L2State, 0, 3, 1, 1);


        verticalLayout_2->addLayout(core4);

        headerLbl = new QLabel(centralwidget);
        headerLbl->setObjectName(QString::fromUtf8("headerLbl"));
        headerLbl->setEnabled(true);
        headerLbl->setGeometry(QRect(480, 0, 220, 29));
        QFont font1;
        font1.setPointSize(16);
        font1.setBold(true);
        font1.setWeight(75);
        headerLbl->setFont(font1);
        headerLbl->setAlignment(Qt::AlignCenter);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1286, 28));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        xState->setText(QCoreApplication::translate("MainWindow", "UP", nullptr));
        sqrState->setText(QCoreApplication::translate("MainWindow", "UP", nullptr));
        dpadState->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        dpabPix->setText(QString());
        sqrPix->setText(QString());
        crcPix->setText(QString());
        triState->setText(QCoreApplication::translate("MainWindow", "UP", nullptr));
        crcState->setText(QCoreApplication::translate("MainWindow", "UP", nullptr));
        xPix->setText(QString());
        triPix->setText(QString());
        R2pix->setText(QString());
        R2State->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        L2pix->setText(QString());
        L2State->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        headerLbl->setText(QCoreApplication::translate("MainWindow", "DS4 Display", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
