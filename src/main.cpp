#include "pokedexwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    PokedexWindow w;
    w.show();
    return a.exec();
}
