/********************************************************************************
** Form generated from reading UI file 'admin_mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMIN_MAINWINDOW_H
#define UI_ADMIN_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_admin_MainWindow
{
public:
    QAction *action;
    QAction *actionqingjiashenpi;
    QWidget *centralwidget;
    QMenuBar *menubar;
    QMenu *menu;
    QMenu *menu_2;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *admin_MainWindow)
    {
        if (admin_MainWindow->objectName().isEmpty())
            admin_MainWindow->setObjectName(QString::fromUtf8("admin_MainWindow"));
        admin_MainWindow->resize(700, 700);
        action = new QAction(admin_MainWindow);
        action->setObjectName(QString::fromUtf8("action"));
        actionqingjiashenpi = new QAction(admin_MainWindow);
        actionqingjiashenpi->setObjectName(QString::fromUtf8("actionqingjiashenpi"));
        centralwidget = new QWidget(admin_MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        admin_MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(admin_MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 700, 19));
        menu = new QMenu(menubar);
        menu->setObjectName(QString::fromUtf8("menu"));
        menu_2 = new QMenu(menubar);
        menu_2->setObjectName(QString::fromUtf8("menu_2"));
        admin_MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(admin_MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        admin_MainWindow->setStatusBar(statusbar);

        menubar->addAction(menu->menuAction());
        menubar->addAction(menu_2->menuAction());
        menu->addAction(action);
        menu_2->addAction(actionqingjiashenpi);

        retranslateUi(admin_MainWindow);

        QMetaObject::connectSlotsByName(admin_MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *admin_MainWindow)
    {
        admin_MainWindow->setWindowTitle(QApplication::translate("admin_MainWindow", "MainWindow", nullptr));
        action->setText(QApplication::translate("admin_MainWindow", "\344\272\272\344\272\213\347\256\241\347\220\206", nullptr));
        actionqingjiashenpi->setText(QApplication::translate("admin_MainWindow", "\350\257\267\345\201\207\345\256\241\346\211\271", nullptr));
        actionqingjiashenpi->setIconText(QApplication::translate("admin_MainWindow", "\350\257\267\345\201\207\345\256\241\346\211\271", nullptr));
        menu->setTitle(QApplication::translate("admin_MainWindow", "\344\272\272\344\272\213\347\256\241\347\220\206", nullptr));
        menu_2->setTitle(QApplication::translate("admin_MainWindow", "\345\207\272\345\213\244\347\256\241\347\220\206", nullptr));
    } // retranslateUi

};

namespace Ui {
    class admin_MainWindow: public Ui_admin_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMIN_MAINWINDOW_H
