/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *DFT;
    QPushButton *openFolder;
    QPushButton *InputPhoto;
    QTextBrowser *Developer;
    QTextBrowser *myFilePath;
    QTextBrowser *LogBrow;
    QTextBrowser *textBrowser;
    QPushButton *cleanLog;
    QProgressBar *cleanBar;
    QPushButton *openDFT;
    QLabel *Pic;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(664, 547);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        DFT = new QPushButton(centralwidget);
        DFT->setObjectName(QString::fromUtf8("DFT"));
        DFT->setGeometry(QRect(-10, 40, 151, 31));
        openFolder = new QPushButton(centralwidget);
        openFolder->setObjectName(QString::fromUtf8("openFolder"));
        openFolder->setGeometry(QRect(-20, 210, 161, 31));
        InputPhoto = new QPushButton(centralwidget);
        InputPhoto->setObjectName(QString::fromUtf8("InputPhoto"));
        InputPhoto->setGeometry(QRect(-10, 0, 151, 31));
        Developer = new QTextBrowser(centralwidget);
        Developer->setObjectName(QString::fromUtf8("Developer"));
        Developer->setGeometry(QRect(0, 240, 141, 111));
        myFilePath = new QTextBrowser(centralwidget);
        myFilePath->setObjectName(QString::fromUtf8("myFilePath"));
        myFilePath->setGeometry(QRect(0, 90, 141, 121));
        LogBrow = new QTextBrowser(centralwidget);
        LogBrow->setObjectName(QString::fromUtf8("LogBrow"));
        LogBrow->setGeometry(QRect(470, 40, 191, 461));
        textBrowser = new QTextBrowser(centralwidget);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(490, 10, 151, 31));
        cleanLog = new QPushButton(centralwidget);
        cleanLog->setObjectName(QString::fromUtf8("cleanLog"));
        cleanLog->setGeometry(QRect(0, 500, 141, 21));
        cleanLog->setFlat(true);
        cleanBar = new QProgressBar(centralwidget);
        cleanBar->setObjectName(QString::fromUtf8("cleanBar"));
        cleanBar->setGeometry(QRect(470, 500, 191, 21));
        cleanBar->setInputMethodHints(Qt::ImhNone);
        cleanBar->setMaximum(10);
        cleanBar->setValue(0);
        cleanBar->setTextVisible(false);
        openDFT = new QPushButton(centralwidget);
        openDFT->setObjectName(QString::fromUtf8("openDFT"));
        openDFT->setGeometry(QRect(-10, 350, 151, 41));
        Pic = new QLabel(centralwidget);
        Pic->setObjectName(QString::fromUtf8("Pic"));
        Pic->setGeometry(QRect(150, 80, 311, 351));
        MainWindow->setCentralWidget(centralwidget);
        cleanLog->raise();
        LogBrow->raise();
        cleanBar->raise();
        DFT->raise();
        openFolder->raise();
        InputPhoto->raise();
        Developer->raise();
        myFilePath->raise();
        textBrowser->raise();
        openDFT->raise();
        Pic->raise();
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        DFT->setText(QCoreApplication::translate("MainWindow", "DFT and IDFT", nullptr));
        openFolder->setText(QCoreApplication::translate("MainWindow", "open Pic-Folder", nullptr));
        InputPhoto->setText(QCoreApplication::translate("MainWindow", "Put in Picture", nullptr));
        Developer->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><a href=\"https://github.com/sngo666\"><span style=\" text-decoration: underline; color:#0000ff;\">MyGithub</span></a></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\342\200\224\342\200\224\342\200\224\342\200\224</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\346\233\264\346\226\260\346\227\266\351\227\264\357\274\232</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; marg"
                        "in-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
        textBrowser->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt; color:#1201d4;\">System Log</span></p></body></html>", nullptr));
        cleanLog->setText(QString());
        openDFT->setText(QCoreApplication::translate("MainWindow", "open the DFT Widget", nullptr));
        Pic->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
