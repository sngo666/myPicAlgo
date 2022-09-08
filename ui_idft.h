/********************************************************************************
** Form generated from reading UI file 'idft.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IDFT_H
#define UI_IDFT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_IDFT
{
public:
    QLabel *displayIDFT;
    QTextBrowser *textBrowser;

    void setupUi(QWidget *IDFT)
    {
        if (IDFT->objectName().isEmpty())
            IDFT->setObjectName(QString::fromUtf8("IDFT"));
        IDFT->resize(458, 573);
        displayIDFT = new QLabel(IDFT);
        displayIDFT->setObjectName(QString::fromUtf8("displayIDFT"));
        displayIDFT->setGeometry(QRect(70, 140, 311, 311));
        textBrowser = new QTextBrowser(IDFT);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(0, 0, 461, 51));

        retranslateUi(IDFT);

        QMetaObject::connectSlotsByName(IDFT);
    } // setupUi

    void retranslateUi(QWidget *IDFT)
    {
        IDFT->setWindowTitle(QCoreApplication::translate("IDFT", "Form", nullptr));
        displayIDFT->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class IDFT: public Ui_IDFT {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IDFT_H
