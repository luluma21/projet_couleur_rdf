#include "mainwindow.h"
#include <QApplication>
#include "classification.h"

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
    for (int i = 1;i<5;i++) {
        QFile file(":/filters/f"+(QString)i);
    }
    //filters declaration
    cv::CascadeClassifier face_cascade1,face_cascade2, face_cascade3, face_cascade4;
    face_cascade1.load("./haarcascade_frontalface_alt.xml"); //Renvoie un bool
    face_cascade2.load(":/filters/f2");
    face_cascade3.load(":/filters/f3");
    face_cascade4.load(":/filters/f4");
    String emotions[]={"Joie","Colere","Neutre","Tristesse"};
//Data preparation
    //Creation of the faces folders
    //D:/Cours/Semestre8/ChefdOeuvre/faces
    String directory = "D:/Cours/Semestre8/ChefdOeuvre/faces";
    //C:/Users/Florian/Desktop/base_d_image
    //D:/Cours/Semestre8/ChefdOeuvre/BasedImages
    String initial_directory = "D:/Cours/Semestre8/ChefdOeuvre/BasedImages";
    mkdir(directory.c_str());

    for (int i = 0; i < (int) emotions->size(); i++) {
        String temp = directory+"/"+emotions[i];
        mkdir(temp.c_str());
        //Iterate over a directory & detect faces
        vector<cv::String> fn;
        String temp2=initial_directory +"/"+emotions[i];
        glob(temp2.c_str(), fn, false);


        size_t count = fn.size(); //number of png files in images folder
        int counter = 0;
        for (size_t j=0; j<count; j++){
            //images.push_back(imread(fn[i])); // peut être utile si on veut lire toutes les images à la suite
            Mat image =  imread(fn[j]);
            Mat image_gray;
            vector<Rect> faces,faces1,faces2,faces3,faces4;
            cvtColor(image,image_gray,COLOR_BGR2GRAY);
            face_cascade1.detectMultiScale( image_gray, faces1, 1.1, 4, 0|CV_HAAR_SCALE_IMAGE, Size(60, 60) );
            face_cascade2.detectMultiScale( image_gray, faces2, 1.1, 4, 0|CV_HAAR_SCALE_IMAGE, Size(60, 60) );
            face_cascade3.detectMultiScale( image_gray, faces3, 1.1, 4, 0|CV_HAAR_SCALE_IMAGE, Size(60, 60) );
            face_cascade4.detectMultiScale( image_gray, faces4, 1.1, 4, 0|CV_HAAR_SCALE_IMAGE, Size(60, 60) );

            if (faces1.size()==1)faces = faces1;
            else if (faces2.size()==1)faces = faces2;
            else if (faces3.size()==1)faces = faces3;
            else if (faces4.size()==1)faces = faces4;
             //Resize of the image around the face
            if (faces.size()>0){
            counter++;
            Rect r = faces[0];
            image_gray = image_gray(r);
            char buffer[50];
            String te = temp+ "/" + "%i" + ".png";
            sprintf(buffer,te.c_str(),counter);
            //save the faces in the new directories
            imwrite(buffer,image_gray);}


         }
        cout<<emotions[i]<<" : "<<(int)((float)counter*100/count)<<" % faces detected\n";


        }
        //Ptr<FaceRecognizer> fishface = cv::createFisherFaceRecognizer(); //treshhold ??
        //create a 80/20 training set for each class
        vector<Mat> training_data,prediction_data;
        for (int i=0;i<(int)emotions->size();i++){


        }

        w.show();
        return a.exec();
}









