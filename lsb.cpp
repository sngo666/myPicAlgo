#include "lsb.h"
#include "ui_lsb.h"

lsb::lsb(QWidget *parent) : QWidget(parent),
                            ui(new Ui::lsb)
{
  ui->setupUi(this);
  this->setFixedSize(this->width(), this->height());
  this->setAttribute(Qt::WA_QuitOnClose, false);
  operatePos = ui->bitPos;

  connect(ui->inputMarkPic, SIGNAL(clicked()), this, SLOT(inputMarkPic()));
  connect(ui->lsbEmbed, SIGNAL(clicked()), this, SLOT(lsbEmbed_Clicked()));
  // connect(ui->bitPos, static_cast<void (QSpinBox::*)(int)>(&QSpinBox::valueChanged), SLOT(bitPos_Changed));
}

template <typename _Tp>
vector<_Tp> lsb::convertMatToVector(const Mat &mat)
{
  return (vector<_Tp>)(mat.reshape(1, 1));
}

template <typename _Tp>
cv::Mat lsb::convertVectorToMat(vector<_Tp> v, int channels, int rows)
{
  cv::Mat mat = cv::Mat(v);
  cv::Mat dest = mat.reshape(channels, rows).clone();
  dest.convertTo(dest, CV_8U);
  return dest;
}

void lsb::receiveFilePath(QString m_filePath)
{
  filePath = m_filePath;
  QTextCodec *code = QTextCodec::codecForName("gb18030");
  std::string name = code->fromUnicode(filePath).data();
  src = imread(name);

  // this->printMat(src, ui->markPic);
}

void lsb::inputMarkPic()
{
  QString m_filePath = QFileDialog::getOpenFileName(
      this, tr("Put in Picture"), ".", tr("Image Files(*.jpg *.png)"));
  if (m_filePath.isEmpty())
  {
    this->PrintLog("cancelled!", "red", "3");
  }
  else
  {
    QTextCodec *code = QTextCodec::codecForName("gb18030");
    std::string name = code->fromUnicode(m_filePath).data();
    mrk = imread(name, 0);

    // this->testConvert();
    this->printMat(mrk, ui->markPic);
  }
}

void lsb::testConvert()
{
  vector<char> vec = this->convertMatToVector<char>(mrk);
  Mat m = this->convertVectorToMat(vec, 1, mrk.rows);
  this->printMat(mrk, ui->markPic);
}

void lsb::PrintLog(const QString qstr, QString color, QString size)
{
  ui->Msg->moveCursor(QTextCursor::End, QTextCursor::MoveAnchor);
  ui->Msg->append("<font size=\"" + size + "\"" + " color=\"" + color +
                  "\"" + ">" + qstr + "</font>");
}

void lsb::bitPos_Changed()
{
  // vector<Mat> imgs;
  // cv::split(src, imgs);
  // for (int i = 0; i < 3; ++i)
  // {
  //   imgs[i] = this->imageLSB(imgs[i], mrk, ui->bitPos->text().toInt());
  // }
  // Mat img_lsb;
  // cv::merge(imgs, img_lsb);

  // this->printMat(img_lsb, ui->lsbPic);
}

void lsb::lsbEmbed_Clicked()
{
  vector<Mat> imgs;
  cv::split(src, imgs);
  for (int i = 0; i < 3; ++i)
  {
    imgs[i] = this->imageLSB(imgs[i], mrk, ui->bitPos->text().toInt());
  }
  Mat img_lsb;
  cv::merge(imgs, img_lsb);

  this->printMat(img_lsb, ui->lsbPic);
}

void lsb::showImageLSBWatermark(cv::Mat image, int num)
{
  cv::Mat dst_img;
  if (num > 7 || num < 0)
    num = 0;
  vector<int> v = convertMatToVector<int>(image);
  vector<int> u;
  int series = pow(2, num);
  int j = 0, k = 0;
  for (long long unsigned int i = 0; i < v.size() / 3; ++i)
  {
    j = 0, k = 0;
    v[3 * i] / series % 2 == 0 ? ++j : ++k;
    v[3 * i + 1] / series % 2 == 0 ? ++j : ++k;
    v[3 * i + 2] / series % 2 == 0 ? ++j : ++k;
    u.push_back(j > k ? 0 : 255);
  }
  dst_img = convertVectorToMat(u, 1, image.rows);
  cv::imshow("dst_img", dst_img);
}

template <typename _Tp>
vector<_Tp> lsb::drawWatermarkOnImage(vector<_Tp> v, vector<_Tp> w, int num)
{
  if (num > 7 || num < 0)
    return v;
  int series = pow(2, num);
  for (long long unsigned int i = 0; i < v.size(); ++i)
  {
    if (v[i] / series % 2 != 0)
      v[i] -= series; //清空操作位
    v[i] += pow(2, num) * w[i];

    if (v[i] > 254)
      v[i] = 255;
    else if (v[i] < 1)
      v[i] = 0;
  }
  return v;
}

cv::Mat lsb::imageLSB(cv::Mat src_img, cv::Mat mrk_img, int num)
{
  if (src_img.size() != mrk_img.size())
  {
    cv::copyMakeBorder(mrk_img, mrk_img,
                       0, src_img.rows - mrk_img.rows,
                       0, src_img.cols - mrk_img.cols,
                       cv::BORDER_WRAP, Scalar::all(0));
  }
  cv::Mat dst_img;

  vector<int> src_v = convertMatToVector<int>(src_img);
  vector<int> mrk_v = convertMatToVector<int>(mrk_img);

  for (long long unsigned int i = 0; i < mrk_v.size(); ++i)
  {
    mrk_v[i] = mrk_v[i] < 120 ? 0 : 1;
  }

  src_v = drawWatermarkOnImage(src_v, mrk_v, num);
  dst_img = convertVectorToMat(src_v, 1, src_img.rows);

  return dst_img;
}

void lsb::printMat(Mat &m_srcImage, QLabel *label)
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
    label->setPixmap(pixmap.scaled(m_width - 1, m_height - 1, Qt::IgnoreAspectRatio)); //防止溢出

    QPalette palette;
    palette.setBrush(label->backgroundRole(), QBrush(pixmap));
    label->setPalette(palette);
    label->repaint();

    // label->setScaledContents(true);

    // label->resize(lWide, lHeight);
  }
}

lsb::~lsb()
{
  delete ui;
}
