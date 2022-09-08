/********************************************************************************
** Form generated from reading UI file 'dft.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DFT_H
#define UI_DFT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DFT
{
public:
    QTextBrowser *textBrowser;
    QLabel *displayPic;

    void setupUi(QWidget *DFT)
    {
        if (DFT->objectName().isEmpty())
            DFT->setObjectName(QString::fromUtf8("DFT"));
        DFT->resize(471, 559);
        textBrowser = new QTextBrowser(DFT);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(0, 0, 471, 41));
        displayPic = new QLabel(DFT);
        displayPic->setObjectName(QString::fromUtf8("displayPic"));
        displayPic->setGeometry(QRect(70, 120, 321, 331));

        retranslateUi(DFT);

        QMetaObject::connectSlotsByName(DFT);
    } // setupUi

    void retranslateUi(QWidget *DFT)
    {
        DFT->setWindowTitle(QCoreApplication::translate("DFT", "Form", nullptr));
        textBrowser->setHtml(QCoreApplication::translate("DFT", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">this is a DFT Widget</p></body></html>", nullptr));
        displayPic->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class DFT: public Ui_DFT {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DFT_H
