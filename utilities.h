#ifndef UTILITIES_H
#define UTILITIES_H
#include "mainwindow.h"
#include <QApplication>
#include"classification.h"

#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <opencv2/objdetect/objdetect.hpp>
#include "opencv2/contrib/contrib.hpp"

#include <cstdio>
#include <iostream>
#include <direct.h>

using namespace cv;
using namespace std;

class utilities
{
public:
    utilities();
    vector<cv::String> get_files(String path,String emotions []);
};

#endif // UTILITIES_H
