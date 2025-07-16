/********************************************************************************
** Form generated from reading UI file 'worker_mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WORKER_MAINWINDOW_H
#define UI_WORKER_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_worker_MainWindow
{
public:
    QAction *action;
    QAction *actionrenshi;
    QAction *action_2;
    QAction *action_3;
    QAction *action_4;
    QAction *action_5;
    QAction *action_6;
    QAction *action_7;
    QAction *action_8;
    QWidget *centralwidget;
    QMenuBar *menubar;
    QMenu *menu;
    QMenu *menu_2;
    QMenu *menu_3;
    QMenu *menu_4;
    QMenu *menu_5;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *worker_MainWindow)
    {
        if (worker_MainWindow->objectName().isEmpty())
            worker_MainWindow->setObjectName(QString::fromUtf8("worker_MainWindow"));
        worker_MainWindow->resize(700, 700);
        worker_MainWindow->setStyleSheet(QString::fromUtf8(""));
        action = new QAction(worker_MainWindow);
        action->setObjectName(QString::fromUtf8("action"));
        actionrenshi = new QAction(worker_MainWindow);
        actionrenshi->setObjectName(QString::fromUtf8("actionrenshi"));
        action_2 = new QAction(worker_MainWindow);
        action_2->setObjectName(QString::fromUtf8("action_2"));
        action_3 = new QAction(worker_MainWindow);
        action_3->setObjectName(QString::fromUtf8("action_3"));
        action_4 = new QAction(worker_MainWindow);
        action_4->setObjectName(QString::fromUtf8("action_4"));
        action_5 = new QAction(worker_MainWindow);
        action_5->setObjectName(QString::fromUtf8("action_5"));
        action_6 = new QAction(worker_MainWindow);
        action_6->setObjectName(QString::fromUtf8("action_6"));
        action_7 = new QAction(worker_MainWindow);
        action_7->setObjectName(QString::fromUtf8("action_7"));
        action_8 = new QAction(worker_MainWindow);
        action_8->setObjectName(QString::fromUtf8("action_8"));
        centralwidget = new QWidget(worker_MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        worker_MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(worker_MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 700, 19));
        menu = new QMenu(menubar);
        menu->setObjectName(QString::fromUtf8("menu"));
        menu_2 = new QMenu(menubar);
        menu_2->setObjectName(QString::fromUtf8("menu_2"));
        menu_3 = new QMenu(menubar);
        menu_3->setObjectName(QString::fromUtf8("menu_3"));
        menu_4 = new QMenu(menubar);
        menu_4->setObjectName(QString::fromUtf8("menu_4"));
        menu_5 = new QMenu(menubar);
        menu_5->setObjectName(QString::fromUtf8("menu_5"));
        worker_MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(worker_MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        worker_MainWindow->setStatusBar(statusbar);

        menubar->addAction(menu->menuAction());
        menubar->addAction(menu_2->menuAction());
        menubar->addAction(menu_3->menuAction());
        menubar->addAction(menu_4->menuAction());
        menubar->addAction(menu_5->menuAction());
        menu->addAction(action);
        menu_2->addAction(actionrenshi);
        menu_2->addAction(action_3);
        menu_2->addAction(action_4);
        menu_3->addAction(action_5);
        menu_3->addAction(action_6);
        menu_4->addAction(action_2);
        menu_5->addAction(action_7);
        menu_5->addAction(action_8);

        retranslateUi(worker_MainWindow);

        QMetaObject::connectSlotsByName(worker_MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *worker_MainWindow)
    {
        worker_MainWindow->setWindowTitle(QApplication::translate("worker_MainWindow", "MainWindow", nullptr));
        action->setText(QApplication::translate("worker_MainWindow", "\344\270\232\344\270\273\344\277\241\346\201\257\347\256\241\347\220\206", nullptr));
        actionrenshi->setText(QApplication::translate("worker_MainWindow", "\350\257\267\351\224\200\345\201\207", nullptr));
        action_2->setText(QApplication::translate("worker_MainWindow", "\347\273\264\344\277\256\347\256\241\347\220\206", nullptr));
        action_3->setText(QApplication::translate("worker_MainWindow", "\346\234\210\345\272\246\345\207\272\345\213\244", nullptr));
        action_4->setText(QApplication::translate("worker_MainWindow", "\344\270\212\344\270\213\347\217\255\347\231\273\350\256\260", nullptr));
        action_5->setText(QApplication::translate("worker_MainWindow", "\350\275\246\344\275\215\344\277\241\346\201\257\347\256\241\347\220\206 ", nullptr));
        action_6->setText(QApplication::translate("worker_MainWindow", "\350\275\246\344\275\215\345\207\272\347\247\237", nullptr));
        action_7->setText(QApplication::translate("worker_MainWindow", "\347\211\251\344\270\232\347\274\264\350\264\271", nullptr));
        action_8->setText(QApplication::translate("worker_MainWindow", "\347\274\264\350\264\271\350\256\260\345\275\225", nullptr));
        menu->setTitle(QApplication::translate("worker_MainWindow", "\344\270\232\344\270\273\347\256\241\347\220\206", nullptr));
        menu_2->setTitle(QApplication::translate("worker_MainWindow", "\344\272\272\344\272\213\347\256\241\347\220\206", nullptr));
        menu_3->setTitle(QApplication::translate("worker_MainWindow", "\350\275\246\344\275\215\347\256\241\347\220\206", nullptr));
        menu_4->setTitle(QApplication::translate("worker_MainWindow", "\347\273\264\344\277\256\347\256\241\347\220\206", nullptr));
        menu_5->setTitle(QApplication::translate("worker_MainWindow", "\347\274\264\350\264\271\347\256\241\347\220\206", nullptr));
    } // retranslateUi

};

namespace Ui {
    class worker_MainWindow: public Ui_worker_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WORKER_MAINWINDOW_H
