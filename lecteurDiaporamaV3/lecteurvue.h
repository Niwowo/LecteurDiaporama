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
    QTimer *timer = new QTimer(this);  // Timer pour le mode automatique

private:
    Ui::LecteurVue *ui;  // Instance de l'interface utilisateur
    Lecteur _lecteur;   // Instance du lecteur de diaporama


private slots:
    void modeAuto();  // Slot pour le mode automatique
    void chargerDiaporama();  // Slot pour charger le diaporama
    void viderDiaporama();  // Slot pour vider le diaporama
    void vitesseX0_5();  // Slot pour changer la vitesse à 0.5x
    void vitesseX1();    // Slot pour changer la vitesse à 1x
    void vitesseX2();    // Slot pour changer la vitesse à 2x
    void aProposDe();    // Slot pour afficher les informations sur l'application
    void passerAuSuivant();    // Slot pour passer à la diapositive suivante
    void passerAuPrecedent();  // Slot pour passer à la diapositive précédente
    void lecture();     // Slot pour lancer la lecture du diaporama
    void pause();       // Slot pour mettre en pause le diaporama
    void choisirCategorie();   // Slot pour choisir une catégorie
};
#endif // LECTEURVUE_H
