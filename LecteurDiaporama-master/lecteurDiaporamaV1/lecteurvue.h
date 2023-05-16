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
    Ui::LecteurVue *ui;

private slots:
    void chargerDiaporama();
    void enleverDiaporama();
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
