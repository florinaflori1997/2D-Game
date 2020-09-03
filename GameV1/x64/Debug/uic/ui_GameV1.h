/********************************************************************************
** Form generated from reading UI file 'GameV1.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAMEV1_H
#define UI_GAMEV1_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GameV1Class
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *GameV1Class)
    {
        if (GameV1Class->objectName().isEmpty())
            GameV1Class->setObjectName(QString::fromUtf8("GameV1Class"));
        GameV1Class->resize(600, 400);
        menuBar = new QMenuBar(GameV1Class);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        GameV1Class->setMenuBar(menuBar);
        mainToolBar = new QToolBar(GameV1Class);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        GameV1Class->addToolBar(mainToolBar);
        centralWidget = new QWidget(GameV1Class);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        GameV1Class->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(GameV1Class);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        GameV1Class->setStatusBar(statusBar);

        retranslateUi(GameV1Class);

        QMetaObject::connectSlotsByName(GameV1Class);
    } // setupUi

    void retranslateUi(QMainWindow *GameV1Class)
    {
        GameV1Class->setWindowTitle(QCoreApplication::translate("GameV1Class", "GameV1", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GameV1Class: public Ui_GameV1Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMEV1_H
