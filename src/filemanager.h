#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include "pokemon.h"
#include "pokedex.h"
#include <QMap>
#include <QString>

#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonValue>
#include <QFile>

#define ARCHIVO_POKEMON ".\pokemones.json"

class FileManager
{
public:
    FileManager();

    static int save_pokemon(QMap<int, Pokemon*> pkdx, QString);
};

#endif // FILEMANAGER_H
