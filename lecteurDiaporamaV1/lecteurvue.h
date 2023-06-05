#ifndef LECTEURVUE_H
#define LECTEURVUE_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class LecteurVue; }
QT_END_NAMESPACE

class LecteurVue : public QMainWindow
{
    Q_OBJECT

public:
    LecteurVue(QWidget *parent = nullptr);
    ~LecteurVue();

private:
    Ui::LecteurVue *ui;  // Interface utilisateur associée à la fenêtre

private slots:
    void chargerDiaporama();  // Slot appelé lors du chargement d'un diaporama
    void enleverDiaporama();  // Slot appelé lors de la suppression d'un diaporama
    void vitesseX0_5();  // Slot appelé lors de la sélection de la vitesse x0.5
    void vitesseX1();  // Slot appelé lors de la sélection de la vitesse x1
    void vitesseX2();  // Slot appelé lors de la sélection de la vitesse x2
    void aProposDe();  // Slot appelé lors de la sélection de "À propos de"
    void passerAuSuivant();  // Slot appelé lors du passage à l'image suivante
    void passerAuPrecedent();  // Slot appelé lors du passage à l'image précédente
    void lecture();  // Slot appelé lors de la sélection de "Lecture"
    void pause();  // Slot appelé lors de la sélection de "Pause"
    void choisirCategorie();  // Slot appelé lors du choix d'une catégorie
};
#endif // LECTEURVUE_H
