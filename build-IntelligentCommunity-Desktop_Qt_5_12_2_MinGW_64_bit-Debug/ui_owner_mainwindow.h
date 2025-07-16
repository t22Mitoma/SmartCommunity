/********************************************************************************
** Form generated from reading UI file 'owner_mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OWNER_MAINWINDOW_H
#define UI_OWNER_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Owner_MainWindow
{
public:
    QAction *action;
    QAction *action_2;
    QAction *action_3;
    QAction *action_4;
    QAction *action_5;
    QWidget *centralwidget;
    QMenuBar *menubar;
    QMenu *menu;
    QMenu *menu_2;
    QMenu *menu_3;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Owner_MainWindow)
    {
        if (Owner_MainWindow->objectName().isEmpty())
            Owner_MainWindow->setObjectName(QString::fromUtf8("Owner_MainWindow"));
        Owner_MainWindow->resize(700, 700);
        action = new QAction(Owner_MainWindow);
        action->setObjectName(QString::fromUtf8("action"));
        action_2 = new QAction(Owner_MainWindow);
        action_2->setObjectName(QString::fromUtf8("action_2"));
        action_3 = new QAction(Owner_MainWindow);
        action_3->setObjectName(QString::fromUtf8("action_3"));
        action_4 = new QAction(Owner_MainWindow);
        action_4->setObjectName(QString::fromUtf8("action_4"));
        action_5 = new QAction(Owner_MainWindow);
        action_5->setObjectName(QString::fromUtf8("action_5"));
        centralwidget = new QWidget(Owner_MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        Owner_MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Owner_MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 700, 19));
        menu = new QMenu(menubar);
        menu->setObjectName(QString::fromUtf8("menu"));
        menu_2 = new QMenu(menubar);
        menu_2->setObjectName(QString::fromUtf8("menu_2"));
        menu_3 = new QMenu(menubar);
        menu_3->setObjectName(QString::fromUtf8("menu_3"));
        Owner_MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(Owner_MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        Owner_MainWindow->setStatusBar(statusbar);

        menubar->addAction(menu->menuAction());
        menubar->addAction(menu_2->menuAction());
        menubar->addAction(menu_3->menuAction());
        menu->addAction(action_4);
        menu_2->addAction(action);
        menu_2->addAction(action_5);
        menu_3->addAction(action_3);
        menu_3->addAction(action_2);

        retranslateUi(Owner_MainWindow);

        QMetaObject::connectSlotsByName(Owner_MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *Owner_MainWindow)
    {
        Owner_MainWindow->setWindowTitle(QApplication::translate("Owner_MainWindow", "MainWindow", nullptr));
        action->setText(QApplication::translate("Owner_MainWindow", "\344\270\232\344\270\273\347\274\264\350\264\271", nullptr));
        action_2->setText(QApplication::translate("Owner_MainWindow", "\346\225\205\351\232\234\346\237\245\350\257\242\345\222\214\350\257\204\344\273\267", nullptr));
        action_3->setText(QApplication::translate("Owner_MainWindow", "\346\225\205\351\232\234\346\212\245\344\277\256", nullptr));
        action_4->setText(QApplication::translate("Owner_MainWindow", "\350\275\246\344\275\215\347\256\241\347\220\206", nullptr));
        action_5->setText(QApplication::translate("Owner_MainWindow", "\347\274\264\350\264\271\350\256\260\345\275\225", nullptr));
        menu->setTitle(QApplication::translate("Owner_MainWindow", "\350\275\246\344\275\215\347\256\241\347\220\206", nullptr));
        menu_2->setTitle(QApplication::translate("Owner_MainWindow", "\347\274\264\350\264\271\347\256\241\347\220\206", nullptr));
        menu_3->setTitle(QApplication::translate("Owner_MainWindow", "\347\273\264\344\277\256\347\256\241\347\220\206", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Owner_MainWindow: public Ui_Owner_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OWNER_MAINWINDOW_H
