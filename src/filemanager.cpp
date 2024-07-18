#include "filemanager.h"

FileManager::FileManager()
{

}

int FileManager::save_pokemon(QMap<int, Pokemon*> pkdx, QString fileName){
    int resultado = 0;
    QJsonArray arregloPokemons;
    QJsonObject objetoPrincipal;
    QJsonDocument jsonDocument;
    QFile archivo;

    Q_FOREACH(Pokemon* p, pkdx){
        arregloPokemons.push_back(p->to_json());
    }
    objetoPrincipal.insert("Pokedex", arregloPokemons);
    jsonDocument.setObject(objetoPrincipal);

    archivo.setFileName(fileName);
    if(!archivo.open(QIODevice::Text | QIODevice::WriteOnly))
        return resultado;
    archivo.write(jsonDocument.toJson());
    archivo.close();
    resultado = 1;
    return resultado;
}
