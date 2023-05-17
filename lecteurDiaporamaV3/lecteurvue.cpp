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

    timer->setInterval(5000);

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
    Image *image = _lecteur.imageCourante();
    QString imageAffichee = QString::fromStdString(image->getChemin());
    QString imageCategorie = QString::fromStdString(image->getCategorie());
    QString imageTitre = QString::fromStdString(image->getTitre());
    int imageRang = image->getRang();

    ui->lTitreImage->setText(imageTitre);
    ui->lCategorie->setText(imageCategorie);
    ui->lRang->setNum(imageRang);
    ui->labelImage->setPixmap(QPixmap(imageAffichee));
    ui->statusbar->showMessage(imageAffichee);
    ui->pDroite->setEnabled(true);
    ui->pGauche->setEnabled(true);
    ui->pLecture->setEnabled(true);
    ui->pPause->setEnabled(true);
    ui->pCategorie->setEnabled(true);
}

void LecteurVue::viderDiaporama()
{
    ui->lTitreImage->setText("Titre de l'image");
    ui->lCategorie->setText("");
    ui->labelImage->setPixmap(QPixmap(""));
    ui->lRang->setNum(0);
    ui->statusbar->showMessage("");
    qDebug() << "J'enlève le diaporama" << Qt::endl;
    _lecteur.changerDiaporama(0);
    ui->pDroite->setEnabled(false);
    ui->pGauche->setEnabled(false);
    ui->pLecture->setEnabled(false);
    ui->pPause->setEnabled(false);
    ui->pCategorie->setEnabled(false);
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
    msgBox->setText("Version de l'application : v3 \nDate de création : 27/04/2023 \nAuteurs : BURASOVITCH Ewan, ELDUAYEN Néo, ZAZA Souleymen");
    msgBox->exec();
}

void LecteurVue::passerAuSuivant()
{
    if(timer->isActive())
    {
        timer->stop();
        timer->~QTimer();
    }
    qDebug() <<  "Je passe à la diapositive suivante" << Qt::endl;
    _lecteur.avancer();
    Image *image = _lecteur.imageCourante();
    QString imageAffichee = QString::fromStdString(image->getChemin());
    QString imageCategorie = QString::fromStdString(image->getCategorie());
    QString imageTitre = QString::fromStdString(image->getTitre());
    int imageRang = image->getRang();

    ui->lTitreImage->setText(imageTitre);
    ui->lCategorie->setText(imageCategorie);
    ui->lRang->setNum(imageRang);
    ui->labelImage->setPixmap(QPixmap(imageAffichee));
    ui->statusbar->showMessage(imageAffichee);
}

void LecteurVue::passerAuPrecedent()
{
    if(timer->isActive())
    {
        timer->stop();
        timer->~QTimer();
    }
    qDebug() <<  "Je passe à la diapositive précédente" << Qt::endl;
    _lecteur.reculer();
    Image *image = _lecteur.imageCourante();
    QString imageAffichee = QString::fromStdString(image->getChemin());
    QString imageCategorie = QString::fromStdString(image->getCategorie());
    QString imageTitre = QString::fromStdString(image->getTitre());
    int imageRang = image->getRang();

    ui->lTitreImage->setText(imageTitre);
    ui->lCategorie->setText(imageCategorie);
    ui->lRang->setNum(imageRang);
    ui->labelImage->setPixmap(QPixmap(imageAffichee));
    ui->statusbar->showMessage(imageAffichee);
}

void LecteurVue::modeAuto()
{
    passerAuSuivant();
}

void LecteurVue::lecture()
{
    if(timer->isActive())
    {
        qDebug() << "Le timer est  déjà lancé";
    }
    else
    {
        QTimer *timer = new QTimer;
        qDebug() <<  "je lance la lecture" << Qt::endl;
        timer->connect(timer, SIGNAL(timeout()), this, SLOT(modeAuto()));
        timer->start();
    }
}

void LecteurVue::pause()
{
    timer->~QTimer();
    qDebug() <<  "je met en pause" << Qt::endl;
}

void LecteurVue::choisirCategorie()
{
    qDebug() <<  "j'affiche les catégories" << Qt::endl;
}

