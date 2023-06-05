#include "lecteurvue.h"
#include "ui_lecteurvue.h"
#include <Qt>
#include <QLayout>
#include <QDebug>
#include <QCoreApplication>
#include <QMessageBox>

LecteurVue::LecteurVue(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::LecteurVue)
{
    ui->setupUi(this);
    // Désactive les boutons et les éléments de l'interface utilisateur initialement
    ui->pDroite->setEnabled(false);
    ui->pGauche->setEnabled(false);
    ui->pLecture->setEnabled(false);
    ui->pPause->setEnabled(false);
    ui->pCategorie->setEnabled(false);

    // Connecte les signaux aux slots correspondants
    connect(ui->actionQuitter,SIGNAL(triggered()),QCoreApplication::instance(), SLOT(quit()), Qt::QueuedConnection);
    connect(ui->actionCharger_diaporama,SIGNAL(triggered()), this, SLOT(chargerDiaporama()));
    connect(ui->actionEnlever_diaporama,SIGNAL(triggered()), this, SLOT(viderDiaporama()));
    connect(ui->actionx0_5,SIGNAL(triggered()),this,SLOT(vitesseX0_5()));
    connect(ui->actionx1, SIGNAL(triggered()),this,SLOT(vitesseX1()));
    connect(ui->actionx2, SIGNAL(triggered()),this,SLOT(vitesseX2()));
    connect(ui->actionA_propos_de, SIGNAL(triggered()),this,SLOT(aProposDe()));
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
    // Change le diaporama dans l'objet _lecteur
    _lecteur.changerDiaporama(1);
    // Récupère l'image courante du diaporama
    Image *image = _lecteur.imageCourante();
    // Obtient les informations de l'image
    QString imageAffichee = QString::fromStdString(image->getChemin());
    QString imageCategorie = QString::fromStdString(image->getCategorie());
    QString imageTitre = QString::fromStdString(image->getTitre());
    int imageRang = image->getRang();

    // Met à jour l'interface utilisateur avec les informations de l'image
    ui->lTitreImage->setText(imageTitre);
    ui->lCategorie->setText(imageCategorie);
    ui->lRang->setNum(imageRang);
    ui->labelImage->setPixmap(QPixmap(imageAffichee));
    ui->statusbar->showMessage(imageAffichee);

    // Active les boutons et les éléments de l'interface utilisateur appropriés
    ui->pDroite->setEnabled(true);
    ui->pGauche->setEnabled(true);
    ui->pLecture->setEnabled(true);
    ui->pPause->setEnabled(true);
    ui->pCategorie->setEnabled(true);
}

void LecteurVue::viderDiaporama()
{
    // Réinitialise l'interface utilisateur pour afficher les valeurs par défaut
    ui->lTitreImage->setText("Titre de l'image");
    ui->lCategorie->setText("");
    ui->labelImage->setPixmap(QPixmap(""));
    ui->lRang->setNum(0);
    ui->statusbar->showMessage("");
    qDebug() << "J'enlève le diaporama" << Qt::endl;

    // Change le diaporama dans l'objet _lecteur
    _lecteur.changerDiaporama(0);

    // Désactive les boutons et les éléments de l'interface utilisateur appropriés
    ui->pDroite->setEnabled(false);
    ui->pGauche->setEnabled(false);
    ui->pLecture->setEnabled(false);
    ui->pPause->setEnabled(false);
    ui->pCategorie->setEnabled(false);
}

void LecteurVue::vitesseX0_5()
{
    qDebug() << "Je change la vitesse a x0.5" << Qt::endl;
    // Implémente le code pour changer la vitesse du diaporama à 0.5x
}

void LecteurVue::vitesseX1()
{
    qDebug() << "Je change la vitesse a x1" << Qt::endl;
    // Implémente le code pour changer la vitesse du diaporama à 1x
}

void LecteurVue::vitesseX2()
{
    qDebug() << "Je change la vitesse a x2" << Qt::endl;
    // Implémente le code pour changer la vitesse du diaporama à 2x
}

void LecteurVue::aProposDe()
{
    qDebug() << "J'affiche le A Propos de" << Qt::endl;
    // Crée une boîte de message pour afficher les informations sur l'application
    QMessageBox *msgBox = new QMessageBox();
    msgBox->setStandardButtons(QMessageBox::Ok);
    msgBox->setText("Version de l'application : v2 \nDate de création : 27/04/2023 \nAuteurs : BURASOVITCH Ewan, ELDUAYEN Néo, ZAZA Souleymen");
    msgBox->exec();
}

void LecteurVue::passerAuSuivant()
{
    qDebug() <<  "Je passe à la diapositive suivante" << Qt::endl;
    // Avance vers la diapositive suivante dans l'objet _lecteur
    _lecteur.avancer();
    // Récupère l'image courante
    Image *image = _lecteur.imageCourante();
    // Obtient les informations de l'image
    QString imageAffichee = QString::fromStdString(image->getChemin());
    QString imageCategorie = QString::fromStdString(image->getCategorie());
    QString imageTitre = QString::fromStdString(image->getTitre());
    int imageRang = image->getRang();

    // Met à jour l'interface utilisateur avec les informations de la nouvelle image
    ui->lTitreImage->setText(imageTitre);
    ui->lCategorie->setText(imageCategorie);
    ui->lRang->setNum(imageRang);
    ui->labelImage->setPixmap(QPixmap(imageAffichee));
    ui->statusbar->showMessage(imageAffichee);
}

void LecteurVue::passerAuPrecedent()
{
    qDebug() <<  "Je passe à la diapositive précédente" << Qt::endl;
    // Recule vers la diapositive précédente dans l'objet _lecteur
    _lecteur.reculer();
    // Récupère l'image courante
    Image *image = _lecteur.imageCourante();
    // Obtient les informations de l'image
    QString imageAffichee = QString::fromStdString(image->getChemin());
    QString imageCategorie = QString::fromStdString(image->getCategorie());
    QString imageTitre = QString::fromStdString(image->getTitre());
    int imageRang = image->getRang();

    // Met à jour l'interface utilisateur avec les informations de la nouvelle image
    ui->lTitreImage->setText(imageTitre);
    ui->lCategorie->setText(imageCategorie);
    ui->lRang->setNum(imageRang);
    ui->labelImage->setPixmap(QPixmap(imageAffichee));
    ui->statusbar->showMessage(imageAffichee);
}

void LecteurVue::lecture()
{
    qDebug() <<  "je lance la lecture" << Qt::endl;
    // Implémente le code pour lancer la lecture du diaporama
}

void LecteurVue::pause()
{
    qDebug() <<  "je met en pause" << Qt::endl;
    // Implémente le code pour mettre en pause le diaporama
}

void LecteurVue::choisirCategorie()
{
    qDebug() <<  "j'affiche les catégories" << Qt::endl;
    // Implémente le code pour afficher les catégories disponibles et permettre à l'utilisateur d'en choisir une
}
