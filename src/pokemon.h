#ifndef POKEMON_H
#define POKEMON_H

#include <QString>
#include <QJsonObject>

class Pokemon
{
private:
    int id;
    QString name;
    int evolution;
    int preevolution;
    QString descripcion;
    int tipo1;
    int tipo2;
    QString imgPath;

public:
    Pokemon(int id, QString name, int evol, int prevol, QString descrip, int t1, int t2, QString ip);
    int get_id();
    QString get_name();
    int get_evolution();
    int get_prevolution();
    QString get_description();
    int get_tipo1();
    int get_tipo2();
    QString get_imgPath();

    QJsonObject to_json();

};

#endif // POKEMON_H

