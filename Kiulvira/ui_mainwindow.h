/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionNouveauTag;
    QAction *actionNouveauGroupe;
    QAction *actionFermer;
    QAction *actionAssocierFichier;
    QAction *actionAssocierGroupe;
    QAction *actionDesassocierFichier;
    QAction *actionDesassocierGroupe;
    QAction *actionRechercher;
    QWidget *centralWidget;
    QMenuBar *menuBar;
    QMenu *menuFichier;
    QMenu *menuEdition;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(720, 600);
        MainWindow->setWindowTitle(QStringLiteral("Kiulvira"));
        actionNouveauTag = new QAction(MainWindow);
        actionNouveauTag->setObjectName(QStringLiteral("actionNouveauTag"));
        actionNouveauGroupe = new QAction(MainWindow);
        actionNouveauGroupe->setObjectName(QStringLiteral("actionNouveauGroupe"));
        actionFermer = new QAction(MainWindow);
        actionFermer->setObjectName(QStringLiteral("actionFermer"));
        actionAssocierFichier = new QAction(MainWindow);
        actionAssocierFichier->setObjectName(QStringLiteral("actionAssocierFichier"));
        actionAssocierGroupe = new QAction(MainWindow);
        actionAssocierGroupe->setObjectName(QStringLiteral("actionAssocierGroupe"));
        actionDesassocierFichier = new QAction(MainWindow);
        actionDesassocierFichier->setObjectName(QStringLiteral("actionDesassocierFichier"));
        actionDesassocierGroupe = new QAction(MainWindow);
        actionDesassocierGroupe->setObjectName(QStringLiteral("actionDesassocierGroupe"));
        actionRechercher = new QAction(MainWindow);
        actionRechercher->setObjectName(QStringLiteral("actionRechercher"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 720, 24));
        menuFichier = new QMenu(menuBar);
        menuFichier->setObjectName(QStringLiteral("menuFichier"));
        menuEdition = new QMenu(menuBar);
        menuEdition->setObjectName(QStringLiteral("menuEdition"));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFichier->menuAction());
        menuBar->addAction(menuEdition->menuAction());
        menuFichier->addAction(actionNouveauTag);
        menuFichier->addAction(actionNouveauGroupe);
        menuFichier->addSeparator();
        menuFichier->addAction(actionFermer);
        menuEdition->addAction(actionAssocierFichier);
        menuEdition->addAction(actionAssocierGroupe);
        menuEdition->addSeparator();
        menuEdition->addAction(actionDesassocierFichier);
        menuEdition->addAction(actionDesassocierGroupe);
        menuEdition->addSeparator();
        menuEdition->addAction(actionRechercher);
        menuEdition->addSeparator();

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        actionNouveauTag->setText(QApplication::translate("MainWindow", "Nouvelle \303\251tiquette", 0));
        actionNouveauGroupe->setText(QApplication::translate("MainWindow", "Nouveau groupe", 0));
        actionFermer->setText(QApplication::translate("MainWindow", "Fermer", 0));
        actionAssocierFichier->setText(QApplication::translate("MainWindow", "Associer au fichier ...", 0));
        actionAssocierGroupe->setText(QApplication::translate("MainWindow", "Associer au groupe ...", 0));
        actionDesassocierFichier->setText(QApplication::translate("MainWindow", "D\303\251sassocier du fichier", 0));
        actionDesassocierGroupe->setText(QApplication::translate("MainWindow", "D\303\251sassocier du groupe", 0));
        actionRechercher->setText(QApplication::translate("MainWindow", "Rechercher", 0));
        menuFichier->setTitle(QApplication::translate("MainWindow", "Fichier", 0));
        menuEdition->setTitle(QApplication::translate("MainWindow", "Edition", 0));
        Q_UNUSED(MainWindow);
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
