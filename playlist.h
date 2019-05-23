#ifndef PLAYLIST_H
#define PLAYLIST_H

#include <qstring.h>
#include <QList>

class playlist
{
public:
    playlist();
    QList<QString> get_element();
    void change_element(QString ind);

private:
    std::vector<QString> list_total;
    std::vector<QString> list_music;
};

#endif // PLAYLIST_H
