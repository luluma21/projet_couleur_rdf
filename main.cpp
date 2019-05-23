#include "mainwindow.h"
#include <QApplication>


#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <opencv2/objdetect/objdetect.hpp>
#include "opencv2/contrib/contrib.hpp"

#include <cstdio>
#include <iostream>
#include <direct.h>
#include <QFile>

using namespace cv;
using namespace std;


int main(int argc, char *argv[])
{

    QApplication a(argc,argv);
    MainWindow w;
    w.show();
    return a.exec();
}









