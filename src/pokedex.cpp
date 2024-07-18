#include "pokedex.h"

Pokedex::Pokedex()
{

}

void Pokedex::nuevo_pokemon(Pokemon *pokemon)
{
    this->registro.insert(pokemon->get_id(), pokemon);
}


QMap<int, Pokemon *> Pokedex::obtiene_todos_pokemon()
{
    return this->registro;
}


Pokemon *Pokedex::busca_pokemon(int id)
{
    Pokemon* j = NULL;
    Q_FOREACH(Pokemon *i, this->registro){
        if(i->get_id() == id)
            j=i;
    }
    return j;
}

QMap<int, Pokemon *> Pokedex::filtrar_por_tipo(int ind1, int ind2, QString str)
{
    QMap<int, Pokemon *> registroNuevo;
    if(ind1==0 && ind2==0)
        return this->join_comboLineEdit_edit(this->registro, str); //registro
    else if(ind2==0 && ind1!=0){
        Q_FOREACH(Pokemon* i, this->registro){
            if(i->get_tipo1()==ind1){
                registroNuevo.insert(i->get_id(), i);
            }
        }
        return this->join_comboLineEdit_edit(registroNuevo, str);
    }
    else if(ind1==0 && ind2!=0){
        Q_FOREACH(Pokemon* i, this->registro){
            if(i->get_tipo2()==ind2){
                registroNuevo.insert(i->get_id(), i);
            }
        }
        return this->join_comboLineEdit_edit(registroNuevo, str);
    }
    else{
        Q_FOREACH(Pokemon* i, this->registro){
            if(i->get_tipo1()==ind1 && i->get_tipo2()==ind2){
                registroNuevo.insert(i->get_id(), i);
            }
        }
        return this->join_comboLineEdit_edit(registroNuevo, str);
    }
}

void Pokedex::guarda_pokemon()
{
    FileManager::save_pokemon(this->registro, ARCHIVO_POKEMON);
}


    //METODOS AUX//
QMap<int, Pokemon *> Pokedex::join_comboLineEdit_edit(QMap<int, Pokemon *> qmap, QString str)
{
    if(str == "")
        return qmap;
    QMap<int, Pokemon *> nuevoRegistro;
    Q_FOREACH(Pokemon* i, qmap){
        if(i->get_name().contains(str, Qt::CaseInsensitive))
            nuevoRegistro.insert(i->get_id(), i);
    }
    return nuevoRegistro;
}
