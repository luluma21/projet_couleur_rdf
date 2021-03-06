#include "camerawidget.h"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <opencv2/objdetect/objdetect.hpp>

#include <cstdio>
#include <iostream>
#include <math.h>
#include <QFile>
#include <QTemporaryDir>
#include <QDebug>
#include <QRect>
#include <QLayout>

using namespace cv;
using namespace std;

CameraWidget::CameraWidget(QWidget *parent) : QWidget(parent)
{
    if(!fist_cascade.load("D:/couleur_rdf/projet_couleur_rdf/projet_couleur_rdf/base_music/cascade.xml")){
        cerr<<"Error loading haarcascade"<<endl;
    }

    webCam_=new VideoCapture(0);

    screen = new QLabel;

    QHBoxLayout* lay = new QHBoxLayout();

    lay->addWidget(screen);

    setLayout(lay);

    screen->setGeometry(QRect(10,10,500,500));

    running = true;

}

void CameraWidget::refresh(){

    if(webCam_->isOpened() && running)  // check if we succeeded
    {
        Mat frame,frame_gray;
        std::vector<Rect> face;
        frameWidth=screen->sizeHint().width();
        frameHeight=screen->sizeHint().height();
        if (webCam_->read(frame)) {

            cv::flip(frame,frame,1);
            cv::cvtColor(frame,frame,CV_BGR2RGB);
            cv::cvtColor(frame,frame_gray,COLOR_BGR2GRAY);
            fist_cascade.detectMultiScale( frame_gray, face, 1.1, 4, 0|CV_HAAR_SCALE_IMAGE, Size(60, 60) );

            // centre de l'ellipse
            Point ellipse_center;
            ellipse_center.x = frameWidth/2;
            ellipse_center.y = frameHeight/2;
            // Affichage de l'ellipse
            ellipse(frame, ellipse_center, Size(frameWidth/4, frameHeight/4), 90, 0, 360, ellipse_color, 2, 8);

            if (face.size()>0 && face.size()<2) // on affiche les rectangles et on identifie le mouvement seulement quand on détecte 2 points par la caméra
            {
                // calcul du centre du rectangle (du visage détecté):
                Point face_center;
                face_center.x = face[0].x + (face[0].width/2);
                face_center.y = face[0].y + (face[0].height/2);

                int marge_x = 10;
                int marge_y = 100;

                // test si le visage est compris dans l'ellipse
                // si oui l'ellipse devient verte, sinon elle est rouge
                if (face_center.x>=(ellipse_center.x-marge_x) && face_center.x<=(ellipse_center.x+marge_x)){
                    if (face_center.y>=ellipse_center.y && face_center.y<=(ellipse_center.y+marge_y)){
                        ellipse_color = Scalar(0, 255, 0);
                        // + apparition d'un bouton pour récupérer la frame
                        // + envoie de la frame au traitement
                    }
                    else {
                        ellipse_color = Scalar(0, 0, 255);
                    }
                }
                else {
                    ellipse_color = Scalar(0, 0, 255);
                }
            }

            // Display frame
            CurentImage= new QImage((const unsigned char*)(frame.data),frame.cols,frame.rows,QImage::Format_RGB888);
            // Display on label

            screen->setPixmap(QPixmap::fromImage(*CurentImage));
        }


        else {
            screen->setText("Error capturing the frame");
        }
    }

}

CameraWidget::~CameraWidget(){
    delete webCam_;
}
