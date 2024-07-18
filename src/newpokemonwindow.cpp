#include "newpokemonwindow.h"

NewPokemonWindow::NewPokemonWindow(int modo, Pokemon* pk, QWidget* parent) : QDialog(parent)
{
    this->pokemonEditar = pk;
    this->modo = modo;
    this->setFixedSize(ANCHO_VENTANA_DIALOG, LARGO_VENTANA_DIALOG);
    inicializa_layout_principal();
    conecta_signals();
}


int NewPokemonWindow::get_modo()
{
    return this->modo;
}

void NewPokemonWindow::inicializa_layout_principal()
{
    if(this->modo==AGREGAR)
        this->setWindowTitle("Mini-Pokedex Agregar");
    else if(this->modo==EDITAR)
        this->setWindowTitle("Mini-Pokedex Editar");
    QStringList opcionesTipo = {"N/A","Agua","Fuego","Planta","Electrico","Tierra","Roca","Volador","Veneno","Normal","Lucha","Psico","Oscuridad","Fantasma","Dragon","Hielo","Acero","Hada","Bicho"};
    //DEFINIENDO LAYOUTS //
    this->layoutVBoxPrincipal = new QVBoxLayout();
    this->layoutHBoxIdNombre = new QHBoxLayout();
    this->layoutHBoxBotonera = new QHBoxLayout();
    this->layoutFormDatos = new QFormLayout();

    // DEFINIENDO WIDGETS //
    this->lineEditId = new QLineEdit();
    if(this->modo==EDITAR){
        this->lineEditId->setText(QString::number(this->pokemonEditar->get_id()));
        this->lineEditId->setEnabled(false);
    }
    else
        this->lineEditId->setPlaceholderText("ID Pokemon");
    //
    this->lineEditNombre = new QLineEdit();
    if(this->modo==EDITAR){
        this->lineEditNombre->setText(this->pokemonEditar->get_name());
    }
    else
        this->lineEditNombre->setPlaceholderText("Nombre Pokemon");
    //
    this->lineEditIdEvolicion = new QLineEdit();
    if(this->modo==EDITAR)
        this->lineEditIdEvolicion->setText(QString::number(this->pokemonEditar->get_evolution()));

    this->lineEditIdPreevol = new QLineEdit();
    if(this->modo==EDITAR)
        this->lineEditIdPreevol->setText(QString::number(this->pokemonEditar->get_prevolution()));

    this->lineEditDescripcion = new QLineEdit();
    if(this->modo==EDITAR)
        this->lineEditDescripcion->setText(this->pokemonEditar->get_description());
    //
    this->comboBoxTipo1 = new QComboBox();
    this->comboBoxTipo1->addItems(opcionesTipo);
    //
    this->comboBoxTipo2 = new QComboBox();
    this->comboBoxTipo2->addItems(opcionesTipo);
    //
    this->lineEditImgPath = new QLineEdit();
    if(this->modo==EDITAR)
        this->lineEditImgPath->setText(this->pokemonEditar->get_imgPath());
    //
    this->botonera = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel);

    // ORGANIZANDO WIDGETS Y LAYOUTS //
    this->layoutHBoxIdNombre->addWidget(this->lineEditId);
    this->layoutHBoxIdNombre->addWidget(this->lineEditNombre);

    this->layoutFormDatos->addRow("ID Evolucion: ", this->lineEditIdEvolicion);
    this->layoutFormDatos->addRow("ID Preevolucion: ", this->lineEditIdPreevol);
    this->layoutFormDatos->addRow("Descripcion: ", this->lineEditDescripcion);
    this->layoutFormDatos->addRow("Tipo 1: ", this->comboBoxTipo1);
    this->layoutFormDatos->addRow("Tipo 2: ", this->comboBoxTipo2);
    this->layoutFormDatos->addRow("image path: ", this->lineEditImgPath);

    this->layoutHBoxBotonera->addWidget(this->botonera);

    this->layoutVBoxPrincipal->addLayout(this->layoutHBoxIdNombre);
    this->layoutVBoxPrincipal->addLayout(this->layoutFormDatos);
    this->layoutVBoxPrincipal->addLayout(this->layoutHBoxBotonera);

    this->setLayout(this->layoutVBoxPrincipal);
}

void NewPokemonWindow::conecta_signals()
{
    QObject::connect(this->botonera, SIGNAL(accepted()), this, SLOT(accept()));
    QObject::connect(this->botonera, SIGNAL(rejected()), this, SLOT(reject()));
}


    //METODOS//
Pokemon *NewPokemonWindow::toma_info_pokemon()
{
    this->toma_datos_interfaz();
    return this->pokemon;
}

void NewPokemonWindow::toma_datos_interfaz()
{
    int ide = this->lineEditId->text().toInt();
    QString nombre = this->lineEditNombre->text();
    int idEvol = this->lineEditIdEvolicion->text().toInt();
    int idPrev = this->lineEditIdPreevol->text().toInt();
    QString des = this->lineEditDescripcion->text();
    int tipo1 = this->comboBoxTipo1->currentIndex();
    int tipo2 = this->comboBoxTipo2->currentIndex();
    QString ip = this->lineEditImgPath->text();
    this->pokemon = new Pokemon(ide, nombre, idEvol, idPrev, des, tipo1, tipo2, ip);
}
