#ifndef LECTEURVUE_H
#define LECTEURVUE_H

#include <QMainWindow>
#include "image.h"
#include "lecteur.h"
#include <QWidget>
#include <vector>
#include <QTimer>

typedef std::vector<Image*> Diaporama;

QT_BEGIN_NAMESPACE
namespace Ui { class LecteurVue; }
QT_END_NAMESPACE

class LecteurVue : public QMainWindow
{
    Q_OBJECT

public:
    LecteurVue(QWidget *parent = nullptr);
    ~LecteurVue();
    QTimer *timer = new QTimer(this);  // Timer utilisé pour le mode automatique du diaporama

private:
    Ui::LecteurVue *ui;  // Interface utilisateur
    Lecteur _lecteur;  // Instance du lecteur de diaporama

private slots:
    void modeAuto();  // Fonction appelée périodiquement lors du mode automatique
    void chargerDiaporama();  // Charge un diaporama
    void viderDiaporama();  // Vide le diaporama actuel
    void vitesseX0_5();  // Définit la vitesse du diaporama à 0.5x
    void vitesseX1();  // Définit la vitesse du diaporama à 1x
    void vitesseX2();  // Définit la vitesse du diaporama à 2x
    void aProposDe();  // Affiche les informations sur l'application
    void passerAuSuivant();  // Passe à la diapositive suivante
    void passerAuPrecedent();  // Passe à la diapositive précédente
    void lecture();  // Démarre la lecture automatique du diaporama
    void pause();  // Met en pause la lecture automatique du diaporama
    void choisirCategorie();  // Affiche les catégories du diaporama
};
#endif // LECTEURVUE_H
