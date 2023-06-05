#include "lecteur.h"

Lecteur::Lecteur()
{
    _numDiaporamaCourant = 0;   // Initialise le lecteur comme étant vide
}

void Lecteur::avancer()
{
    _posImageCourante++;  // Avance à l'image suivante dans le diaporama
}

void Lecteur::reculer()
{
    _posImageCourante--;  // Recule à l'image précédente dans le diaporama
}

void Lecteur::changerDiaporama(unsigned int pNumDiaporama)
{
    // Si un diaporama courant existe, le vider avant de charger le nouveau diaporama
    if (numDiaporamaCourant() > 0)
    {
        viderDiaporama();
    }
    _numDiaporamaCourant = pNumDiaporama;  // Met à jour le numéro du diaporama courant
    if (numDiaporamaCourant() > 0)
    {
        chargerDiaporama(); // Charge le diaporama courant
    }

}

void Lecteur::chargerDiaporama()
{
    /* Chargement des images associées au diaporama courant
       Dans une version ultérieure, ces données proviendront d'une base de données,
       et correspondront au diaporama choisi */
    Image* imageACharger;
    imageACharger = new Image(3, "personne", "Blanche Neige", "C:\\cartesDisney\\carteDisney2.gif");
    _diaporama.push_back(imageACharger);  // Ajoute l'image à la fin du diaporama
    imageACharger = new Image(2, "personne", "Cendrillon", "C:\\cartesDisney\\carteDisney4.gif");
    _diaporama.push_back(imageACharger);
    imageACharger = new Image(4, "animal", "Mickey", "C:\\cartesDisney\\carteDisney1.gif");
    _diaporama.push_back(imageACharger);
    imageACharger = new Image(1, "personne", "Grincheux", "C:\\cartesDisney\\carteDisney1.gif");
    _diaporama.push_back(imageACharger);


    // Trier le contenu du diaporama par ordre croissant selon le rang de l'image dans le diaporama
    // À FAIRE

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

    _posImageCourante = 0;  // Réinitialise l'indice de l'image courante à 0

    cout << "Diaporama num. " << numDiaporamaCourant() << " sélectionné." << endl;
            cout << nbImages() << " images chargées dans le diaporama" << endl;

}

void Lecteur::viderDiaporama()
{
    if (nbImages () > 0)
    {
        unsigned int taille = nbImages();
        for (unsigned int i = 0; i < taille ; i++)
        {
            _diaporama.pop_back(); /* Supprime le dernier élément du vecteur,
                                      réduisant ainsi la taille du conteneur de un.
                                      ET supprime l'élément supprimé */
        }
        _posImageCourante = 0;  // Réinitialise l'indice de l'image courante à 0
    }
    cout << nbImages() << " images restantes dans le diaporama." << endl;

}

void Lecteur::afficher()
{
    /* Affiche les informations sur le lecteur :
     * 1) Vide (si le numéro de diaporama est 0) OU BIEN le numéro du diaporama affiché
     * 2) Si un diaporama courant est chargé (numéro de diaporama > 0), affiche l'image courante
     *    OU BIEN 'diaporama vide' s'il n'y a aucune image dans ce diaporama */
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
    return _diaporama.size();  // Retourne le nombre d'images dans le diaporama
}

Image *Lecteur::imageCourante()
{
    return nullptr;  // Retourne un pointeur nul pour l'image courante (à implémenter)
}

unsigned int Lecteur::numDiaporamaCourant()
{
    return _numDiaporamaCourant;  // Retourne le numéro du diaporama courant
}
}
