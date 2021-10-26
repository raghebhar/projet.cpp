#include "bus.h"

bus::bus()
{

}

bus::bus(int id,QString marque,QString datefct,int nbrplaces,float kilometrage)//constructeur parametré pour declarer un bus avec ses valeurs directement
{
    this->id=id;
    this->marque=marque;
    this->datefct=datefct;
    this->nbrplaces=nbrplaces;
    this->kilometrage=kilometrage;
}

bool bus::ajouter()
{
    QString k=QString::number(kilometrage);//convertissement kilometrage de float a string
    QSqlQuery q;//requete SQL qui peut s'executer a partir du QT
    q.prepare("insert into bus values(:id,:marque,:datefct,:nbrplaces,:kilometrage)");//preparation de requete
    q.bindValue(":id",id);//injection SQL (securité) remplacement des tags ex::id avec les valeurs
    q.bindValue(":marque",marque);
    q.bindValue(":datefct",datefct);
    q.bindValue(":nbrplaces",nbrplaces);
    q.bindValue(":kilometrage",k);
    return q.exec();//executer

}
bool bus::supprimer(int id)
{
    QSqlQuery q;
    q.prepare("delete from bus where id=:id");
    q.bindValue(":id",id);
    return q.exec();
}
QSqlQueryModel* bus::afficher()//creation du model d'affichage de bus
{
    QSqlQueryModel* model=new QSqlQueryModel();
    model->setQuery("select * from bus");
    return model;
}

