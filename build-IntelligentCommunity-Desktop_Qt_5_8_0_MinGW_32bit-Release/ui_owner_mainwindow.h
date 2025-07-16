/********************************************************************************
** Form generated from reading UI file 'owner_mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OWNER_MAINWINDOW_H
#define UI_OWNER_MAINWINDOW_H

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

class Ui_Owner_MainWindow
{
public:
    QAction *action;
    QAction *action_2;
    QAction *action_3;
    QWidget *centralwidget;
    QMenuBar *menubar;
    QMenu *menu;
    QMenu *menu_2;
    QMenu *menu_3;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Owner_MainWindow)
    {
        if (Owner_MainWindow->objectName().isEmpty())
            Owner_MainWindow->setObjectName(QStringLiteral("Owner_MainWindow"));
        Owner_MainWindow->resize(700, 700);
        action = new QAction(Owner_MainWindow);
        action->setObjectName(QStringLiteral("action"));
        action_2 = new QAction(Owner_MainWindow);
        action_2->setObjectName(QStringLiteral("action_2"));
        action_3 = new QAction(Owner_MainWindow);
        action_3->setObjectName(QStringLiteral("action_3"));
        centralwidget = new QWidget(Owner_MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        Owner_MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Owner_MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 700, 26));
        menu = new QMenu(menubar);
        menu->setObjectName(QStringLiteral("menu"));
        menu_2 = new QMenu(menubar);
        menu_2->setObjectName(QStringLiteral("menu_2"));
        menu_3 = new QMenu(menubar);
        menu_3->setObjectName(QStringLiteral("menu_3"));
        Owner_MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(Owner_MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        Owner_MainWindow->setStatusBar(statusbar);

        menubar->addAction(menu->menuAction());
        menubar->addAction(menu_2->menuAction());
        menubar->addAction(menu_3->menuAction());
        menu_2->addAction(action);
        menu_3->addAction(action_3);
        menu_3->addAction(action_2);

        retranslateUi(Owner_MainWindow);

        QMetaObject::connectSlotsByName(Owner_MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *Owner_MainWindow)
    {
        Owner_MainWindow->setWindowTitle(QApplication::translate("Owner_MainWindow", "MainWindow", Q_NULLPTR));
        action->setText(QApplication::translate("Owner_MainWindow", "\346\225\205\351\232\234\346\212\245\344\277\256", Q_NULLPTR));
        action_2->setText(QApplication::translate("Owner_MainWindow", "\346\225\205\351\232\234\346\237\245\350\257\242\345\222\214\350\257\204\344\273\267", Q_NULLPTR));
        action_3->setText(QApplication::translate("Owner_MainWindow", "\346\225\205\351\232\234\346\212\245\344\277\256", Q_NULLPTR));
        menu->setTitle(QApplication::translate("Owner_MainWindow", "\350\275\246\344\275\215\347\256\241\347\220\206", Q_NULLPTR));
        menu_2->setTitle(QApplication::translate("Owner_MainWindow", "\347\274\264\350\264\271\347\256\241\347\220\206", Q_NULLPTR));
        menu_3->setTitle(QApplication::translate("Owner_MainWindow", "\347\273\264\344\277\256\347\256\241\347\220\206", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Owner_MainWindow: public Ui_Owner_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OWNER_MAINWINDOW_H
