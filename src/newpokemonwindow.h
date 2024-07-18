#ifndef NEWPOKEMONWINDOW_H
#define NEWPOKEMONWINDOW_H

#include "pokemon.h"

#include <QDialog>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QFormLayout>
#include <QLineEdit>
#include <QComboBox>
#include <QDialogButtonBox>
#include <QPushButton>
#include <QList>

#define ANCHO_VENTANA_DIALOG 300
#define LARGO_VENTANA_DIALOG 300

enum modosNewWindow{
    EDITAR = -1,
    AGREGAR
};

class NewPokemonWindow : public QDialog
{
    Q_OBJECT
public:
    NewPokemonWindow(int modo, Pokemon* pk, QWidget *parent = nullptr);


    //METODOS//
    int get_modo();
    Pokemon* toma_info_pokemon();
private:
    int modo;
    Pokemon* pokemon;
    Pokemon* pokemonEditar;
    // DECLARANDO LAYOUTS //
    QVBoxLayout* layoutVBoxPrincipal;
    QHBoxLayout* layoutHBoxIdNombre;
    QHBoxLayout* layoutHBoxBotonera;
    QFormLayout* layoutFormDatos;

    // DECLARANDO WIDGETS //
    QLineEdit* lineEditId;
    QLineEdit* lineEditNombre;
    QLineEdit* lineEditIdEvolicion;
    QLineEdit* lineEditIdPreevol;
    QLineEdit* lineEditDescripcion;
    QComboBox* comboBoxTipo1;
    QComboBox* comboBoxTipo2;
    QLineEdit* lineEditImgPath;
    QDialogButtonBox* botonera;

    //METODOS AUX//
    void inicializa_layout_principal();
    void conecta_signals();
    void toma_datos_interfaz();
};

#endif // NEWPOKEMONWINDOW_H
