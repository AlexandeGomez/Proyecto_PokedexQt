#ifndef POKEDEXWINDOW_H
#define POKEDEXWINDOW_H

#include "newpokemonwindow.h"
#include "pokedex.h"

#include <QMainWindow>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QListWidget>
#include <QPushButton>
#include <QComboBox>
#include <QLineEdit>
#include <QFormLayout>
#include <QStringList>
#include <QMessageBox>
#include <QLabel>
#include <QPixmap>

// CONSTANTES //
#define ANCHO_COMBOBOX 120
#define ANCHO_VENTANA_MAIN 300
#define LARGO_VENTANA_MAIN 450
#define ANCHO_BOTON_AGREGAR 120
#define ANCHO_LINE_EDIT_BUSCAR 150
#define ANCHO_LIST_WIDGET_DATOS 150
#define ANCHO_IMAGEN 100
#define LARGO_IMAGEN 100

class PokedexWindow : public QMainWindow
{
    Q_OBJECT
public:
    PokedexWindow(QWidget *parent = nullptr);
    ~PokedexWindow();

private:
    // DEFINIENDO LAYOUTS //
    QVBoxLayout* layoutVBoxPrincipal;
    QHBoxLayout* layoutVBoxListaMostrar;
    QVBoxLayout* layoutVBoxMostrar;
    QFormLayout* layoutFormAddFilterSeek;

    // DEFINIENDO WIGETS //
    QLabel* widgetImagen;
    QListWidget* widgetListaDatos;
    QPushButton* widgetBotonIngresar;
    QPushButton* widgetBotonEditar;
    QComboBox* widgetComboBoxOrdenar;
    QComboBox* widgetComboBoxOrdenar2;
    QLineEdit* widgetLineEditBuscar;

    QLineEdit* leId;
    QLineEdit* leNombre;
    QLineEdit* leEvolucion;
    QLineEdit* lePreevol;
    QLineEdit* leDescripcion;
    QLineEdit* leTipo1;
    QLineEdit* leTipo2;
    QLineEdit* leImgPath;

    QWidget* widgetCentral;

    // REGISTRO //
    Pokedex* pokedex;

    int f1 = 0;
    int f2 = 0;
    QString str = "";

    QString selected = "";

    //METODOS AUX//
    void inicializa_widget_principal();
    void conecta_signals();
    void agregar_a_pokedex(Pokemon*);

    void actualizar_listaWidget(int _f1, int _f2, QString _str);

    void actualizar_informacionMostrada(Pokemon*);
    void setear_informacionMostrada();
    QString darTipo_conID(int id);
    QString darEvolucionesPrevol(int id, int evolPre);
    //SLOTS//
public Q_SLOTS:
    void nuevo_pokemon();
    void edita_pokemon();
    void item_selected_list(QString str);
    void seach_lineEdit(QString str);
    void filter_tipo1(int index);
    void filter_tipo2(int index);
};
#endif // POKEDEXWINDOW_H
