#ifndef DFT_H
#define DFT_H

#include <QWidget>
#include <QDialog.h>
#include <opencv2/opencv.hpp>
#include <QImage.h>
#include <QTextCodec.h>
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
    void receiveData(QString);
    void receiveMat(Mat &);
signals:
    void sendData(QString);

public:
    explicit DFT(QWidget *parent = nullptr);
    ~DFT();
    void ImagePrint(QString);
    void matPrint(Mat &);


private:
    Ui::DFT *ui;
    Mat myMat;
};

#endif // DFT_H
