#ifndef LECTEURVUE_H
#define LECTEURVUE_H

#include <QMainWindow>
#include "image.h"
#include "lecteur.h"
#include "choixcategorie.h"
#include "modifierdiaporama.h"
#include <QWidget>
#include <vector>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui { class LecteurVue; }
QT_END_NAMESPACE

class LecteurVue : public QMainWindow
{
    Q_OBJECT

public:
    LecteurVue(QWidget *parent = nullptr);
    ~LecteurVue();
    QTimer *timer = new QTimer(this);    // Timer pour le mode automatique

private:
    Ui::LecteurVue *ui;                     // Interface utilisateur de la fenêtre principale
    Lecteur _lecteur;                        // Objet Lecteur pour gérer le diaporama
    Diaporama _diaporama;                // Diaporama actuel
    QString selectedCategory = "Tout"; // La catégorie sélectionnée par l'utilisateur
    bool pDroiteClicked = false;
    bool pGaucheClicked = false;

private slots:
    void modeAuto();                            // Mode automatique : passe à l'image suivante
    void chargerDiaporama();              // Charge un diaporama
    void viderDiaporama();                    // Vide le diaporama actuel
    void vitesseX0_5();                          // Définit la vitesse de défilement à 0.5x
    void vitesseX1();                              // Définit la vitesse de défilement à 1x
    void vitesseX2();                              // Définit la vitesse de défilement à 2x
    void aProposDe();                              // Affiche les informations sur l'application
    void passerAuSuivant();                   // Passe à l'image suivante dans le diaporama
    void passerAuPrecedent();                // Passe à l'image précédente dans le diaporama
    void lecture();                                    // Démarre la lecture automatique
    void pause();                                       // Met en pause la lecture automatique
    void choisirCategorie();                    // Affiche les catégories d'images
    void onpDroiteClicked();
    void onpGaucheClicked();
    void modifierDiaporama();
};

#endif // LECTEURVUE_H

