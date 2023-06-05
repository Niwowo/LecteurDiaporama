#include "lecteur.h"
#include <QDebug>

Lecteur::Lecteur()
{
    _numDiaporamaCourant = 0;   // Le lecteur est initialement vide
}

void Lecteur::avancer()
{
    if(_posImageCourante == nbImages()-1)
    {
        _posImageCourante = 0;  // Si nous sommes à la dernière image, passer à la première
    }
    else
    {
        _posImageCourante++;    // Sinon, passer à l'image suivante
    }
    qDebug() << _posImageCourante;
}

void Lecteur::reculer()
{
    if(_posImageCourante == 0)
    {
        _posImageCourante = nbImages()-1;  // Si nous sommes à la première image, passer à la dernière
    }
    else
    {
        _posImageCourante--;   // Sinon, passer à l'image précédente
    }
    qDebug() << _posImageCourante;
}

void Lecteur::changerDiaporama(unsigned int pNumDiaporama)
{
    // Si un diaporama courant existe, le vider avant de charger le nouveau diaporama
    if (numDiaporamaCourant() > 0)
    {
        viderDiaporama();
    }
    _numDiaporamaCourant = pNumDiaporama;  // Définir le nouveau numéro de diaporama courant
    if (numDiaporamaCourant() > 0)
    {
        chargerDiaporama(); // Charger le diaporama courant
    }
}

void Lecteur::chargerDiaporama()
{
    /* Charger les images associées au diaporama courant.
       Dans une version ultérieure, ces données proviendront d'une base de données
       et correspondront au diaporama choisi. */

    // Créer et ajouter des instances d'Image au diaporama
    Image* imageACharger;
    imageACharger = new Image(3, "personne", "Alice", ":/cartesDisney/images/cartesDisney/Disney_2.gif");
    _diaporama.push_back(imageACharger);
    imageACharger = new Image(2, "animal", "Chiengue", ":/cartesDisney/images/cartesDisney/Disney_1.gif");
    _diaporama.push_back(imageACharger);
    imageACharger = new Image(4, "animal", "Bambi", ":/cartesDisney/images/cartesDisney/Disney_3.gif");
    _diaporama.push_back(imageACharger);
    imageACharger = new Image(1, "autre", "Chateau de Disney", ":/cartesDisney/images/cartesDisney/Disney_0.gif");
    _diaporama.push_back(imageACharger);

    // Trier le contenu du diaporama par ordre croissant selon le rang de l'image dans le diaporama
    // À FAIRE

    // Tri du diaporama en utilisant l'algorithme de tri à bulles
    int n = _diaporama.size();
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (_diaporama[j]->getRang() > _diaporama[j+1]->getRang()) {
                Image* temp = _diaporama[j];
                _diaporama[j] = _diaporama[j+1];
                _diaporama[j+1] = temp;
            }
        }
    }

    _posImageCourante = 0;

    cout << "Diaporama num. " << numDiaporamaCourant() << " sélectionné." << endl;
            cout << nbImages() << " images chargées dans le diaporama." << endl;
}

void Lecteur::viderDiaporama()
{
    if (nbImages() > 0)
    {
        unsigned int taille = nbImages();
        for (unsigned int i = 0; i < taille ; i++)
        {
            delete _diaporama[i]; // Supprimer chaque instance d'Image
        }
        _diaporama.clear();  // Vider le vector de diaporama
        _posImageCourante = 0;
    }
    cout << nbImages() << " images restantes dans le diaporama." << endl;
}

void Lecteur::afficher()
{
    /* Afficher les informations sur le lecteur :
     * 1) "Lecteur vide" si le numéro de diaporama est 0
     *    OU
     *    Numéro de diaporama affiché
     * 2) Si un diaporama courant est chargé (numéro de diaporama > 0),
     *    afficher l'image courante
     *    OU
     *    "Diaporama vide" s'il n'y a aucune image dans le diaporama.
     */

    if (numDiaporamaCourant() == 0)
    {
        cout << "Lecteur vide" << endl;
    }
    else
    {
        if (nbImages() > 0)
        {
            cout << "Image courante : " << endl;
            _diaporama[_posImageCourante]->afficher();
        }
        else
        {
            cout << "Diaporama vide" << endl;
        }
    }
}

unsigned int Lecteur::nbImages()
{
    return _diaporama.size();
}

Image *Lecteur::imageCourante()
{
    return _diaporama[_posImageCourante];
}

unsigned int Lecteur::numDiaporamaCourant()
{
    return _numDiaporamaCourant;
}







