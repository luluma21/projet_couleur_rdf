#ifndef CAMERAWIDGET_H
#define CAMERAWIDGET_H

#include <QWidget>
#include "opencv2/opencv.hpp"
#include <QLabel>

using namespace cv;

class CameraWidget : public QWidget
{
    Q_OBJECT
public:
    //Constructeur
    explicit CameraWidget(QWidget *parent = nullptr);

    bool getRunning(){return running;}

    void changeRunning(){running=!running;}

    Scalar getEllipseColor(){return ellipse_color;}

    //Déstructeur de l'objet et désallocation des attributs
    ~CameraWidget();

private:
    VideoCapture cap;
    double frameWidth=cap.get(CV_CAP_PROP_FRAME_WIDTH); //longueur de la caméra
    double frameHeight=cap.get(CV_CAP_PROP_FRAME_HEIGHT); //largeur de la caméra

    Scalar ellipse_color = Scalar(0,0,255); // couleur de l'ellipse


    //VideoCapture pour la webcam
     VideoCapture * webCam_;
     //Qlabel d'affichage de la caméra
     QLabel *screen;
     //Image courante
     QImage *CurentImage;
     //Feuille de Haar pour détéction des mains
     CascadeClassifier fist_cascade ;
     //Booléen vrai si la capture n'est pas encore faite
     bool running;

     // Compteur pour exécuter l'alogorithme de détéction tout les 50ms
     int counter =0;



signals:

public slots:
      //Méthode de rafraichissement de l'affichage et éxecution de l'algorithme de détéction
         void refresh();
};

#endif // CAMERAWIDGET_H
