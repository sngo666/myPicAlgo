#include "mainwindow.h"
#undef main
#include <QApplication>
using namespace std;

void test()
{
    Mat img = imread("D:/TestPic.jpg", 0);
    imshow("Original Image", img);
    cv::waitKey(10);
    Mat dftInput1, dftImage1, inverseDFT, inverseDFTconverted;
    img.convertTo(dftInput1, CV_32F);
    dft(dftInput1, dftImage1);
    imshow("dft", dftImage1);
    int cx = dftImage1.cols / 2;
    int cy = dftImage1.rows / 2;
    Mat q0(dftImage1, Rect(0, 0, cx, cy));   // Top-Left
    Mat q1(dftImage1, Rect(cx, 0, cx, cy));  // Top-Right
    Mat q2(dftImage1, Rect(0, cy, cx, cy));  // Bottom-Left
    Mat q3(dftImage1, Rect(cx, cy, cx, cy)); // Bottom-Right
    Mat tmp;
    q0.copyTo(tmp);
    q3.copyTo(q0);
    tmp.copyTo(q3);
    q1.copyTo(tmp);
    q2.copyTo(q1);
    tmp.copyTo(q2);
    // normalize(dftImage1, dftImage1, 0, 1, CV_MINMAX);
    imshow("***", dftImage1);
    Scalar s0 = sum(dftImage1);
    int m = dftImage1.rows;
    int n = dftImage1.cols;
    Mat gaussianBlur(m, n, CV_32F);
    float D0 = 2 * 50 * 50;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            float d = (i - m / 2) * (i - m / 2) + (j - n / 2) * (j - n / 2);
            float m = -d / D0;
            gaussianBlur.at<float>(i, j) = exp(m);
        }
    }
    multiply(dftImage1, gaussianBlur, gaussianBlur);
    int cx1 = gaussianBlur.cols / 2;
    int cy1 = gaussianBlur.rows / 2;

    Mat r0(gaussianBlur, Rect(0, 0, cx1, cy1));     // Top-Left
    Mat r1(gaussianBlur, Rect(cx1, 0, cx1, cy1));   // Top-Right
    Mat r2(gaussianBlur, Rect(0, cy1, cx1, cy1));   // Bottom-Left
    Mat r3(gaussianBlur, Rect(cx1, cy1, cx1, cy1)); // Bottom-Right

    Mat tmp1;
    r0.copyTo(tmp1);
    r3.copyTo(q0);
    tmp1.copyTo(q3);

    r1.copyTo(tmp1);
    r2.copyTo(r1);
    tmp1.copyTo(r2);
    imshow("gaussian", gaussianBlur);
    idft(gaussianBlur, inverseDFT, DFT_SCALE | DFT_REAL_OUTPUT); // Applying IDFT
    inverseDFT.convertTo(inverseDFTconverted, CV_8U);
    Scalar s1 = sum(gaussianBlur);
    imshow("Output", inverseDFTconverted);

    cout << s0.val[0] << endl;
    cout << s1.val[0];
    waitKey(0);
}
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    // test();
    // return 0;

    w.show();
    return a.exec();
}
