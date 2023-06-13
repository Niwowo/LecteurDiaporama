#include "modifierdiaporama.h"
#include "ui_modifierdiaporama.h"

ModifierDiaporama::ModifierDiaporama(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ModifierDiaporama)
{
    ui->setupUi(this);
    mydb.openDataBase();
    QSqlQuery query;
    QStringList header;
    header << "Id" << "Titre" << "Famille" << "Chemin d'accès" ;
    query.exec("SELECT * from Diapos");
    for(unsigned int i = 0; query.next(); i++)
    {
        QString id = query.value(0).toString();
        QString titre = query.value(1).toString();
        QString famille = query.value(2).toString();
        QString chemin = query.value(3).toString();

        qDebug() << id << titre << famille << chemin << Qt::endl;

        // On fixe le nombre de colonnes
        ui->tableWidget->setColumnCount(header.size());
        // On applique les noms des colonnes
        ui->tableWidget->setHorizontalHeaderLabels(header);
        QHeaderView * headerView = ui->tableWidget->horizontalHeader();
        headerView->setSectionResizeMode(QHeaderView::Stretch);

        QTableWidgetItem *id1 = new QTableWidgetItem(QString(id));
        QTableWidgetItem *titre2 = new QTableWidgetItem(QString(titre));
        QTableWidgetItem *famille3 = new QTableWidgetItem(QString(famille));
        QTableWidgetItem *chemin4 = new QTableWidgetItem(QString(chemin));

        ui->tableWidget->insertRow(i);

        ui->tableWidget->setItem(i, 0, id1);
        ui->tableWidget->setItem(i, 1, titre2);
        ui->tableWidget->setItem(i, 2, famille3);
        ui->tableWidget->setItem(i, 3, chemin4);
    }
    mydb.closeDataBase();

    connect(ui->tableWidget, &QTableWidget::itemChanged, this, &ModifierDiaporama::itemModified);
    connect(ui->bQuitter,SIGNAL(clicked()),this,SLOT(reject()));
}

ModifierDiaporama::~ModifierDiaporama()
{
    delete ui;
}

void ModifierDiaporama::itemModified(QTableWidgetItem *item)
{
    /* Cette fonction permet de modifier les données contenues dans la BD. N'ayant pas les droits de modification,
       cette fonction ne fonctionnera pas avec mes accès. */

    // Récupérer les informations de la ligne modifiée
    int row = item->row();
    QString id = ui->tableWidget->item(row, 0)->text();
    QString titre = ui->tableWidget->item(row, 1)->text();
    QString famille = ui->tableWidget->item(row, 2)->text();
    QString chemin = ui->tableWidget->item(row, 3)->text();


    // Mettre à jour les données dans la base de données
    mydb.openDataBase();
    qDebug() << "je change les données" << Qt::endl;
    QSqlQuery query;
    query.prepare("UPDATE Diapos SET Titre = :titre, Famille = :famille, Chemin = :chemin WHERE Id = :id");
    query.bindValue(":titre", titre);
    query.bindValue(":famille", famille);
    query.bindValue(":chemin", chemin);
    query.bindValue(":id", id);
    query.exec();
    mydb.closeDataBase();
}

