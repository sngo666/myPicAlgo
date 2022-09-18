#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <cmath>
#include <iostream>

#include "dft.h"
#include "ui_dft.h"

using namespace cv;
using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(this->width(), this->height());

    QString updateTime(UPDATE);
    // this->PrintLog(updateTime, "pink", "4");
    ui->Developer->append("<font size=\" 4 \" color=\"green\">" + updateTime +
                          "</font>");

    cout << "ui initialized" << endl;
    // this->setMinimumHeight(600);
    // this->setMinimumWidth(800);

    ui->Developer->setFocusPolicy(Qt::NoFocus);
    ui->Developer->setOpenLinks(true);
    ui->Developer->setOpenExternalLinks(true);

    dftWidget = new DFT();
    systembusy = 0;
    QTimer *timer = new QTimer(this);
    timer->start(100);

    connect(timer, &QTimer::timeout, [=]() {
        if (ui->cleanLog->isDown() == false)
        {
            i--;
            ui->cleanBar->setValue(i);
            if (i <= 0)
                i = 0;
        }
        if (i >= 10)
            i = 0;
    });

    this->PrintLog("ui initialized\n", "blue", "4");
    connect(ui->DFT, SIGNAL(clicked()), this, SLOT(DFT_clicked()));
    connect(ui->openFolder, SIGNAL(clicked()), this,
            SLOT(openFolder_clicked()));
    connect(ui->InputPhoto, SIGNAL(clicked()), this, SLOT(INPUT_clicked()));

    ui->cleanLog->setText("press to clean log");

    ui->cleanLog->setAutoRepeat(true);       //启用长按
    ui->cleanLog->setAutoRepeatDelay(200);   //触发长按的时间
    ui->cleanLog->setAutoRepeatInterval(50); //长按时click信号间隔

    connect(ui->openDFT, SIGNAL(clicked(bool)), this,
            SLOT(SLOT_openDFTWidget()));

    connect(ui->cleanLog, &QPushButton::clicked, [&] {
        // this->PrintLog("Button is down!\n", "blue", "5");
        i++;
        ui->cleanBar->setValue(i);
        if (i >= 10)
        {
            i = 0;
            ui->LogBrow->setText("");
        }
    });
}

void MainWindow::DFT_clicked()
{

    if (systembusy == 1)
    {
        this->PrintLog("System Busy!!!", "red", "4");
        return;
    }

    // this->PrintLog("DFT Pressed\n", "blue", "5");
    connect(this, SIGNAL(sendDFTMat(Mat &)), dftWidget,
            SLOT(receiveDFTMat(Mat &)));
    connect(this, SIGNAL(sendIDFTMat(Mat &)), dftWidget,
            SLOT(receiveIDFTMat(Mat &)));

    QString fileName = ui->myFilePath->toPlainText();
    if (fileName.isEmpty())
        return;

    QTextCodec *code = QTextCodec::codecForName("gb18030");
    std::string name = code->fromUnicode(fileName).data();
    Mat mat = imread(name, 0);

    m_workerThread = new QThread();
    worker = new workThread();

    connect(m_workerThread, &QThread::started, worker, &workThread::startWork);
    connect(worker, &workThread::workFinished, m_workerThread, &QThread::quit);
    connect(m_workerThread, &QThread::finished, m_workerThread,
            &QThread::deleteLater);
    connect(this, SIGNAL(sendThPath(QString)), worker,
            SLOT(getFilePath(QString)));
    emit sendThPath(fileName);

    QTimer *tr = new QTimer(this);

    tr->start(10);

    connect(tr, &QTimer::timeout, [=]() {
        if (sendflag == 1)
        {
            m_workerThread->quit();
            m_workerThread->wait();
            this->PrintLog("DFT && IDFT Complete!!!", "green", "4");

            emit sendDFTMat(tempDFTMat);
            emit sendIDFTMat(tempIDFTMat);
            sendflag = 0;
        }
    });

    worker->moveToThread(m_workerThread);
    this->PrintLog("starting DFT && IDFT....", "purple", "4");

    m_workerThread->start();

    // emit sendMat(tempDFTMat);
}
void MainWindow::INPUT_clicked()
{
    // this->PrintLog("INPUT Pressed\n", "blue", "5");
    QString filePath = QFileDialog::getOpenFileName(
        this, tr("Put in Picture"), ".", tr("Image Files(*.jpg *.png)"));
    // const char *fileRealPath = filePath.toStdString().c_str();
    if (!filePath.isEmpty())
    {
        //     this->PrintLog("realPath: ", "green", "5");
        //     this->PrintLog(filePath + "\n", "black", "5");
    }
    else
    {
        this->PrintLog("OK,may be you cancelled all these....", "orange", "3");
        return;
    }
    QTextCodec *code = QTextCodec::codecForName("gb18030");

    ui->myFilePath->setText(filePath);
    std::string name = code->fromUnicode(filePath).data();

    Mat mat = imread(name, 0);

    // cout << name << std ::endl;

    matPrint(mat);
}

void MainWindow::openFolder_clicked()
{
    if (systembusy == 1)
    {
        this->PrintLog("System Busy!!!", "red", "4");
        return;
    }
    QString fileName = ui->myFilePath->toPlainText();
    QTextCodec *code = QTextCodec::codecForName("gb18030");

    QStringList para;
    QString folderPath = fileToFolder(fileName);
    QString pathLog("Folder Path: ");
    this->PrintLog(pathLog + folderPath, "orange", "3");

    para << QDir::toNativeSeparators(folderPath);

    if (fileName.isEmpty())
    {
        this->PrintLog("there's no Path!", "red", "4");
    }
    else
    {
        QProcess::startDetached("explorer", para);
    }
}

void MainWindow::PrintLog(const QString qstr, QString color, QString size)
{
    ui->LogBrow->moveCursor(QTextCursor::End, QTextCursor::MoveAnchor);
    ui->LogBrow->append("<font size=\"" + size + "\"" + " color=\"" + color +
                        "\"" + ">" + qstr + "</font>");
}

void MainWindow::SLOT_openDFTWidget()
{
    QDesktopWidget *desktop = QApplication::desktop();
    dftWidget->show();
    dftWidget->move(this->width() * 0.2,
                    (desktop->height() / 2 - this->height() / 2));
    QString pathStr = ui->myFilePath->toPlainText();
    if (pathStr.isEmpty())
    {
    }
    else
    {
        createConnection();
        // emit sendData(pathStr);
        // this->PrintLog("data sent!\n", "blue", "5");
    }
}

void MainWindow::childTest()
{
    this->PrintLog("child used successfully!!\n", "blue", "5");
}

void MainWindow::createConnection()
{
    //     connect(dftWidget, SIGNAL(sendData(QString)), this,
    //     SLOT(receiveData(QString)));
    connect(this, SIGNAL(sendData(QString)), dftWidget,
            SLOT(receiveData(QString)));
}

void MainWindow::receiveData(QString data)
{
    this->PrintLog("data received:\n" + data, "blue", "5");
}

void MainWindow::matPrint(Mat &m_srcImage)
{
    if (m_srcImage.data)
    {
        QImage img = QImage(
            (const uchar *)m_srcImage.data, m_srcImage.cols, m_srcImage.rows,
            m_srcImage.cols * m_srcImage.channels(), QImage::Format_Indexed8);
        ui->Pic->clear();
        int m_nImgWidth = m_srcImage.cols;  //图像宽
        int m_nImgHeight = m_srcImage.rows; //图像高
        QPixmap pixmap = QPixmap::fromImage(img);
        pixmap = pixmap.scaled(ui->Pic->size());
        ui->Pic->setAutoFillBackground(true);
        QPalette palette;
        palette.setBrush(ui->Pic->backgroundRole(), QBrush(pixmap));
        ui->Pic->setPalette(palette);
        ui->Pic->repaint();
    }
}

void MainWindow::AutoScale(Mat src, Mat out)
{
    int w = src.cols;
    int h = src.rows;
    double *p = src.ptr<double>(0);
    uchar *pOut = out.ptr<uchar>(0);
    double max = p[0];
    double min = p[0];
    for (int i = 0; i < w * h; i++)
    {
        if (p[i] > max)
            max = p[i];
        if (p[i] < min)
            min = p[i];
    }

    double scale = 255.0 / (max - min);

    for (int i = 0; i < w * h; i++)
    {
        int j = i + w * h / 2 + w / 2;
        if (j > w * h)
            j = j - w * h; //低频移至中间
        pOut[i] = (uchar)((p[j] - min) * scale);
    }
}

double MainWindow::tsin(double x)
{ //降低计算量使用低精度的泰勒展开计算sin
    double n = x, sum = 0;
    int i = 1;
    for (i = 0; i < 4; i++)
    {
        sum += n;
        i++;
        n = -n * x * x / (2 * i - 1) / (2 * i - 2);
    }
    return sum;
}

MainWindow::~MainWindow()
{
    delete ui;
}

workThread::workThread(QObject *parent) : QObject(parent)
{
    //     connect(this, SIGNAL(sendThIDFTMat(Mat &)), idftWidget,
    //     SLOT(receiveIDFTMat(Mat &))); connect(this, SIGNAL(sendThMat(Mat &)),
    //     dftWidget, SLOT(receiveMat(Mat &)));
}
workThread::~workThread()
{
}

void workThread::getFilePath(QString str)
{
    fileName = str;
    qDebug() << fileName << endl;
    cout << "file received" << endl;
}

void workThread::startWork()
{
    emit workStart();
    cout << "start thread!" << endl;

    doWork();
}

void workThread::doWork()
{
    if (fileName.isEmpty())
    {
        return;
        cout << "finished condition : 1";
        emit workFinished();
    }
    systembusy = 1;
    cout << "start thread!" << endl;
    QTextCodec *code = QTextCodec::codecForName("gb18030");

    std::string name = code->fromUnicode(fileName).data();
    Mat mat = imread(name, 0);
    int wid = mat.cols;
    int hei = mat.rows;

    unsigned char **matArray;
    matArray = new uchar *[hei];
    matArray[0] = new uchar[hei * wid];
    for (int i = 1; i < hei; i++)
    {
        matArray[i] = matArray[i - 1] + wid;
    }

    unsigned char **dftArray;
    dftArray = new uchar *[hei];
    dftArray[0] = new uchar[hei * wid];
    for (int i = 1; i < hei; i++)
    {
        dftArray[i] = dftArray[i - 1] + wid;
    }

    unsigned char **idftArray;
    idftArray = new uchar *[hei];
    idftArray[0] = new uchar[hei * wid];
    for (int i = 1; i < hei; i++)
    {
        idftArray[i] = idftArray[i - 1] + wid;
    }

    double **reArray;
    reArray = new double *[hei];
    reArray[0] = new double[hei * wid];
    for (int i = 1; i < hei; i++)
    {
        reArray[i] = reArray[i - 1] + wid;
    }

    double **imArray;
    imArray = new double *[hei];
    imArray[0] = new double[hei * wid];
    for (int i = 1; i < hei; i++)
    {
        imArray[i] = imArray[i - 1] + wid;
    }

    for (int i = 0; i < hei; i++)
    {
        for (int j = 0; j < wid; j++)
        {
            matArray[i][j] = mat.at<uchar>(i, j);
        }
    }

    this->dftHandle(matArray, dftArray, reArray, imArray, hei, wid);

    Mat dftMat(hei, wid, CV_8UC1);
    uchar *ptmp = NULL;
    for (int i = 0; i < hei; ++i)
    {
        ptmp = dftMat.ptr<uchar>(i);

        for (int j = 0; j < wid; ++j)
        {
            ptmp[j] = dftArray[i][j];
        }
    }
    this->idftHandle(reArray, imArray, idftArray, hei, wid);
    uchar *ptmp2 = NULL;
    Mat M(hei, wid, CV_8UC1);
    for (int i = 0; i < hei; ++i)
    {
        ptmp2 = M.ptr<uchar>(i);

        for (int j = 0; j < wid; ++j)
        {
            ptmp2[j] = idftArray[i][j];
        }
    }

    tempDFTMat = dftMat;
    tempIDFTMat = M;
    sendflag = 1;
    systembusy = 0;
    cout << "finished condition : 0";
    emit workFinished();
}

void workThread::dftHandle(unsigned char **in_array, unsigned char **out_array,
                           double **re_array, double **im_array, int height,
                           int width)
{
    double re, im, t;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        { //二维矩阵各点情况
            re = 0.0;
            im = 0.0;

            for (int x = 0; x < height; x++)
            {
                for (int y = 0; y < width; y++)
                {
                    t = (double)(i * x / (double)height) +
                        (double)(j * y / (double)width); // e指数上标
                    re += in_array[x][y] * cos(2 * 3.1415926 * t);
                    im += (-1) * sin(2 * 3.1415926 * t) * in_array[x][y];

                    //                 this->PrintLog(QString::number(re) +
                    //                 "\n", "blue", "5");
                }
            }

            re_array[i][j] = re;
            im_array[i][j] = im;
            out_array[i][j] = (unsigned char)((sqrt(re * re + im * im))); //振幅
                                                                          //  =
            if (out_array[i][j] > 0xff)
                out_array[i][j] = 0xff;
            else if (out_array[i][j] < 0)
                out_array[i][j] = 0;
        }
    }
    // printf("dft done\n");
}

void workThread::idftHandle(double **re_array, double **im_array,
                            unsigned char **out_array, int height, int width)
{
    double real, temp, imagin, flag;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            real = 0.0;
            imagin = 0.0;
            for (int x = 0; x < height; x++)
            {
                for (int y = 0; y < width; y++)
                {
                    temp = (double)(i * x / (double)height) +
                           (double)(j * y / (double)width); // e指数部分

                    real += re_array[x][y] * cos(2 * 3.1415926 * temp) -
                            im_array[x][y] * sin(2 * 3.1415926 * temp);
                    imagin += im_array[x][y] * cos(2 * 3.1415926 * temp) +
                              re_array[x][y] * sin(2 * 3.1415926 * temp);
                }
            }
            // * 1.0 / (width * height)
            flag = (double)(((double)sqrt(real * real + imagin * imagin)) *
                            1.0 / (width * height)); //振幅
            // out_array[i][j] = (unsigned char)atan(imagin / real); //振幅

            // if (flag > 255)
            //     flag = 255;

            // else if (flag < 0)
            //     flag = 0;

            out_array[i][j] = (unsigned char)flag;
        }
    }
}

QString fileToFolder(const QString &str)
{
    QString Folder;
    if (str.isEmpty())
        return "";
    int ptr = str.size();
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == '/')
            ptr = i;
    }
    for (int i = 0; i < ptr; i++)
    {
        Folder.append(str[i]);
    }
    return Folder;
}