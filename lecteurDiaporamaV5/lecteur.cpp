#include "lecteur.h"
#include <QDebug>

Lecteur::Lecteur()
{
    _numDiaporamaCourant = 0;   // Le lecteur est vide par défaut
}

void Lecteur::avancer()
{
    if(_posImageCourante == nbImages() - 1)
    {
        _posImageCourante = 0;  // Revenir à la première image si on atteint la dernière
    }
    else
    {
        _posImageCourante++;  // Passer à l'image suivante
    }
    qDebug() << _posImageCourante;  // Afficher la position de l'image courante (pour le débogage)
}

void Lecteur::reculer()
{
    if(_posImageCourante == 0)
    {
        _posImageCourante = nbImages() - 1;  // Revenir à la dernière image si on est à la première
    }
    else
    {
        _posImageCourante--;  // Passer à l'image précédente
    }
    qDebug() << _posImageCourante;  // Afficher la position de l'image courante (pour le débogage)
}

void Lecteur::changerDiaporama(unsigned int pNumDiaporama)
{
    // S'il y a un diaporama courant, le vider, puis charger le nouveau diaporama
    if (numDiaporamaCourant() > 0)
    {
        viderDiaporama();
    }
    _numDiaporamaCourant = pNumDiaporama;
    if (numDiaporamaCourant() > 0)
    {
        chargerDiaporama(); // Charger le diaporama courant
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

    // Trier le contenu du diaporama par ordre croissant selon le rang de l'image dans le diaporama
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
            delete _diaporama.back();  // Supprimer l'image de la mémoire
            _diaporama.pop_back();    // Supprimer la dernière image du diaporama
        }
        _posImageCourante = 0;
    }
    cout << nbImages() << " images restantes dans le diaporama." << endl;
    closeDataBase();
}

void Lecteur::afficher()
{
    /* Affiche les informations sur le lecteur :
     * 1) Vide (si num. de diaporama = 0) OU BIEN le numéro de diaporama affiché
     * 2) Si un diaporama courant est chargé (num. de diaporama > 0), affiche l'image courante
     *    OU BIEN 'diaporama vide' si ce diaporama ne contient aucune image */
    if (numDiaporamaCourant() == 0){
        cout << "Lecteur vide" << endl;
    }
    else
    {
        if (nbImages() > 0)
        {
            cout << "Image courante : " << endl;
            _diaporama[_posImageCourante]->afficher();  // Afficher l'image courante
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

Image* Lecteur::imageCourante()
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
