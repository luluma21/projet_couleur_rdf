#include "classification.h"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <opencv2/objdetect/objdetect.hpp>
#include<iostream>

classification::classification()
{
    cv::CascadeClassifier face_cascade;
    if(!face_cascade.load(":/classifieurs/haarcascade_frontalface_alt.xml")){
        std::cout<<"ERROR";
    }
    else {
        std::cout<<"OUVERT";
    }
}


