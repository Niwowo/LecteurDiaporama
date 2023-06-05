#ifndef DIAPORAMA_H
#define DIAPORAMA_H

#include <iostream>
#include "image.h"
#include <vector>
using namespace std;

class Diaporama
{
public:
    Diaporama(unsigned int pidDiaporama = 0, string ptitreDiaporama = "", unsigned int pvitesseDefilement = 0);
    unsigned int getIdDiaporama();              // Obtient l'ID du diaporama
    string getTitreDiaporama();                  // Obtient le titre du diaporama
    unsigned int getVitesseDefilement();     // Obtient la vitesse de défilement du diaporama
    void chargerDiapo(Image* image);                 // Charge une image dans le diaporama
    void trier();                                                   // Trie les images dans le diaporama
    void enleverImage();                                     // Enlève une image du diaporama
    unsigned int nbImages();                            // Obtient le nombre d'images dans le diaporama
    Image* imageCourante(unsigned int posImageCourante); // Obtient l'image courante dans le diaporama en fonction de la position
    void afficher();                                               // Affiche les informations sur le diaporama

    vector<Image*> _diaporama;

private:
    unsigned int _idDiaporama;                // ID du diaporama
    string _titreDiaporama;                       // Titre du diaporama
    unsigned int _vitesseDefilement;       // Vitesse de défilement du diaporama
};

#endif // DIAPORAMA_H
