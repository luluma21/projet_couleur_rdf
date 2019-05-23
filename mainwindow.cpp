#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <Qprocess>
#include "playlist.h"
#include <QString>
#include <QListWidgetItem>
#include <qstringlist.h>
#include <qdebug.h>
#include <QIcon>
#include <QAbstractItemView>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    // ouverture de l'interface
    ui->setupUi(this);
    humor = "Colere";

    // initialisation de la plylist
    music = new playlist();

    // affichage de la vidéo récupéré par la webcam
    timer =new QTimer;
    connect(timer, SIGNAL(timeout()), ui->widget,SLOT(refresh()));
    connect(timer, SIGNAL(timeout()), this,SLOT(testIfOk()));
    timer->start(10);
    connect(ui->music_button,SIGNAL(clicked()),this,SLOT(on_accessButton_clicked()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

// fonction pour accéder à la vidéo sur youtube
void MainWindow::on_accessButton_clicked()
{
    if (ui->listWidget->selectedItems().size()==1){
        QList<QListWidgetItem*> ele;
        ele.clear();
        ele = ui->listWidget->selectedItems();
        QString ele1 = "";
        ele1 = ele[0]->text();
        for (int k=0;k<music_name.size();k++){
            if (ele1 == music_name[k] + "\n" + music_author[k]){
                QString command = "cmd /c start " + music_link[k];
                qDebug() << command;
                QProcess::execute(command);
            }
        }
    }
}

// test de l'humeur et affichage de la playlist
void MainWindow::on_test_button_clicked()
{
    testok = true;
    music_name.clear();
    music_author.clear();
    music_link.clear();
    ui->listWidget->clear();
    QString fileName = ":/base_music/base_music/icone_music.png";
    QIcon newicon = QIcon(fileName);
    music->change_element(humor);
    music1 = music->get_element();
    for (int k=0;k<music1.size();k++){
        int i=0;
        int j=music1[k].indexOf(QString(';'),i);
        music_name.push_back(music1[k].mid(i,j-i));
        i=j+1;
        j=music1[k].indexOf(QString(';'),i);
        music_author.push_back(music1[k].mid(i,j-i));
        music_link.push_back(music1[k].mid(j+1,music1.size()-j));
        QListWidgetItem *newItem = new QListWidgetItem;
        newItem->setText(music_name[k] + "\n" + music_author[k]);
        newItem->setTextAlignment(Qt::AlignHCenter);
        newItem->setTextAlignment(Qt::AlignVCenter);
        newItem->setIcon(newicon);
        if (k%2 == 0){
            newItem->setBackground(QBrush(QColor(255, 220, 220, 255)));
        }
        ui->listWidget->setIconSize(QSize(75, 75));
        ui->listWidget->addItem(newItem);
    }
    for (int k=0;k<music_name_author.size();k++){
    }

    ui->label_2->setText(humor);
humor = "Joie";
}

bool MainWindow::testIfOk(){
    if(ui->widget->getEllipseColor()==Scalar(0,0,255)) ui->pushButton->setEnabled(false);
    else if(ui->widget->getEllipseColor()==Scalar(0,255,0)) ui->pushButton->setEnabled(true);
    if(!ui->widget->getRunning()) {
        ui->pushButton_2->setEnabled(true);
        ui->test_button->setEnabled(true);
    }
    else if(ui->widget->getRunning()) {
        ui->pushButton_2->setEnabled(false);
        ui->test_button->setEnabled(false);
        ui->label_2->hide();
        ui->listWidget->hide();
        testok = false;
        ui->music_button->setEnabled(false);
    }
    if (testok == true){
        ui->label_2->show();
        ui->listWidget->show();
        if (ui->listWidget->selectedItems().size()==1){
            ui->music_button->setEnabled(true);
        }
        else{ui->music_button->setEnabled(false);}
    }
}

void MainWindow::on_pushButton_clicked()
{
    if(ui->widget->getRunning()) ui->widget->changeRunning();
}

void MainWindow::on_pushButton_2_clicked()
{
    if(!ui->widget->getRunning()) ui->widget->changeRunning();
}
