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
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *gridLayoutWidget;
    QGridLayout *core4;
    QLabel *crcLbl;
    QLabel *sqrLbl;
    QLabel *xLbl;
    QLabel *triLbl;
    QLabel *tstLbl;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayoutWidget = new QWidget(centralwidget);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(150, 150, 501, 331));
        core4 = new QGridLayout(gridLayoutWidget);
        core4->setObjectName(QString::fromUtf8("core4"));
        core4->setContentsMargins(0, 0, 0, 0);
        crcLbl = new QLabel(gridLayoutWidget);
        crcLbl->setObjectName(QString::fromUtf8("crcLbl"));

        core4->addWidget(crcLbl, 0, 1, 1, 1);

        sqrLbl = new QLabel(gridLayoutWidget);
        sqrLbl->setObjectName(QString::fromUtf8("sqrLbl"));

        core4->addWidget(sqrLbl, 1, 0, 1, 1);

        xLbl = new QLabel(gridLayoutWidget);
        xLbl->setObjectName(QString::fromUtf8("xLbl"));

        core4->addWidget(xLbl, 1, 1, 1, 1);

        triLbl = new QLabel(gridLayoutWidget);
        triLbl->setObjectName(QString::fromUtf8("triLbl"));

        core4->addWidget(triLbl, 0, 0, 1, 1);

        tstLbl = new QLabel(centralwidget);
        tstLbl->setObjectName(QString::fromUtf8("tstLbl"));
        tstLbl->setGeometry(QRect(320, 10, 171, 31));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 30));
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
        crcLbl->setText(QCoreApplication::translate("MainWindow", "CRC", nullptr));
        sqrLbl->setText(QCoreApplication::translate("MainWindow", "SQR", nullptr));
        xLbl->setText(QCoreApplication::translate("MainWindow", "X", nullptr));
        triLbl->setText(QCoreApplication::translate("MainWindow", "TRI", nullptr));
        tstLbl->setText(QCoreApplication::translate("MainWindow", "DS4 Display", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
