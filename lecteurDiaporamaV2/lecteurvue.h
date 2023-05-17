#ifndef LECTEURVUE_H
#define LECTEURVUE_H

#include <QMainWindow>
#include "image.h"
#include "lecteur.h"
#include <QWidget>
#include <vector>

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

private:
    Ui::LecteurVue *ui;
    Lecteur _lecteur;
    unsigned _numDiaporamaCourant;   // numéro du diaporama courant, par défaut 0
    Diaporama _diaporama;            // pointeurs vers les images du diaporama

private slots:
    void chargerDiaporama();
    void viderDiaporama();
    void vitesseX0_5();
    void vitesseX1();
    void vitesseX2();
    void aProposDe();
    void passerAuSuivant();
    void passerAuPrecedent();
    void lecture();
    void pause();
    void choisirCategorie();
};
#endif // LECTEURVUE_H
