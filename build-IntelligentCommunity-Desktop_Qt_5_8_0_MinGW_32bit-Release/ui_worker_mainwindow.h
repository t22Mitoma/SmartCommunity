/********************************************************************************
** Form generated from reading UI file 'worker_mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WORKER_MAINWINDOW_H
#define UI_WORKER_MAINWINDOW_H

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
            worker_MainWindow->setObjectName(QStringLiteral("worker_MainWindow"));
        worker_MainWindow->resize(700, 700);
        worker_MainWindow->setStyleSheet(QStringLiteral(""));
        action = new QAction(worker_MainWindow);
        action->setObjectName(QStringLiteral("action"));
        actionrenshi = new QAction(worker_MainWindow);
        actionrenshi->setObjectName(QStringLiteral("actionrenshi"));
        action_2 = new QAction(worker_MainWindow);
        action_2->setObjectName(QStringLiteral("action_2"));
        action_3 = new QAction(worker_MainWindow);
        action_3->setObjectName(QStringLiteral("action_3"));
        action_4 = new QAction(worker_MainWindow);
        action_4->setObjectName(QStringLiteral("action_4"));
        action_5 = new QAction(worker_MainWindow);
        action_5->setObjectName(QStringLiteral("action_5"));
        action_6 = new QAction(worker_MainWindow);
        action_6->setObjectName(QStringLiteral("action_6"));
        centralwidget = new QWidget(worker_MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        worker_MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(worker_MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 700, 26));
        menu = new QMenu(menubar);
        menu->setObjectName(QStringLiteral("menu"));
        menu_2 = new QMenu(menubar);
        menu_2->setObjectName(QStringLiteral("menu_2"));
        menu_3 = new QMenu(menubar);
        menu_3->setObjectName(QStringLiteral("menu_3"));
        menu_4 = new QMenu(menubar);
        menu_4->setObjectName(QStringLiteral("menu_4"));
        menu_5 = new QMenu(menubar);
        menu_5->setObjectName(QStringLiteral("menu_5"));
        worker_MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(worker_MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
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

        retranslateUi(worker_MainWindow);

        QMetaObject::connectSlotsByName(worker_MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *worker_MainWindow)
    {
        worker_MainWindow->setWindowTitle(QApplication::translate("worker_MainWindow", "MainWindow", Q_NULLPTR));
        action->setText(QApplication::translate("worker_MainWindow", "\344\270\232\344\270\273\344\277\241\346\201\257\347\256\241\347\220\206", Q_NULLPTR));
        actionrenshi->setText(QApplication::translate("worker_MainWindow", "\350\257\267\351\224\200\345\201\207", Q_NULLPTR));
        action_2->setText(QApplication::translate("worker_MainWindow", "\347\273\264\344\277\256\347\256\241\347\220\206", Q_NULLPTR));
        action_3->setText(QApplication::translate("worker_MainWindow", "\346\234\210\345\272\246\345\207\272\345\213\244", Q_NULLPTR));
        action_4->setText(QApplication::translate("worker_MainWindow", "\344\270\212\344\270\213\347\217\255\347\231\273\350\256\260", Q_NULLPTR));
        action_5->setText(QApplication::translate("worker_MainWindow", "\350\275\246\344\275\215\344\277\241\346\201\257\347\256\241\347\220\206 ", Q_NULLPTR));
        action_6->setText(QApplication::translate("worker_MainWindow", "\350\275\246\344\275\215\345\207\272\347\247\237", Q_NULLPTR));
        menu->setTitle(QApplication::translate("worker_MainWindow", "\344\270\232\344\270\273\347\256\241\347\220\206", Q_NULLPTR));
        menu_2->setTitle(QApplication::translate("worker_MainWindow", "\344\272\272\344\272\213\347\256\241\347\220\206", Q_NULLPTR));
        menu_3->setTitle(QApplication::translate("worker_MainWindow", "\350\275\246\344\275\215\347\256\241\347\220\206", Q_NULLPTR));
        menu_4->setTitle(QApplication::translate("worker_MainWindow", "\347\273\264\344\277\256\347\256\241\347\220\206", Q_NULLPTR));
        menu_5->setTitle(QApplication::translate("worker_MainWindow", "\347\274\264\350\264\271\347\256\241\347\220\206", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class worker_MainWindow: public Ui_worker_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WORKER_MAINWINDOW_H
