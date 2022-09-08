#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDebug.h>
#include <QDesktopWidget.h>
#include <QDialog.h>
#include <QFileDialog.h>
#include <QImage.h>
#include <QMainWindow>
#include <QPushButton.h>
#include <QString.h>
#include <QThread>
#include <QTimer.h>
#include <Qlabel.h>
#include <QtCore/qmath.h>
#include <cmath>
#include <opencv2/opencv.hpp>
#include <stdlib.h>

using namespace cv;
class DFT;
class IDFT;
QT_BEGIN_NAMESPACE
namespace Ui
{
class MainWindow;
}
QT_END_NAMESPACE

static Mat tempDFTMat;
static Mat tempIDFTMat;
static int sendflag;
static int systembusy;
class workThread : public QObject
{
    // int id;
    Q_OBJECT
  public:
    workThread(QObject *parent = nullptr);
    ~workThread();
    void dftHandle(unsigned char **, unsigned char **, double **, double **,
                   int, int);
    void idftHandle(double **, double **, unsigned char **, int, int);
    QString fileName;
  public slots:
    void startWork();
    void doWork();
  signals:
    void workFinished();
    void workStart();
    void sendThMat(Mat &);
    void sendThIDFTMat(Mat &);
  public slots:
    void getFilePath(QString);
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

  public slots:
    void DFT_clicked();
    void INPUT_clicked();
    void IDFT_clicked();
    void SLOT_openDFTWidget();
    void receiveData(QString);
    void createConnection();
    void SLOT_openIDFTWidget();

  public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void PrintLog(const QString, QString, QString);
    void childTest();

    // , long, long
    // Mat dftTransfer(Mat &);
    double tsin(double);
    void matPrint(Mat &);
    void AutoScale(Mat, Mat);
    QThread *m_workerThread;
    workThread *worker;
  signals:
    void sendData(QString);
    void sendMat(Mat &);
    void sendIDFTMat(Mat &);
    void sendThPath(QString);

  private:
    Ui::MainWindow *ui;
    QLabel *m_label;
    QPushButton *Button_PutInPicture;
    QPushButton *Button_DFT;
    QPushButton *Button_IDFT;
    DFT *dftWidget;
    IDFT *idftWidget;

    int i = 0;
    int tid_1;
};

#endif // MAINWINDOW_H
