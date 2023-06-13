#ifndef MODIFIERDIAPORAMA_H
#define MODIFIERDIAPORAMA_H

#include <QDialog>
#include <QSqlQuery>
#include "database.h"
#include <QTableWidget>

namespace Ui {
class ModifierDiaporama;
}

class ModifierDiaporama : public QDialog
{
    Q_OBJECT

public:
    explicit ModifierDiaporama(QWidget *parent = nullptr);
    ~ModifierDiaporama();

private:
    Ui::ModifierDiaporama *ui;
    Database mydb;

private slots:
    void itemModified(QTableWidgetItem *item);
};

#endif // MODIFIERDIAPORAMA_H
