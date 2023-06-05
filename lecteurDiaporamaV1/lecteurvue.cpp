#include "lecteurvue.h"
#include "ui_lecteurvue.h"
#include <Qt>
#include <QLayout>
#include <QDebug>
#include <QCoreApplication>

LecteurVue::LecteurVue(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::LecteurVue)
{
    ui->setupUi(this);

    // Connexion des signaux aux slots
    connect(ui->actionQuitter, SIGNAL(triggered()), QCoreApplication::instance(), SLOT(quit()), Qt::QueuedConnection);
    connect(ui->actionCharger_diaporama, SIGNAL(triggered()), this, SLOT(chargerDiaporama()));
    connect(ui->actionEnlever_diaporama, SIGNAL(triggered()), this, SLOT(enleverDiaporama()));
    connect(ui->actionx0_5, SIGNAL(triggered()), this, SLOT(vitesseX0_5()));
    connect(ui->actionx1, SIGNAL(triggered()), this, SLOT(vitesseX1()));
    connect(ui->actionx2, SIGNAL(triggered()), this, SLOT(vitesseX2()));
    connect(ui->actionA_propos_de, SIGNAL(triggered()), this, SLOT(aProposDe()));
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

void LecteurVue::chargerDiaporama()
{
    qDebug() << "Je charge le diaporama" << Qt::endl;
}

void LecteurVue::enleverDiaporama()
{
    qDebug() << "J'enlève le diaporama" << Qt::endl;
}

void LecteurVue::vitesseX0_5()
{
    qDebug() << "Je change la vitesse à x0.5" << Qt::endl;
}

void LecteurVue::vitesseX1()
{
    qDebug() << "Je change la vitesse à x1" << Qt::endl;
}

void LecteurVue::vitesseX2()
{
    qDebug() << "Je change la vitesse à x2" << Qt::endl;
}

void LecteurVue::aProposDe()
{
    qDebug() << "J'affiche À Propos de" << Qt::endl;
}

void LecteurVue::passerAuSuivant()
{
    qDebug() << "Je passe à la diapositive suivante" << Qt::endl;
}

void LecteurVue::passerAuPrecedent()
{
    qDebug() << "Je passe à la diapositive précédente" << Qt::endl;
}

void LecteurVue::lecture()
{
    qDebug() << "Je lance la lecture" << Qt::endl;
}

void LecteurVue::pause()
{
    qDebug() << "Je mets en pause" << Qt::endl;
}

void LecteurVue::choisirCategorie()
{
    qDebug() << "J'affiche les catégories" << Qt::endl;
}


