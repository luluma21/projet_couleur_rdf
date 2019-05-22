#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    timer =new QTimer;
    connect(timer, SIGNAL(timeout()), ui->widget,SLOT(refresh()));
    connect(timer, SIGNAL(timeout()), this,SLOT(testIfOk()));
    timer->start(10);
}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::testIfOk(){
    if(ui->widget->getEllipseColor()==Scalar(0,0,255)) ui->pushButton->setEnabled(false);
    else if(ui->widget->getEllipseColor()==Scalar(0,255,0)) ui->pushButton->setEnabled(true);
    if(!ui->widget->getRunning()) ui->pushButton_2->setEnabled(true);
    else if(ui->widget->getRunning()) ui->pushButton_2->setEnabled(false);
}

void MainWindow::on_pushButton_clicked()
{
    if(ui->widget->getRunning()) ui->widget->changeRunning();
}

void MainWindow::on_pushButton_2_clicked()
{
    if(!ui->widget->getRunning()) ui->widget->changeRunning();
}
