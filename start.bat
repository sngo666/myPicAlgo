uic mainwindow.ui -o ui_mainwindow.h
uic dft.ui -o ui_dft.h
uic idft.ui -o ui_idft.h
qmake
mingw32-make
.\release\myPicAlgo.exe