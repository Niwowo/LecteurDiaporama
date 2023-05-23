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
    openDataBase();
    Image* imageACharger;
    QSqlQuery query;
    query.exec("SELECT idphoto, titrePhoto, F.nomFamille, uriPhoto FROM Diapos INNER JOIN Familles F ON Diapos.idFam = F.idFamille");
    for(int i = 0; query.next(); i++)
    {
        qDebug() << query.value(1).toString() << query.value(2).toString() << query.value(3).toString();
        unsigned int rang = query.value(0).toInt();
        QString nomCategorie = query.value(2).toString();
        string nomCategorieImage = nomCategorie.toStdString();
        QString nom = query.value(1).toString();
        string nomImage = nom.toStdString();
        QString cheminAcces = query.value(3).toString();
        string cheminAccesImage = ":/cartesDisney/images/" + cheminAcces.toStdString();
        imageACharger = new Image(rang, nomCategorieImage, nomImage, cheminAccesImage);
        _diaporama.push_back(imageACharger);
    }
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
    closeDataBase();
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

bool Lecteur::openDataBase()
{
    mydb = QSqlDatabase::addDatabase(CONNECT_TYPE);
    mydb.setHostName("lakartxela.iutbayonne.univ-pau.fr");
    mydb.setDatabaseName(DATABASE_NAME);
    mydb.setUserName("nelduayen_bd");
    mydb.setPassword("nelduayen_bd");
    return mydb.open();
}

void Lecteur::closeDataBase()
{
    mydb.close();
}
