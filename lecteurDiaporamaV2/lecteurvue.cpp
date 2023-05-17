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
    ui->pDroite->setEnabled(false);
    ui->pGauche->setEnabled(false);
    ui->pLecture->setEnabled(false);
    ui->pPause->setEnabled(false);
    ui->pCategorie->setEnabled(false);
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
    _lecteur.changerDiaporama(1);
    ui->labelImage->setPixmap(QPixmap(":/cartesDisney/images/cartesDisney/Disney_0.gif"));
    ui->pDroite->setEnabled(true);
    ui->pGauche->setEnabled(true);
    ui->pLecture->setEnabled(true);
    ui->pPause->setEnabled(true);
    ui->pCategorie->setEnabled(true);
}

void LecteurVue::viderDiaporama()
{
    qDebug() << "J'enlève le diaporama" << Qt::endl;
    _lecteur.changerDiaporama(0);
    ui->pDroite->setEnabled(false);
    ui->pGauche->setEnabled(false);
    ui->pLecture->setEnabled(false);
    ui->pPause->setEnabled(false);
    ui->pCategorie->setEnabled(false);
    ui->labelImage->setPixmap(QPixmap("-----"));

}

void LecteurVue::vitesseX0_5()
{
    qDebug() << "Je change la vitesse a x0.5" << Qt::endl;
}

void LecteurVue::vitesseX1()
{
    qDebug() << "Je change la vitesse a x1" << Qt::endl;
}

void LecteurVue::vitesseX2()
{
    qDebug() << "Je change la vitesse a x2" << Qt::endl;
}

void LecteurVue::aProposDe()
{
    qDebug() << "J'affiche le A Propos de" << Qt::endl;
    QMessageBox *msgBox = new QMessageBox();
    msgBox->setStandardButtons(QMessageBox::Ok);
    msgBox->setText("Version de l'application : v2 \nDate de création : 27/04/2023 \nAuteurs : BURASOVITCH Ewan, ELDUAYEN Néo, ZAZA Souleymen");
    msgBox->exec();
}

void LecteurVue::passerAuSuivant()
{
    qDebug() <<  "Je passe à la diapositive suivante" << Qt::endl;
//    QString nomImage = ":/cartesDisney/images/cartesDisney/Disney_";
//    nomImage.append(QString::number(_posImageCourante));
//    nomImage.append(".gif");
//    qDebug() << nomImage;
//    ui->labelImage->setPixmap(QPixmap(nomImage));
    _lecteur.avancer();
}

void LecteurVue::passerAuPrecedent()
{
    qDebug() <<  "Je passe à la diapositive précédente" << Qt::endl;
//    QString nomImage = ":/cartesDisney/images/cartesDisney/Disney_";
//    nomImage.append(QString::number(_lecteur.imageCourante()));
//    nomImage.append(".gif");
//    qDebug() << nomImage;
//    ui->labelImage->setPixmap(QPixmap(nomImage));
    _lecteur.reculer();
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

