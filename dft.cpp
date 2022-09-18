#include "dft.h"
#include "ui_dft.h"
using namespace cv;
// #include "mainwindow.h"
// #include "ui_mainwindow.h"

DFT::DFT(QWidget *parent) : QWidget(parent), ui(new Ui::DFT)
{
    ui->setupUi(this);
    this->setFixedSize(this->width(), this->height());
    this->setAttribute(Qt::WA_QuitOnClose, false);
}

// void DFT::receiveData(QString data)
// {
//     ui->textBrowser->setText("data got:" + data);
//     this->printMat(data);
// }

void DFT::receiveDFTMat(Mat &m_dft)
{
    dftMat = m_dft;
    ui->textBrowser->setText("dft got!");
    this->printMat(dftMat, ui->displayDFT);
}

void DFT::receiveIDFTMat(Mat &m_idft)
{
    idftMat = m_idft;
    ui->textBrowser->setText("idft got!");
    this->printMat(idftMat, ui->displayIDFT);
}

void DFT::printMat(Mat &m_srcImage, QLabel *label)
{
    if (m_srcImage.data)
    {

        QImage img = QImage(
            (const uchar *)m_srcImage.data, m_srcImage.cols, m_srcImage.rows,
            m_srcImage.cols * m_srcImage.channels(), QImage::Format_Indexed8);
        label->clear();
        int m_nImgWidth = m_srcImage.cols;  //图像宽
        int m_nImgHeight = m_srcImage.rows; //图像高

        QPixmap pixmap = QPixmap::fromImage(img);
        int lWide = label->width();
        int lHeight = label->height();
        if (m_nImgWidth * 2 < lWide && m_nImgHeight * 2 < lHeight)
        {
            lWide = m_nImgWidth * 2;
            lHeight = m_nImgHeight * 2;
        }

        label->setPixmap(pixmap.scaled(lWide, lHeight, Qt::IgnoreAspectRatio));
        // label->setAutoFillBackground(true);
        QPalette palette;
        palette.setBrush(label->backgroundRole(), QBrush(pixmap));
        label->setPalette(palette);
        label->repaint();

        // label->setScaledContents(true);

        // label->resize(lWide, lHeight);
    }
}

DFT::~DFT()
{
    delete ui;
}
