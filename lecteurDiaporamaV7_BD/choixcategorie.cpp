#include "choixcategorie.h"
#include "ui_choixcategorie.h"

ChoixCategorie::ChoixCategorie(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ChoixCategorie)
{
    ui->setupUi(this);
    connect(ui->bOk,SIGNAL(clicked()),this,SLOT(accept()));
    connect(ui->bQuitter,SIGNAL(clicked()),this,SLOT(reject()));
}

ChoixCategorie::~ChoixCategorie()
{
    delete ui;
}

QString ChoixCategorie::getSelectedCategory() const
{
    QString selectedCategory = ui->comboBox->currentText();
    return selectedCategory;
}

void ChoixCategorie::chargerCategories(const std::vector<QString>& categories)
{
    ui->comboBox->clear(); // Effacer toutes les catégories précédentes

     // Ajouter les nouvelles catégories à la comboBox
     for (const QString& categorie : categories) {
        ui->comboBox->addItem(categorie);
     }
}
