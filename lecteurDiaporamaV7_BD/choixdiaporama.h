#ifndef CHOIXDIAPORAMA_H
#define CHOIXDIAPORAMA_H

#include <QDialog>
#include <QSqlQuery>

namespace Ui {
class choixDiaporama;
}

class choixDiaporama : public QDialog
{
    Q_OBJECT

public:
    explicit choixDiaporama(QWidget *parent = nullptr);
    ~choixDiaporama();
    int getSelectedDiaporamaId() const;
    int exec();

public slots:
    void lineSelect(const QModelIndex & index);

private:
    Ui::choixDiaporama *ui;
    int selectedDiaporamaId;
};

#endif // CHOIXDIAPORAMA_H
