#include "playlist.h"
#include <qstring.h>
#include <qdebug.h>
#include <qfile.h>

playlist::playlist()
{
    QString ligne;
    QString fileName = ":/base_music/BDD_Musiques.txt";
    QFile fichier(fileName);
    fichier.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream flux(&fichier);
    while(!flux.atEnd())
    {
        ligne = flux.readLine();
        list_total.push_back(ligne);
    }
}

QList<QString> playlist::get_element(){
    QList <QString> a;
    for (int i=0;i<list_music.size();i++){
        a.push_back(list_music[i]);
    }
    return a;
}

void playlist::change_element(QString ind){
    list_music.clear();
    int k = 0;
    while (list_total[k] != ind){
        k++;
    }
    for (int i=k+1;i<k+11;i++){
        list_music.push_back(list_total[i]);
    }
}






