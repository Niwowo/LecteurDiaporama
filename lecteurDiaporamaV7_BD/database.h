#ifndef DATABASE_H
#define DATABASE_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlTableModel>

#define DATABASE_NAME "BD_Nodenot_SAE"
#define CONNECT_TYPE "QODBC"

class Database
{
public:
    Database();
    bool openDataBase();
    void closeDataBase();
    void testDB();

private:
    QSqlDatabase mydb;
};

#endif // DATABASE_H
