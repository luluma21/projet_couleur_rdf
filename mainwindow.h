#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStringList>
#include <QListWidgetItem>
#include "playlist.h"

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
};

#endif // MAINWINDOW_H
