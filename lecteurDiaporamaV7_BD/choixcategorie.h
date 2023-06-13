#ifndef CHOIXCATEGORIE_H
#define CHOIXCATEGORIE_H

#include <QDialog>
#include <QSqlQuery>

namespace Ui {
class ChoixCategorie;
}

class ChoixCategorie : public QDialog
{
    Q_OBJECT

public:
    explicit ChoixCategorie(QWidget *parent = nullptr);
    ~ChoixCategorie();
    QString getSelectedCategory() const;
    void chargerCategories(const std::vector<QString>& categories);

private:
    Ui::ChoixCategorie *ui;
};

#endif // CHOIXCATEGORIE_H
