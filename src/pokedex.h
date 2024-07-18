#ifndef POKEDEX_H
#define POKEDEX_H

#include <QMap>
#include "pokemon.h"
#include "filemanager.h"

enum tipoFilters{
    TIPO1 = 1,
    TIPO2
};

class Pokedex
{
private:
    QMap<int , Pokemon*> registro;
    QMap<int, Pokemon*> join_comboLineEdit_edit(QMap<int, Pokemon*>, QString str);
public:
    Pokedex();
    //metodos//
    void nuevo_pokemon(Pokemon* pokemon);
    QMap<int , Pokemon*> obtiene_todos_pokemon();
    Pokemon* busca_pokemon(int id);
    QMap<int, Pokemon*> filtrar_por_tipo(int ind1, int ind2, QString str);

    void guarda_pokemon();
    //METODOS AUX//
};

#endif // POKEDEX_H
