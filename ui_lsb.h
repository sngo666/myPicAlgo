/********************************************************************************
** Form generated from reading UI file 'lsb.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LSB_H
#define UI_LSB_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_lsb
{
public:
    QTextBrowser *Msg;
    QLabel *markPic;
    QLabel *lsbPic;
    QPushButton *inputMarkPic;
    QSpinBox *bitPos;
    QPushButton *operateBit;

    void setupUi(QWidget *lsb)
    {
        if (lsb->objectName().isEmpty())
            lsb->setObjectName(QString::fromUtf8("lsb"));
        lsb->resize(718, 827);
        Msg = new QTextBrowser(lsb);
        Msg->setObjectName(QString::fromUtf8("Msg"));
        Msg->setGeometry(QRect(560, 60, 161, 291));
        markPic = new QLabel(lsb);
        markPic->setObjectName(QString::fromUtf8("markPic"));
        markPic->setGeometry(QRect(10, 10, 541, 331));
        lsbPic = new QLabel(lsb);
        lsbPic->setObjectName(QString::fromUtf8("lsbPic"));
        lsbPic->setGeometry(QRect(0, 360, 711, 461));
        inputMarkPic = new QPushButton(lsb);
        inputMarkPic->setObjectName(QString::fromUtf8("inputMarkPic"));
        inputMarkPic->setGeometry(QRect(560, 0, 161, 41));
        bitPos = new QSpinBox(lsb);
        bitPos->setObjectName(QString::fromUtf8("bitPos"));
        bitPos->setGeometry(QRect(660, 40, 61, 22));
        bitPos->setMinimum(1);
        bitPos->setMaximum(8);
        bitPos->setValue(8);
        operateBit = new QPushButton(lsb);
        operateBit->setObjectName(QString::fromUtf8("operateBit"));
        operateBit->setGeometry(QRect(560, 40, 101, 23));

        retranslateUi(lsb);

        QMetaObject::connectSlotsByName(lsb);
    } // setupUi

    void retranslateUi(QWidget *lsb)
    {
        lsb->setWindowTitle(QCoreApplication::translate("lsb", "Form", nullptr));
        markPic->setText(QString());
        lsbPic->setText(QString());
        inputMarkPic->setText(QCoreApplication::translate("lsb", "put in markPic", nullptr));
        operateBit->setText(QCoreApplication::translate("lsb", "apply bit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class lsb: public Ui_lsb {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LSB_H
