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
    QPushButton *lsbEmbed;

    void setupUi(QWidget *lsb)
    {
        if (lsb->objectName().isEmpty())
            lsb->setObjectName(QString::fromUtf8("lsb"));
        lsb->resize(724, 827);
        Msg = new QTextBrowser(lsb);
        Msg->setObjectName(QString::fromUtf8("Msg"));
        Msg->setGeometry(QRect(320, 0, 241, 311));
        markPic = new QLabel(lsb);
        markPic->setObjectName(QString::fromUtf8("markPic"));
        markPic->setGeometry(QRect(0, 0, 321, 311));
        lsbPic = new QLabel(lsb);
        lsbPic->setObjectName(QString::fromUtf8("lsbPic"));
        lsbPic->setGeometry(QRect(10, 310, 711, 501));
        inputMarkPic = new QPushButton(lsb);
        inputMarkPic->setObjectName(QString::fromUtf8("inputMarkPic"));
        inputMarkPic->setGeometry(QRect(560, 0, 161, 41));
        bitPos = new QSpinBox(lsb);
        bitPos->setObjectName(QString::fromUtf8("bitPos"));
        bitPos->setGeometry(QRect(640, 40, 81, 22));
        bitPos->setInputMethodHints(Qt::ImhDigitsOnly);
        bitPos->setWrapping(true);
        bitPos->setMinimum(0);
        bitPos->setMaximum(7);
        bitPos->setValue(0);
        lsbEmbed = new QPushButton(lsb);
        lsbEmbed->setObjectName(QString::fromUtf8("lsbEmbed"));
        lsbEmbed->setGeometry(QRect(560, 60, 161, 41));

        retranslateUi(lsb);

        QMetaObject::connectSlotsByName(lsb);
    } // setupUi

    void retranslateUi(QWidget *lsb)
    {
        lsb->setWindowTitle(QCoreApplication::translate("lsb", "Form", nullptr));
        markPic->setText(QString());
        lsbPic->setText(QString());
        inputMarkPic->setText(QCoreApplication::translate("lsb", "put in markPic", nullptr));
        lsbEmbed->setText(QCoreApplication::translate("lsb", "LSB embed", nullptr));
    } // retranslateUi

};

namespace Ui {
    class lsb: public Ui_lsb {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LSB_H
