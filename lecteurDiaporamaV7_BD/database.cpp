#include "database.h"

Database::Database()
{

}

bool Database::openDataBase()
{
    mydb = QSqlDatabase::addDatabase(CONNECT_TYPE);
    mydb.setHostName("lakartxela.iutbayonne.univ-pau.fr");
    mydb.setDatabaseName(DATABASE_NAME);
    mydb.setUserName("nelduayen_bd");
    mydb.setPassword("nelduayen_bd");
    return mydb.open();
}

void Database::closeDataBase()
{
    mydb.close();
}

void Database::testDB()
{
    qDebug() << mydb.tables();
}


