#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <opencv2/objdetect/objdetect.hpp>
#include <QMainWindow>
#include <QStringList>
#include <QListWidgetItem>
#include "playlist.h"
#include <QTimer>
#include "camerawidget.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_test_button_clicked();

    void on_change_clicked();

private:
    Ui::MainWindow *ui;
    QList<QString> music_name;
    QList<QString> music_author;
    QList<QString> music_link;
    QList<QListWidgetItem> music_name_author;
    QList<QString> music1;
    QString humor;
    playlist* music;
    QTimer *timer;
    CameraWidget *cameraWidget;

public slots:
    bool testIfOk();
private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
};

#endif // MAINWINDOW_H
