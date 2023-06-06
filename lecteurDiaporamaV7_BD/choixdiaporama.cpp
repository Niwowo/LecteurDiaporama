#include "choixdiaporama.h"
#include "ui_choixdiaporama.h"

choixDiaporama::choixDiaporama(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::choixDiaporama)
{
    ui->setupUi(this);
    connect(ui->tableWidget, SIGNAL(clicked(const QModelIndex&)), this, SLOT(lineSelect(const QModelIndex&)));
    QSqlQuery query;
    QStringList header;
    header << "idDiaporama" << "titreDiaporama" << "vitesseDefilement" ;
    // openDataBase();
    query.exec("SELECT * from Diaporamas");
    for(unsigned int i = 0; query.next(); i++)
    {
        QString idDiaporama = query.value(0).toString();
        QString titreDiaporama = query.value(1).toString();
        QString vitesseDefilement = query.value(2).toString();

        qDebug() << idDiaporama << titreDiaporama << vitesseDefilement << Qt::endl;

        // On fixe le nombre de colonnes
        ui->tableWidget->setColumnCount(header.size());
        // On applique les noms des colonnes
        ui->tableWidget->setHorizontalHeaderLabels(header);
        QHeaderView * headerView = ui->tableWidget->horizontalHeader();
        headerView->setSectionResizeMode(QHeaderView::Stretch);

        QTableWidgetItem *idDiaporama1 = new QTableWidgetItem(QString(idDiaporama));
        QTableWidgetItem *titreDiaporama2 = new QTableWidgetItem(QString(titreDiaporama));
        QTableWidgetItem *vitesseDefilement3 = new QTableWidgetItem(QString(vitesseDefilement));

        ui->tableWidget->insertRow(i);

        ui->tableWidget->setItem(i, 0, idDiaporama1);
        ui->tableWidget->setItem(i, 1, titreDiaporama2);
        ui->tableWidget->setItem(i, 2, vitesseDefilement3);
    }
}

choixDiaporama::~choixDiaporama()
{
    delete ui;
}

int choixDiaporama::getSelectedDiaporamaId() const
{
    return selectedDiaporamaId;
}

void choixDiaporama::lineSelect(const QModelIndex & index)
{
    selectedDiaporamaId = ui->tableWidget->item(index.row(), 0)->text().toInt();
    qDebug() << selectedDiaporamaId;
    QDialog::accept();
}

int choixDiaporama::exec()
{
    int result = QDialog::exec();
    if (result == QDialog::Accepted)
    {
        return selectedDiaporamaId;
    }
    return 0;
}
