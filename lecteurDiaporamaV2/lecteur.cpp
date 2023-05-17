#include "lecteur.h"
#include <QDebug>

Lecteur::Lecteur()
{
    _numDiaporamaCourant = 0;   // =  le lecteur est vide
}

void Lecteur::avancer()
{
    if(_posImageCourante == nbImages()-1)
    {
        _posImageCourante = 0;
    }
    else
    {
        _posImageCourante++;
    }
    qDebug() << _posImageCourante;
}

void Lecteur::reculer()
{
    if(_posImageCourante == 0)
    {
       _posImageCourante = nbImages()-1;
    }
    else
    {
        _posImageCourante--;
    }
    qDebug() << _posImageCourante;
}

void Lecteur::changerDiaporama(unsigned int pNumDiaporama)
{
    // s'il y a un diaporama courant, le vider, puis charger le nouveau Diaporama
    if (numDiaporamaCourant() > 0)
    {
        viderDiaporama();
    }
    _numDiaporamaCourant = pNumDiaporama;
    if (numDiaporamaCourant() > 0)
    {
        chargerDiaporama(); // charge le diaporama courant
    }
}

void Lecteur::chargerDiaporama()
{
    /* Chargement des images associées au diaporama courant
       Dans une version ultérieure, ces données proviendront d'une base de données,
       et correspondront au diaporama choisi */
    Image* imageACharger;
    imageACharger = new Image(3, "personne", "Alice", ":/cartesDisney/images/cartesDisney/Disney_2.gif");
    _diaporama.push_back(imageACharger);
    imageACharger = new Image(2, "animal", "D", ":/cartesDisney/images/cartesDisney/Disney_1.gif");
    _diaporama.push_back(imageACharger);
    imageACharger = new Image(4, "animal", "Bambi", ":/cartesDisney/images/cartesDisney/Disney_3.gif");
    _diaporama.push_back(imageACharger);
    imageACharger = new Image(1, "autre", "Chateau de Disney", ":/cartesDisney/images/cartesDisney/Disney_0.gif");
    _diaporama.push_back(imageACharger);


     // trier le contenu du diaporama par ordre croissant selon le rang de l'image dans le diaporama
     // A FAIRE

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

     cout << "Diaporama num. " << numDiaporamaCourant() << " selectionne. " << endl;
     cout << nbImages() << " images chargees dans le diaporama" << endl;
}

void Lecteur::viderDiaporama()
{
    if (nbImages () > 0)
    {
        unsigned int taille = nbImages();
        for (unsigned int i = 0; i < taille ; i++)
        {
            _diaporama.pop_back(); /* Removes the last element in the vector,
                                      effectively reducing the container size by one.
                                      AND deletes the removed element */
        }
     _posImageCourante = 0;
    }
    cout << nbImages() << " images restantes dans le diaporama." << endl;

}

void Lecteur::afficher()
{
    /* affiche les information sur le lecteur :
     * 1) vide (si num. de diaporama = 0) OU BIEN  numéro de diaporama affiché
     * 2) Si un diaporama courant est chargé (num. de diaporama > 0), affiche l'image courante OU BIEN 'diaporama vide'
     *     si ce diaporama n'a aucun image */
    if (numDiaporamaCourant() == 0){
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
