#ifndef DFT_H
#define DFT_H

#include <QDialog.h>
#include <QImage.h>
#include <QLabel.h>
#include <QTextCodec.h>
#include <opencv2/opencv.hpp>
#include <qwidget.h>

using namespace cv;

class MainWindow;

namespace Ui
{
class DFT;
}

class DFT : public QWidget
{
    Q_OBJECT

  public slots:
    // void receiveData(QString);
    void receiveDFTMat(Mat &);
    void receiveIDFTMat(Mat &);

  signals:
    void sendData(QString);

  public:
    explicit DFT(QWidget *parent = nullptr);
    ~DFT();
    void printMat(Mat &, QLabel *);

  private:
    Ui::DFT *ui;
    Mat dftMat;
    Mat idftMat;
};

#endif // DFT_H
