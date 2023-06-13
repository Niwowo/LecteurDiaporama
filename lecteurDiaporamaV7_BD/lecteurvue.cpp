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

    // Désactiver les boutons et actions qui ne doivent pas être disponibles au départ
    ui->pDroite->setEnabled(false);
    ui->pGauche->setEnabled(false);
    ui->pLecture->setEnabled(false);
    ui->pPause->setEnabled(false);
    ui->pCategorie->setEnabled(false);

    // Connecter les signaux aux slots correspondants
    connect(ui->actionQuitter, SIGNAL(triggered()), QCoreApplication::instance(), SLOT(quit()), Qt::QueuedConnection);
    connect(ui->actionCharger_diaporama, SIGNAL(triggered()), this, SLOT(chargerDiaporama()));
    connect(ui->actionEnlever_diaporama, SIGNAL(triggered()), this, SLOT(viderDiaporama()));
    connect(ui->actionModifier_diaporama, SIGNAL(triggered()), this, SLOT(modifierDiaporama()));
    connect(ui->actionx0_5, SIGNAL(triggered()), this, SLOT(vitesseX0_5()));
    connect(ui->actionx1, SIGNAL(triggered()), this, SLOT(vitesseX1()));
    connect(ui->actionx2, SIGNAL(triggered()), this, SLOT(vitesseX2()));
    connect(ui->actionA_propos_de, SIGNAL(triggered()), this, SLOT(aProposDe()));
    connect(ui->pLecture, SIGNAL(clicked()), this, SLOT(lecture()));
    connect(ui->pPause, SIGNAL(clicked()), this, SLOT(pause()));
    connect(ui->pDroite, SIGNAL(clicked()), this, SLOT(onpDroiteClicked()));
    connect(ui->pDroite, SIGNAL(clicked()), this, SLOT(passerAuSuivant()));
    connect(ui->pGauche, SIGNAL(clicked()), this, SLOT(onpGaucheClicked()));
    connect(ui->pGauche, SIGNAL(clicked()), this, SLOT(passerAuPrecedent()));
    connect(ui->pCategorie, SIGNAL(clicked()), this, SLOT(choisirCategorie()));

    // Connecter le signal timeout du timer au slot modeAuto
    timer->connect(timer, SIGNAL(timeout()), this, SLOT(modeAuto()));
}

LecteurVue::~LecteurVue()
{
    delete ui;
}

void LecteurVue::chargerDiaporama()
{
    timer->stop();

    qDebug() << "Je charge le diaporama" << Qt::endl;
    _lecteur.changerDiaporama(1);
    if(_lecteur.nbImages() > 0)
    {
        Image *image = _lecteur.imageCourante();
        QString imageAffichee = QString::fromStdString(image->getChemin());
        QString imageCategorie = QString::fromStdString(image->getCategorie());
        QString imageTitre = QString::fromStdString(image->getTitre());
        int imageRang = image->getRang();
        QString titreDiaporama = QString::fromStdString(_lecteur.diaporamaCourant->getTitreDiaporama());

        // Mettre à jour l'interface utilisateur avec les informations du diaporama chargé
        ui->lTitre->setText(titreDiaporama);
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
}

void LecteurVue::viderDiaporama()
{
    timer->stop();

    // Réinitialiser les éléments de l'interface utilisateur
    ui->lTitreImage->setText("Titre de l'image");
    ui->lTitre->setText("Titre du Diaporama");
    ui->lCategorie->setText("Catégorie");
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
    // Définir l'intervalle du timer pour une vitesse de lecture de 0.5x
    timer->setInterval(6000);
}

void LecteurVue::vitesseX1()
{
    // Définir l'intervalle du timer pour une vitesse de lecture de 1x
    timer->setInterval(3000);
}

void LecteurVue::vitesseX2()
{
    // Définir l'intervalle du timer pour une vitesse de lecture de 2x
    timer->setInterval(1500);
}

void LecteurVue::aProposDe()
{
    qDebug() << "J'affiche le A Propos de" << Qt::endl;
    QMessageBox *msgBox = new QMessageBox();
    msgBox->setStandardButtons(QMessageBox::Ok);
    msgBox->setText("Version de l'application : v7 \nDate de création : 27/04/2023 \nAuteurs : BURASOVITCH Ewan, ELDUAYEN Néo, ZAZA Souleymen");
    msgBox->exec();
}

void LecteurVue::onpDroiteClicked()
{
    pDroiteClicked = !pDroiteClicked;
}

void LecteurVue::onpGaucheClicked()
{
    pGaucheClicked = !pGaucheClicked;
}

void LecteurVue::passerAuSuivant()
{
    qDebug() <<  "Je passe à la diapositive suivante" << Qt::endl;
    if(selectedCategory != "Tout")
    {
        while(true)
        {
            _lecteur.avancer();
            Image *image = _lecteur.imageCourante();
            QString imageCategorie = QString::fromStdString(image->getCategorie());
            if(imageCategorie == selectedCategory)
            {
                break;
            }
        }
    }
    else
    {
        _lecteur.avancer();
    }
    if(timer->isActive() && pDroiteClicked)
    {
        timer->stop();
        pDroiteClicked = false;
    }
    Image *image = _lecteur.imageCourante();
    QString imageAffichee = QString::fromStdString(image->getChemin());
    QString imageCategorie = QString::fromStdString(image->getCategorie());
    QString imageTitre = QString::fromStdString(image->getTitre());
    int imageRang = image->getRang();

    // Mettre à jour l'interface utilisateur avec les informations de l'image suivante
    ui->lTitreImage->setText(imageTitre);
    ui->lCategorie->setText(imageCategorie);
    ui->lRang->setNum(imageRang);
    ui->labelImage->setPixmap(QPixmap(imageAffichee));
    ui->statusbar->showMessage(imageAffichee);
    ui->lMode->setText("Manuel");
}

void LecteurVue::passerAuPrecedent()
{
    qDebug() <<  "Je passe à la diapositive précédente" << Qt::endl;
    qDebug() <<  "Je passe à la diapositive suivante" << Qt::endl;
    if(selectedCategory != "Tout")
    {
        while(true)
        {
            _lecteur.avancer();
            Image *image = _lecteur.imageCourante();
            QString imageCategorie = QString::fromStdString(image->getCategorie());
            if(imageCategorie == selectedCategory)
            {
                break;
            }
        }
    }
    else
    {
        _lecteur.reculer();
    }
    if(timer->isActive() && pGaucheClicked)
    {
        timer->stop();
        pGaucheClicked = false;
    }
    Image *image = _lecteur.imageCourante();
    QString imageAffichee = QString::fromStdString(image->getChemin());
    QString imageCategorie = QString::fromStdString(image->getCategorie());
    QString imageTitre = QString::fromStdString(image->getTitre());
    int imageRang = image->getRang();

    // Mettre à jour l'interface utilisateur avec les informations de l'image précédente
    ui->lTitreImage->setText(imageTitre);
    ui->lCategorie->setText(imageCategorie);
    ui->lRang->setNum(imageRang);
    ui->labelImage->setPixmap(QPixmap(imageAffichee));
    ui->statusbar->showMessage(imageAffichee);
    ui->lMode->setText("Manuel");
}

void LecteurVue::modeAuto()
{
    passerAuSuivant();
}

void LecteurVue::lecture()
{
    while(true)
    {
        if(_lecteur.numImageCourante() == 0)
        {
            break;
        }
        else
        {
            passerAuSuivant();
        }
    }
    if(timer->isActive())
    {
        qDebug() << "Le timer est déjà lancé";
    }
    else
    {
        // Définir la vitesse de lecture à 1x et démarrer le timer
        vitesseX1();
//        ui->pDroite->setEnabled(false);
//        ui->pGauche->setEnabled(false);
        qDebug() <<  "Je lance la lecture" << Qt::endl;
        timer->start();
        ui->lMode->setText("Automatique");
    }
}

void LecteurVue::pause()
{
    // Arrêter le timer et réactiver les boutons de navigation
    timer->stop();
//    ui->pDroite->setEnabled(true);
//    ui->pGauche->setEnabled(true);
    qDebug() <<  "Je mets en pause" << Qt::endl;
    ui->lMode->setText("Manuel");
}

void LecteurVue::choisirCategorie()
{
    qDebug() << "J'affiche les catégories" << Qt::endl;

    ChoixCategorie choixCategorieDialog(this);

    // Execute the dialog modally
    int result = choixCategorieDialog.exec();

    // Check the result
    if (result == QDialog::Accepted) {
            // Retrieve the selected category from the dialog
            selectedCategory = choixCategorieDialog.getSelectedCategory();
            qDebug() << selectedCategory << Qt::endl;
    }
    Image *image = _lecteur.imageCourante();
    QString imageCategorie = QString::fromStdString(image->getCategorie());
    unsigned int i = 0;
    while(true)
    {
        if(i>_lecteur.nbImages())
        {
            qDebug() << "Aucune image ne correspond a cette catégorie" << Qt::endl;
            selectedCategory = "Tout";
            break;
        }
        if(imageCategorie != selectedCategory && selectedCategory != "Tout")
        {
            _lecteur.avancer();
        }
        if(imageCategorie == selectedCategory)
        {
            break;
        }
        i++;
    }
}

void LecteurVue::modifierDiaporama()
{
    ModifierDiaporama modifierDiaporama(this);

    // Execute the dialog modally
    int result = modifierDiaporama.exec();
}
