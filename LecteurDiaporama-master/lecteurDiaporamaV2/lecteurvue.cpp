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
    connect(ui->actionQuitter,SIGNAL(triggered()),QCoreApplication::instance(), SLOT(quit()), Qt::QueuedConnection);
    connect(ui->actionCharger_diaporama,SIGNAL(triggered()), this, SLOT(changerDiaporama()));
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
    /* Chargement des images associées au diaporama courant
       Dans une version ultérieure, ces données proviendront d'une base de données,
       et correspondront au diaporama choisi */
    Image* imageACharger;
    imageACharger = new Image(3, "personne", "Blanche Neige", "C:\\cartesDisney\\carteDisney2.gif");
    _diaporama.push_back(imageACharger);
    imageACharger = new Image(2, "personne", "Cendrillon", "C:\\cartesDisney\\carteDisney4.gif");
    _diaporama.push_back(imageACharger);
    imageACharger = new Image(4, "animal", "Mickey", "C:\\cartesDisney\\carteDisney1.gif");
    _diaporama.push_back(imageACharger);
    imageACharger = new Image(1, "personne", "Grincheux", "C:\\cartesDisney\\carteDisney1.gif");
    _diaporama.push_back(imageACharger);


     // trier le contenu du diaporama par ordre croissant selon le rang de l'image dans le diaporama
     // A FAIRE

    int n = _diaporama.size();
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (_diaporama[j]->getRang() > _diaporama[j+1]->getRang()) {
                Image* temp = _diaporama[j];
                _diaporama[j] = _diaporama[j+1];
                _diaporama[j+1] = temp;
            }
        }
    }

     this->_posImageCourante = 0;

     cout << "Diaporama num. " << numDiaporamaCourant() << " selectionne. " << endl;
     cout << nbImages() << " images chargees dans le diaporama" << endl;
}

void LecteurVue::changerDiaporama()
{
    // s'il y a un diaporama courant, le vider, puis charger le nouveau Diaporama
    if (nbImages() > 0)
    {
        viderDiaporama();
        chargerDiaporama();
    }
    else if (nbImages() == 0)
    {
        chargerDiaporama(); // charge le diaporama courant
    }
}

void LecteurVue::viderDiaporama()
{
    qDebug() << "J'enlève le diaporama" << Qt::endl;
    if (nbImages () > 0)
    {
        unsigned int taille = nbImages();
        for (unsigned int i = 0; i < taille ; i++)
        {
            _diaporama.pop_back(); /* Removes the last element in the vector,
                                      effectively reducing the container size by one.
                                      AND deletes the removed element */
        }
     this->_posImageCourante = 0;
    }
    cout << nbImages() << " images restantes dans le diaporama." << endl;

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
    _posImageCourante++;
}

void LecteurVue::passerAuPrecedent()
{
    qDebug() <<  "Je passe à la diapositive précédente" << Qt::endl;
    _posImageCourante--;
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

unsigned int LecteurVue::numDiaporamaCourant()
{
    return _posImageCourante;
}

unsigned int LecteurVue::nbImages()
{
    return _diaporama.size();
}

