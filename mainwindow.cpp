#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    ui->tableBus->setModel(bu.afficher());//affecter le modele qu'on a creé sur la tableBus
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    //pour ajouter un bus il faut d'abord creer une instance bus avec tous les informations
    int id=ui->id->text().toInt();
    QString marque=ui->marque->text();
    QString datefct=ui->datefct->text();
    int nbplaces=ui->nbplaces->text().toInt();
    float kilometrage=ui->kilometrage->text().toFloat();//preparation des informations a partir de la maquette
    bus b(id,marque,datefct,nbplaces,kilometrage);//instanciation d'une instance bus avec tous les infos
    b.ajouter();//appelle a la fonction ajouter
}

void MainWindow::on_pushButton_2_clicked()
{
    int id=ui->idSupp->text().toInt();//preparation du l'id qu'on veut supprimer
    bu.supprimer(id);//appelle a la fonction supprimer avec l'id qu'on veut supprimer en parametre
}
