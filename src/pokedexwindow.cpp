#include "pokedexwindow.h"

PokedexWindow::PokedexWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->pokedex = new Pokedex;
    this->setWindowTitle("Mini-Pokedex");
    this->setFixedSize(ANCHO_VENTANA_MAIN, LARGO_VENTANA_MAIN);
    this->inicializa_widget_principal();
    this->conecta_signals();

}

PokedexWindow::~PokedexWindow()
{
}

void PokedexWindow::inicializa_widget_principal()
{
    QStringList opcionesComboString = {"N/A","Agua","Fuego","Planta","Electrico","Tierra","Roca","Volador","Veneno","Normal","Lucha","Psico","Oscuridad","Fantasma","Dragon","Hielo","Acero","Hada","Bicho"};
    QString defaulTextLineEditBuscar = "Nombre del Pokemon";
    // INICIALIZANDO LAYOUTS //
    this->layoutVBoxPrincipal = new QVBoxLayout();
    this->layoutVBoxListaMostrar = new QHBoxLayout();
    this->layoutVBoxMostrar = new QVBoxLayout();
    this->layoutFormAddFilterSeek = new QFormLayout();

    // INICIALIZANDO WIGETS //
    this->widgetImagen = new QLabel();
    this->widgetImagen->setFixedSize(ANCHO_IMAGEN, LARGO_IMAGEN);
    this->widgetImagen->setAlignment(Qt::AlignHCenter);

    this->widgetListaDatos = new QListWidget();
    this->widgetListaDatos->setMaximumWidth(ANCHO_LIST_WIDGET_DATOS);

    this->widgetBotonIngresar = new QPushButton("Agregar");
    this->widgetBotonIngresar->setMaximumWidth(ANCHO_BOTON_AGREGAR);
    this->widgetBotonEditar = new QPushButton("Editar");
    this->widgetBotonEditar->setMaximumWidth(ANCHO_BOTON_AGREGAR);

    this->widgetComboBoxOrdenar = new QComboBox();
    this->widgetComboBoxOrdenar->addItems(opcionesComboString);
    this->widgetComboBoxOrdenar->setMaximumWidth(ANCHO_COMBOBOX);
    this->widgetComboBoxOrdenar2 = new QComboBox();
    this->widgetComboBoxOrdenar2->addItems(opcionesComboString);
    this->widgetComboBoxOrdenar2->setMaximumWidth(ANCHO_COMBOBOX);

    this->widgetLineEditBuscar = new QLineEdit();
    this->widgetLineEditBuscar->setPlaceholderText(defaulTextLineEditBuscar);
    this->widgetLineEditBuscar->setMaximumWidth(ANCHO_LINE_EDIT_BUSCAR);
    //
    //
    //
    this->leId = new QLineEdit();
    this->leId->setEnabled(false);

    this->leNombre = new QLineEdit();
    this->leNombre->setEnabled(false);

    this->leEvolucion = new QLineEdit();
    this->leEvolucion->setEnabled(false);

    this->lePreevol = new QLineEdit();
    this->lePreevol->setEnabled(false);

    this->leDescripcion = new QLineEdit();
    this->leDescripcion->setEnabled(false);

    this->leTipo1 = new QLineEdit();
    this->leTipo1->setEnabled(false);

    this->leTipo2 = new QLineEdit();
    this->leTipo2->setEnabled(false);

    this->leImgPath = new QLineEdit();
    this->leImgPath->setEnabled(false);
    //
    //
    //
    this->widgetCentral = new QWidget();

    // ORGANIZANDO WIDGETS Y LAYOUTS //
    this->layoutVBoxMostrar->addWidget(this->leId);
    this->layoutVBoxMostrar->addWidget(this->leNombre);
    this->layoutVBoxMostrar->addWidget(this->leEvolucion);
    this->layoutVBoxMostrar->addWidget(this->lePreevol);
    this->layoutVBoxMostrar->addWidget(this->leDescripcion);
    this->layoutVBoxMostrar->addWidget(this->leTipo1);
    this->layoutVBoxMostrar->addWidget(this->leTipo2);
    this->layoutVBoxMostrar->addWidget(this->leImgPath);
    //
    //
    //
    this->layoutVBoxListaMostrar->addWidget(this->widgetListaDatos);
    this->layoutVBoxListaMostrar->addLayout(this->layoutVBoxMostrar);
    //
    //
    //
    this->layoutFormAddFilterSeek->addRow(NULL, this->widgetBotonIngresar);
    this->layoutFormAddFilterSeek->addRow(NULL, this->widgetBotonEditar);
    this->layoutFormAddFilterSeek->addRow("Filtrar tipo1 :", this->widgetComboBoxOrdenar);
    this->layoutFormAddFilterSeek->addRow("Filtrar tipo2 :", this->widgetComboBoxOrdenar2);
    this->layoutFormAddFilterSeek->addRow("Buscar :", this->widgetLineEditBuscar);
    //
    //
    //
    this->layoutVBoxPrincipal->addWidget(this->widgetImagen);
    this->layoutVBoxPrincipal->addLayout(this->layoutVBoxListaMostrar);
    this->layoutVBoxPrincipal->addLayout(this->layoutFormAddFilterSeek);
    //
    //
    //
    this->widgetCentral->setLayout(layoutVBoxPrincipal);
    this->setCentralWidget(this->widgetCentral);
}

    //DEFIENDO SIGNALS//
void PokedexWindow::conecta_signals()
{
    QObject::connect(this->widgetBotonIngresar, SIGNAL(clicked()), this, SLOT(nuevo_pokemon()));
    QObject::connect(this->widgetBotonEditar, SIGNAL(clicked()), this, SLOT(edita_pokemon()));
    QObject::connect(this->widgetListaDatos, SIGNAL(currentTextChanged(QString)), this, SLOT(item_selected_list(QString)));
    QObject::connect(this->widgetLineEditBuscar, SIGNAL(textChanged(QString)), SLOT(seach_lineEdit(QString)));
    QObject::connect(this->widgetComboBoxOrdenar, SIGNAL(activated(int)), this, SLOT(filter_tipo1(int)));
    QObject::connect(this->widgetComboBoxOrdenar2, SIGNAL(activated(int)), this, SLOT(filter_tipo2(int)));
}

    // DEFINIENDO SLOTS//
void PokedexWindow::nuevo_pokemon()
{
    NewPokemonWindow n(AGREGAR, NULL);
    if(n.exec() == QDialog::Accepted){
        agregar_a_pokedex(n.toma_info_pokemon());
        this->pokedex->guarda_pokemon();
    }
    else{

    }
}

void PokedexWindow::edita_pokemon()
{
    if(this->selected == "")
        return;
    int ide = -1;
    Q_FOREACH(Pokemon* i, this->pokedex->obtiene_todos_pokemon()){
        if(i->get_name()==this->selected)
            ide = i->get_id();
    }
    if(ide==-1)
        return;
    NewPokemonWindow e(EDITAR, this->pokedex->busca_pokemon(ide));
    if(e.exec() == QDialog::Accepted){
        agregar_a_pokedex(e.toma_info_pokemon());
    }
    else{

    }
}

void PokedexWindow::item_selected_list(QString str)
{
    this->selected = str;

    this->setear_informacionMostrada();
    Pokemon *j = NULL;
    Q_FOREACH(Pokemon* i, this->pokedex->obtiene_todos_pokemon()){
        if(str == i->get_name()){
            j=i;
        }
    }
    this->actualizar_informacionMostrada(j);
}

void PokedexWindow::seach_lineEdit(QString str)
{
    this->str = str;
    this->actualizar_listaWidget(this->f1, this->f2, this->str);
}

void PokedexWindow::filter_tipo1(int index)
{
    this->f1 = index;
    this->actualizar_listaWidget(this->f1, this->f2, this->str);
}

void PokedexWindow::filter_tipo2(int index)
{
    this->f2 = index;
    this->actualizar_listaWidget(this->f1, this->f2, this->str);
}


    // DEFINIENDO METODOS AUX//
void PokedexWindow::agregar_a_pokedex(Pokemon *p)
{
    this->pokedex->nuevo_pokemon(p);
    this->actualizar_listaWidget(this->f1, this->f2, this->str);
}
//
void PokedexWindow::actualizar_listaWidget(int _f1, int _f2, QString _str)
{
    this->widgetListaDatos->clear();
    Q_FOREACH(Pokemon* i, this->pokedex->filtrar_por_tipo(_f1, _f2, _str)){
        this->widgetListaDatos->addItem(i->get_name());
    }
}
//
void PokedexWindow::actualizar_informacionMostrada(Pokemon *p)
{
    if(!p){
       return;
    }
    QPixmap image(p->get_imgPath());
    this->widgetImagen->setPixmap(image);
    this->leId->setText(QString::number(p->get_id()));
    this->leNombre->setText(p->get_name());

    this->leEvolucion->setText(darEvolucionesPrevol(p->get_evolution(), 0));
    this->lePreevol->setText(darEvolucionesPrevol(p->get_prevolution(), 1));
    this->leDescripcion->setText(p->get_description());
    this->leTipo1->setText(this->darTipo_conID(p->get_tipo1()));
    this->leTipo2->setText(this->darTipo_conID(p->get_tipo2()));
    this->leImgPath->setText(p->get_imgPath());
}

void PokedexWindow::setear_informacionMostrada()
{
    this->leId->setText(" ");
    this->leNombre->setText(" ");
    this->leEvolucion->setText(" ");
    this->lePreevol->setText(" ");
    this->leDescripcion->setText(" ");
    this->leTipo1->setText(" ");
    this->leTipo2->setText(" ");
    this->leImgPath->setText(" ");
}

QString PokedexWindow::darTipo_conID(int id)
{
    QList tiposPokemones = {"N/A","Agua","Fuego","Planta","Electrico","Tierra","Roca","Volador","Veneno","Normal","Lucha","Psico","Oscuridad","Fantasma","Dragon","Hielo","Acero","Hada","Bicho"};
    return tiposPokemones.at(id);
}

QString PokedexWindow::darEvolucionesPrevol(int id, int evolPre)
{
    if(evolPre==0){//Evolucion
        QString name = "Sin registro Evolucion";
        Q_FOREACH(Pokemon* i, this->pokedex->obtiene_todos_pokemon()){
            if(i->get_id()==id)
                name = i->get_name();
        }
        return name;
    }
    else{//Prevolucion
        QString name = "Sin registro Pre-evol";
        Q_FOREACH(Pokemon* i, this->pokedex->obtiene_todos_pokemon()){
            if(i->get_id()==id)
                name = i->get_name();
        }
        return name;
    }
}


