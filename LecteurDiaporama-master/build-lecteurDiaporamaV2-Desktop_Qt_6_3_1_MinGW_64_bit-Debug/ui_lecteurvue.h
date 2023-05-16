/********************************************************************************
** Form generated from reading UI file 'lecteurvue.ui'
**
** Created by: Qt User Interface Compiler version 6.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LECTEURVUE_H
#define UI_LECTEURVUE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LecteurVue
{
public:
    QAction *actionQuitter;
    QAction *actionCharger_diaporama;
    QAction *actionEnlever_diaporama;
    QAction *actionx1;
    QAction *actionx0_5;
    QAction *actionx2;
    QAction *actionA_propos_de;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QLabel *lTitre;
    QSpacerItem *vSpacer;
    QGridLayout *gLayoutBoutons;
    QPushButton *pGauche;
    QSpacerItem *hSpacer1;
    QPushButton *pLecture;
    QPushButton *pPause;
    QSpacerItem *hSpacer2;
    QPushButton *pDroite;
    QPushButton *pCategorie;
    QStatusBar *statusbar;
    QMenuBar *menubar;
    QMenu *menuFichier;
    QMenu *menuParam_tre;
    QMenu *menuVitesse_de_d_filement;
    QMenu *menuAide;

    void setupUi(QMainWindow *LecteurVue)
    {
        if (LecteurVue->objectName().isEmpty())
            LecteurVue->setObjectName(QString::fromUtf8("LecteurVue"));
        LecteurVue->resize(800, 600);
        LecteurVue->setLayoutDirection(Qt::LeftToRight);
        actionQuitter = new QAction(LecteurVue);
        actionQuitter->setObjectName(QString::fromUtf8("actionQuitter"));
        actionCharger_diaporama = new QAction(LecteurVue);
        actionCharger_diaporama->setObjectName(QString::fromUtf8("actionCharger_diaporama"));
        actionEnlever_diaporama = new QAction(LecteurVue);
        actionEnlever_diaporama->setObjectName(QString::fromUtf8("actionEnlever_diaporama"));
        actionx1 = new QAction(LecteurVue);
        actionx1->setObjectName(QString::fromUtf8("actionx1"));
        actionx0_5 = new QAction(LecteurVue);
        actionx0_5->setObjectName(QString::fromUtf8("actionx0_5"));
        actionx2 = new QAction(LecteurVue);
        actionx2->setObjectName(QString::fromUtf8("actionx2"));
        actionA_propos_de = new QAction(LecteurVue);
        actionA_propos_de->setObjectName(QString::fromUtf8("actionA_propos_de"));
        centralwidget = new QWidget(LecteurVue);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        lTitre = new QLabel(centralwidget);
        lTitre->setObjectName(QString::fromUtf8("lTitre"));
        QFont font;
        font.setPointSize(18);
        font.setBold(true);
        font.setStrikeOut(false);
        lTitre->setFont(font);
        lTitre->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(lTitre);

        vSpacer = new QSpacerItem(20, 340, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(vSpacer);

        gLayoutBoutons = new QGridLayout();
        gLayoutBoutons->setObjectName(QString::fromUtf8("gLayoutBoutons"));
        pGauche = new QPushButton(centralwidget);
        pGauche->setObjectName(QString::fromUtf8("pGauche"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pGauche->sizePolicy().hasHeightForWidth());
        pGauche->setSizePolicy(sizePolicy);
        pGauche->setMaximumSize(QSize(25, 16777215));
        pGauche->setLayoutDirection(Qt::LeftToRight);

        gLayoutBoutons->addWidget(pGauche, 0, 0, 1, 1);

        hSpacer1 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gLayoutBoutons->addItem(hSpacer1, 0, 1, 1, 1);

        pLecture = new QPushButton(centralwidget);
        pLecture->setObjectName(QString::fromUtf8("pLecture"));
        sizePolicy.setHeightForWidth(pLecture->sizePolicy().hasHeightForWidth());
        pLecture->setSizePolicy(sizePolicy);

        gLayoutBoutons->addWidget(pLecture, 0, 2, 1, 1);

        pPause = new QPushButton(centralwidget);
        pPause->setObjectName(QString::fromUtf8("pPause"));
        sizePolicy.setHeightForWidth(pPause->sizePolicy().hasHeightForWidth());
        pPause->setSizePolicy(sizePolicy);

        gLayoutBoutons->addWidget(pPause, 0, 3, 1, 1);

        hSpacer2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gLayoutBoutons->addItem(hSpacer2, 0, 4, 1, 1);

        pDroite = new QPushButton(centralwidget);
        pDroite->setObjectName(QString::fromUtf8("pDroite"));
        sizePolicy.setHeightForWidth(pDroite->sizePolicy().hasHeightForWidth());
        pDroite->setSizePolicy(sizePolicy);
        pDroite->setMaximumSize(QSize(25, 16777215));

        gLayoutBoutons->addWidget(pDroite, 0, 5, 1, 1);

        pCategorie = new QPushButton(centralwidget);
        pCategorie->setObjectName(QString::fromUtf8("pCategorie"));

        gLayoutBoutons->addWidget(pCategorie, 1, 2, 1, 2);


        verticalLayout->addLayout(gLayoutBoutons);

        LecteurVue->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(LecteurVue);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        LecteurVue->setStatusBar(statusbar);
        menubar = new QMenuBar(LecteurVue);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 22));
        menuFichier = new QMenu(menubar);
        menuFichier->setObjectName(QString::fromUtf8("menuFichier"));
        menuParam_tre = new QMenu(menubar);
        menuParam_tre->setObjectName(QString::fromUtf8("menuParam_tre"));
        menuVitesse_de_d_filement = new QMenu(menuParam_tre);
        menuVitesse_de_d_filement->setObjectName(QString::fromUtf8("menuVitesse_de_d_filement"));
        menuAide = new QMenu(menubar);
        menuAide->setObjectName(QString::fromUtf8("menuAide"));
        LecteurVue->setMenuBar(menubar);

        menubar->addAction(menuFichier->menuAction());
        menubar->addAction(menuParam_tre->menuAction());
        menubar->addAction(menuAide->menuAction());
        menuFichier->addAction(actionQuitter);
        menuParam_tre->addAction(actionCharger_diaporama);
        menuParam_tre->addAction(actionEnlever_diaporama);
        menuParam_tre->addAction(menuVitesse_de_d_filement->menuAction());
        menuVitesse_de_d_filement->addAction(actionx0_5);
        menuVitesse_de_d_filement->addAction(actionx1);
        menuVitesse_de_d_filement->addAction(actionx2);
        menuAide->addAction(actionA_propos_de);

        retranslateUi(LecteurVue);

        QMetaObject::connectSlotsByName(LecteurVue);
    } // setupUi

    void retranslateUi(QMainWindow *LecteurVue)
    {
        LecteurVue->setWindowTitle(QCoreApplication::translate("LecteurVue", "LecteurVue", nullptr));
        actionQuitter->setText(QCoreApplication::translate("LecteurVue", "Quitter", nullptr));
#if QT_CONFIG(shortcut)
        actionQuitter->setShortcut(QCoreApplication::translate("LecteurVue", "Ctrl+W", nullptr));
#endif // QT_CONFIG(shortcut)
        actionCharger_diaporama->setText(QCoreApplication::translate("LecteurVue", "Charger diaporama", nullptr));
#if QT_CONFIG(shortcut)
        actionCharger_diaporama->setShortcut(QCoreApplication::translate("LecteurVue", "Ctrl+O", nullptr));
#endif // QT_CONFIG(shortcut)
        actionEnlever_diaporama->setText(QCoreApplication::translate("LecteurVue", "Enlever diaporama", nullptr));
#if QT_CONFIG(shortcut)
        actionEnlever_diaporama->setShortcut(QCoreApplication::translate("LecteurVue", "Ctrl+E", nullptr));
#endif // QT_CONFIG(shortcut)
        actionx1->setText(QCoreApplication::translate("LecteurVue", "x1", nullptr));
#if QT_CONFIG(shortcut)
        actionx1->setShortcut(QCoreApplication::translate("LecteurVue", "Ctrl+1", nullptr));
#endif // QT_CONFIG(shortcut)
        actionx0_5->setText(QCoreApplication::translate("LecteurVue", "x0,5", nullptr));
#if QT_CONFIG(shortcut)
        actionx0_5->setShortcut(QCoreApplication::translate("LecteurVue", "Ctrl+0", nullptr));
#endif // QT_CONFIG(shortcut)
        actionx2->setText(QCoreApplication::translate("LecteurVue", "x2", nullptr));
#if QT_CONFIG(shortcut)
        actionx2->setShortcut(QCoreApplication::translate("LecteurVue", "Ctrl+2", nullptr));
#endif // QT_CONFIG(shortcut)
        actionA_propos_de->setText(QCoreApplication::translate("LecteurVue", "A propos de", nullptr));
#if QT_CONFIG(shortcut)
        actionA_propos_de->setShortcut(QCoreApplication::translate("LecteurVue", "Ctrl+H", nullptr));
#endif // QT_CONFIG(shortcut)
        lTitre->setText(QCoreApplication::translate("LecteurVue", "Titre du Diaporama", nullptr));
        pGauche->setText(QCoreApplication::translate("LecteurVue", "<", nullptr));
        pLecture->setText(QCoreApplication::translate("LecteurVue", "Lecture", nullptr));
        pPause->setText(QCoreApplication::translate("LecteurVue", "Pause", nullptr));
        pDroite->setText(QCoreApplication::translate("LecteurVue", ">", nullptr));
        pCategorie->setText(QCoreApplication::translate("LecteurVue", "Cat\303\251gorie", nullptr));
        menuFichier->setTitle(QCoreApplication::translate("LecteurVue", "Fichier", nullptr));
        menuParam_tre->setTitle(QCoreApplication::translate("LecteurVue", "Param\303\250tre", nullptr));
        menuVitesse_de_d_filement->setTitle(QCoreApplication::translate("LecteurVue", "Vitesse de d\303\251filement", nullptr));
        menuAide->setTitle(QCoreApplication::translate("LecteurVue", "Aide", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LecteurVue: public Ui_LecteurVue {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LECTEURVUE_H
