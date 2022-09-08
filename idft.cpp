#include "idft.h"
#include "ui_idft.h"

IDFT::IDFT(QWidget *parent) : QWidget(parent),
                              ui(new Ui::IDFT)
{
    ui->setupUi(this);
    this->setAttribute(Qt::WA_QuitOnClose, false);
}

void IDFT::receiveData(QString data)
{
    // ui->textBrowser->setText("data got:" + data);
    // this->ImagePrint(data);
}

void IDFT::receiveIDFTMat(Mat &m)
{
    myMat = m;
    ui->textBrowser->setText("mat got!");
    this->matPrint(myMat);
}

void IDFT::ImagePrint(QString fileName)
{
    QTextCodec *code = QTextCodec::codecForName("gb18030");
    std::string name = code->fromUnicode(fileName).data();
    Mat m = imread(name, 0);
    matPrint(m);
}

void IDFT::matPrint(Mat &m_srcImage)
{
    if (m_srcImage.data)
    {
        // cvtColor(m_srcImage, m_srcImage, COLOR_BGR2RGB); // BGR转化为RGB
        // QImage::Format format = QImage::Format_RGB888;
        // switch (m_srcImage.type())
        // {
        // case CV_8UC1:
        //     format = QImage::Format_Indexed8;
        //     break;
        // case CV_8UC3:
        //     format = QImage::Format_RGB888;
        //     break;
        // case CV_8UC4:
        //     format = QImage::Format_ARGB32;
        //     break;
        // }
        QImage img = QImage((const uchar *)m_srcImage.data, m_srcImage.cols, m_srcImage.rows,
                            m_srcImage.cols * m_srcImage.channels(),QImage::Format_Indexed8);
        ui->displayIDFT->clear();
        int m_nImgWidth = m_srcImage.cols;  //图像宽
        int m_nImgHeight = m_srcImage.rows; //图像高
        QPixmap pixmap = QPixmap::fromImage(img);
        pixmap = pixmap.scaled(ui->displayIDFT->size());
        ui->displayIDFT->setAutoFillBackground(true);
        QPalette palette;
        palette.setBrush(ui->displayIDFT->backgroundRole(), QBrush(pixmap));
        ui->displayIDFT->setPalette(palette);
        ui->displayIDFT->repaint();
    }
}

IDFT::~IDFT()
{
    delete ui;
}
