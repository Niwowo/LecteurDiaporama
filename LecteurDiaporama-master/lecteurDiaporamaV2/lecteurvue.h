#ifndef LECTEURVUE_H
#define LECTEURVUE_H

#include <QMainWindow>
#include "image.h"
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
    unsigned _numDiaporamaCourant;   // numéro du diaporama courant, par défaut 0
    Diaporama _diaporama;            // pointeurs vers les images du diaporama
    unsigned int _posImageCourante;  /* position, dans le diaporama,
                                        de l'image courante.
                                        Indéfini quand diaporama vide.
                                        Démarre à 0 quand diaporama non vide */
private:
    unsigned int numDiaporamaCourant();
    unsigned int nbImages();
    void chargerDiaporama();

private slots:
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
    void changerDiaporama();
};
#endif // LECTEURVUE_H
