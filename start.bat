uic mainwindow.ui -o ui_mainwindow.h
uic dft.ui -o ui_dft.h
uic lsb.ui -o ui_lsb.h

qmake
mingw32-make
.\release\myPicAlgo.exe