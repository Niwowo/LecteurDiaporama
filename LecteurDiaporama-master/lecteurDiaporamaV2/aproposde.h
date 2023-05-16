#ifndef APROPOSDE_H
#define APROPOSDE_H

#include <QDialog>

namespace Ui {
class AProposDe;
}

class AProposDe : public QDialog
{
    Q_OBJECT

public:
    explicit AProposDe(QWidget *parent = nullptr);
    ~AProposDe();

private:
    Ui::AProposDe *ui;
};

#endif // APROPOSDE_H
