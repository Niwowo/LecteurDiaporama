#ifndef DIAPORAMA_H
#define DIAPORAMA_H
#include <iostream>
using namespace std;

class Diaporama
{
public:
    Diaporama(unsigned int pidDiaporama = 0, string ptitreDiaporama = "", unsigned int pvitesseDefilement = 0);
    unsigned int getIdDiaporama();
    string getTitreDiaporama();
    unsigned int getVitesseDefilement();
    void afficher();

private:
    unsigned int _idDiaporama;
    string _titreDiaporama;
    unsigned int _vitesseDefilement;
};

#endif // DIAPORAMA_H
