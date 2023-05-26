 #include "diaporama.h"

Diaporama::Diaporama(unsigned int pidDiaporama, string ptitreDiaporama, unsigned int pvitesseDefilement)
{
    _idDiaporama = pidDiaporama;
    _titreDiaporama = ptitreDiaporama;
    _vitesseDefilement = pvitesseDefilement;
}

unsigned int Diaporama::getIdDiaporama()
{
    return _idDiaporama;
}

string Diaporama::getTitreDiaporama()
{
    return _titreDiaporama;
}

unsigned int Diaporama::getVitesseDefilement()
{
    return _vitesseDefilement;
}

void Diaporama::afficher()
{
    cout << "diaporama( idDiaporama:" << getIdDiaporama() << ", titreDiaporama:" << getTitreDiaporama() << ", vitesseDefilement:"
         << getVitesseDefilement() << endl;
}
