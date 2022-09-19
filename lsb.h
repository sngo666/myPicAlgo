#ifndef LSB_H
#define LSB_H

#include <QWidget>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <typeinfo>
#include <opencv2/core/utility.hpp>
#include <opencv2/video/tracking.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/highgui.hpp>
#include <vector>
#include <qstring.h>
#include <QDebug.h>
#include <QDesktopWidget.h>
#include <QDialog.h>
#include <QFileDialog.h>

#include <QDialog.h>
#include <QImage.h>
#include <QLabel.h>
#include <QTextCodec.h>
#include <opencv2/opencv.hpp>

#include "opencv2/imgproc/types_c.h"
using namespace cv;
using namespace std;

namespace Ui
{
  class lsb;
}

class lsb : public QWidget
{
  Q_OBJECT

public slots:
  void receiveFilePath(QString);
  void inputMarkPic();
  void lsbEmbed_Clicked();

public:
  explicit lsb(QWidget *parent = nullptr);
  ~lsb();

  template <typename _Tp>
  vector<_Tp> convertMatToVector(const Mat &);

  template <typename _Tp>
  cv::Mat convertVectorToMat(vector<_Tp>, int, int);

  void printMat(Mat &m_srcImage, QLabel *label);
  void PrintLog(const QString qstr, QString color, QString size);
  void testConvert();

  cv::Mat imageLSB(cv::Mat, cv::Mat, int);
  template <typename _Tp>
  vector<_Tp> drawWatermarkOnImage(vector<_Tp>, vector<_Tp>, int);
  void showImageLSBWatermark(cv::Mat, int);


private:
  Ui::lsb *ui;
  QString filePath;
  QString markPath;
  Mat src;
  Mat mrk;
  Mat lsbPic;
};

#endif // LSB_H
