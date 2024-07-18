#include "pokemon.h"

Pokemon::Pokemon(int id, QString name, int evol, int prevol, QString descrip, int t1, int t2, QString ip)
{
    this->id = id;
    this->name = name;
    this->evolution = evol;
    this->preevolution = prevol;
    this->descripcion = descrip;
    this->tipo1 = t1;
    this->tipo2 = t2;
    this->imgPath = ip;
}

int Pokemon::get_id()
{
    return this->id;
}

QString Pokemon::get_name()
{
    return this->name;
}

int Pokemon::get_evolution()
{
    return this->evolution;
}

int Pokemon::get_prevolution()
{
    return this->preevolution;
}

QString Pokemon::get_description()
{
    return this->descripcion;
}

int Pokemon::get_tipo1()
{
    return this->tipo1;
}

int Pokemon::get_tipo2()
{
    return this->tipo2;
}

QString Pokemon::get_imgPath()
{
    return this->imgPath;
}

// METODO JASON//
QJsonObject Pokemon::to_json()
{
    QJsonObject objeto;

    objeto.insert("id", this->get_id());
    objeto.insert("nombre", this->get_name());
    objeto.insert("evolucion", this->get_evolution());
    objeto.insert("prevolucion", this->get_prevolution());
    objeto.insert("descripcion", this->get_description());
    objeto.insert("tipo 1", this->get_tipo1());
    objeto.insert("tipo 2", this->get_tipo2());
    objeto.insert("image path", this->get_imgPath());

    return objeto;
}

