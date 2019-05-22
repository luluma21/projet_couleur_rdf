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
    ui->setupUi(this);
    humor = "Colere";
    music = new playlist();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    if (ui->listWidget->selectedItems().size()==1){
       int ind = 0;
       QList<QListWidgetItem*> ele = ui->listWidget->selectedItems();
       QString ele1 = ele[0]->text();
       for (int k=0;k<music_name.size();k++){
           if (ele1 == music_name[k] + "\n" + music_author[k]){
               QString command = "cmd /c start " + music_link[k];
               qDebug() << command;
               QProcess::execute(command);
           }
       }
    }
}

void MainWindow::on_test_button_clicked()
{
    music_name.clear();
    music_author.clear();
    music_link.clear();
    ui->listWidget->clear();
    QString fileName = ":/base_music/icone_music.png";
    QIcon newicon = QIcon(fileName);
    music->change_element(humor);
    music1 = music->get_element();
    for (int k=0;k<music1.size();k++){
        QListWidgetItem* newitem;
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
        //newItem->setIconSize(QSize(100, 100));
        newItem->setIcon(newicon);
        if (k%2 == 0){
            newItem->setBackground(QBrush(QColor(255, 220, 220, 255)));
        }
        //newItem->(QSize(100, 100));
        ui->listWidget->setIconSize(QSize(75, 75));
        ui->listWidget->addItem(newItem);
        //music_name_author.push_back(QListWidgetItem(music_name[k] + "\n" + music_author[k]));
        //music_name_author.push_back(music1[k].mid(i,j-i) + "\n" + music1[k].mid(i,j-i));
    }
    for (int k=0;k<music_name_author.size();k++){
  //      ui->listWidget->addItem(music_name_author[k]);
    }
    //ui->listWidget->addItems(music_name_author);

    ui->label_2->setText(humor);

    connect(ui->music_button,SIGNAL(clicked()),this,SLOT(on_pushButton_clicked()));
}

void MainWindow::on_change_clicked()
{
    humor = "Neutre";
}
