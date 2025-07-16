/********************************************************************************
** Form generated from reading UI file 'admin_mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMIN_MAINWINDOW_H
#define UI_ADMIN_MAINWINDOW_H

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

class Ui_admin_MainWindow
{
public:
    QAction *action;
    QWidget *centralwidget;
    QMenuBar *menubar;
    QMenu *menu;
    QMenu *menu_2;
    QMenu *menu_3;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *admin_MainWindow)
    {
        if (admin_MainWindow->objectName().isEmpty())
            admin_MainWindow->setObjectName(QStringLiteral("admin_MainWindow"));
        admin_MainWindow->resize(700, 700);
        action = new QAction(admin_MainWindow);
        action->setObjectName(QStringLiteral("action"));
        centralwidget = new QWidget(admin_MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        admin_MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(admin_MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 700, 26));
        menu = new QMenu(menubar);
        menu->setObjectName(QStringLiteral("menu"));
        menu_2 = new QMenu(menubar);
        menu_2->setObjectName(QStringLiteral("menu_2"));
        menu_3 = new QMenu(menubar);
        menu_3->setObjectName(QStringLiteral("menu_3"));
        admin_MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(admin_MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        admin_MainWindow->setStatusBar(statusbar);

        menubar->addAction(menu->menuAction());
        menubar->addAction(menu_2->menuAction());
        menubar->addAction(menu_3->menuAction());
        menu->addAction(action);

        retranslateUi(admin_MainWindow);

        QMetaObject::connectSlotsByName(admin_MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *admin_MainWindow)
    {
        admin_MainWindow->setWindowTitle(QApplication::translate("admin_MainWindow", "MainWindow", Q_NULLPTR));
        action->setText(QApplication::translate("admin_MainWindow", "\344\272\272\344\272\213\347\256\241\347\220\206", Q_NULLPTR));
        menu->setTitle(QApplication::translate("admin_MainWindow", "\344\272\272\344\272\213\347\256\241\347\220\206", Q_NULLPTR));
        menu_2->setTitle(QApplication::translate("admin_MainWindow", "\345\207\272\345\213\244\347\256\241\347\220\206", Q_NULLPTR));
        menu_3->setTitle(QApplication::translate("admin_MainWindow", "\347\263\273\347\273\237\350\256\276\347\275\256", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class admin_MainWindow: public Ui_admin_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMIN_MAINWINDOW_H
