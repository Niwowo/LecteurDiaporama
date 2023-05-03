#include "lecteurvue.h"
#include "ui_lecteurvue.h"

LecteurVue::LecteurVue(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::LecteurVue)
{
    ui->setupUi(this);
    connect(ui->pLecture, SIGNAL(clicked()), this, SLOT(lecture()));
    connect(ui->pPause, SIGNAL(clicked()), this, SLOT(pause()));
    connect(ui->pDroite, SIGNAL(clicked()), this, SLOT(passerAuSuivant()));
    connect(ui->pGauche, SIGNAL(clicked()), this, SLOT(passerAuPrecedent()));
    connect(ui->pCategorie, SIGNAL(clicked()), this, SLOT(choisirCategorie()));
}

LecteurVue::~LecteurVue()
{
    delete ui;
}

void LecteurVue::passerAuSuivant()
{
    qDebug() <<  "Je passe à la diapositive suivante" << Qt::endl;
}

void LecteurVue::passerAuPrecedent()
{
    qDebug() <<  "Je passe à la diapositive précédente" << Qt::endl;
}

void LecteurVue::lecture()
{
    qDebug() <<  "je lance la lecture" << Qt::endl;
}

void LecteurVue::pause()
{
    qDebug() <<  "je met en pause" << Qt::endl;
}

void LecteurVue::choisirCategorie()
{
    qDebug() <<  "j'affiche les catégories" << Qt::endl;
}

