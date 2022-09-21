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

    cvtColor(m_srcImage, m_srcImage, COLOR_BGR2RGB);
    QImage::Format format = QImage::Format_RGB888;
    switch (m_srcImage.type())
    {
    case CV_8UC1:
      format = QImage::Format_Indexed8;
      break;
    case CV_8UC3:
      format = QImage::Format_RGB888;
      break;
    case CV_8UC4:
      format = QImage::Format_ARGB32;
      break;
    }

    QImage img = QImage((const uchar *)m_srcImage.data, m_srcImage.cols, m_srcImage.rows, m_srcImage.cols * m_srcImage.channels(), format);
    label->clear();
    int m_nImgWidth = m_srcImage.cols;  //图像宽
    int m_nImgHeight = m_srcImage.rows; //图像高

    QPixmap pixmap = QPixmap::fromImage(img);
    int lWide = label->width();
    int lHeight = label->height();
    // if (m_nImgWidth * 2 < lWide && m_nImgHeight * 2 < lHeight)
    // {
    //   lWide = m_nImgWidth * 2;
    //   lHeight = m_nImgHeight * 2;
    // }
    // this->PrintLog("LabelWide: " + QString::number(lWide), "red", "3");
    // this->PrintLog("LabelHeight: " + QString::number(lHeight), "red", "3");

    // this->PrintLog("PicWide: " + QString::number(m_nImgWidth), "green", "3");
    // this->PrintLog("PicHeight: " + QString::number(m_nImgHeight), "green", "3");

    int m_height, m_width;
    double k2 = (double)m_nImgWidth / (double)m_nImgHeight;
    double k1 = (double)lWide / (double)lHeight;

    // this->PrintLog("k1: " + QString::number(k1), "purple", "3");
    // this->PrintLog("k2: " + QString::number(k2), "purple", "3");
    if (k2 >= k1)
    {
      m_width = lWide;
      m_height = (int)(lWide * 1.0 / k2);
    }
    else
    {
      m_width = (int)(k2 * lHeight);
      m_height = lHeight;
    }

    // label->setAutoFillBackground(true);
    // this->PrintLog("PicWide: " + QString::number(m_width), "blue", "3");
    // this->PrintLog("PicHeight: " + QString::number(m_height), "blue", "3");

    // label->setPixmap(pixmap.scaled(m_nImgWidth, m_nImgHeight));
    label->setPixmap(pixmap.scaled(m_width, m_height, Qt::IgnoreAspectRatio));

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
