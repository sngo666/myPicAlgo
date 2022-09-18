#ifndef IDFT_H
#define IDFT_H

#include <QDialog.h>
#include <QImage.h>
#include <QTextCodec.h>
#include <QThread.h>
#include <QWidget.h>
#include <opencv2/opencv.hpp>
using namespace cv;

namespace Ui
{
class IDFT;
}

class IDFT : public QWidget
{
    Q_OBJECT

  public slots:
    void receiveData(QString);
    void receiveIDFTMat(Mat &);
  signals:
    void sendData(QString);

  public:
    explicit IDFT(QWidget *parent = nullptr);
    ~IDFT();
    void ImagePrint(QString);
    void matPrint(Mat &);

  private:
    Ui::IDFT *ui;
    Mat myMat;
};

#endif // IDFT_H
