/********************************************************************************
** Form generated from reading UI file 'wuyeyueduchuqin.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WUYEYUEDUCHUQIN_H
#define UI_WUYEYUEDUCHUQIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Wuyeyueduchuqin
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QTableView *tableView;
    QPushButton *pushButton1;
    QPushButton *pushButton_2;

    void setupUi(QWidget *Wuyeyueduchuqin)
    {
        if (Wuyeyueduchuqin->objectName().isEmpty())
            Wuyeyueduchuqin->setObjectName(QString::fromUtf8("Wuyeyueduchuqin"));
        Wuyeyueduchuqin->resize(622, 591);
        gridLayout = new QGridLayout(Wuyeyueduchuqin);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(Wuyeyueduchuqin);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        tableView = new QTableView(Wuyeyueduchuqin);
        tableView->setObjectName(QString::fromUtf8("tableView"));

        gridLayout->addWidget(tableView, 1, 1, 1, 1);

        pushButton1 = new QPushButton(Wuyeyueduchuqin);
        pushButton1->setObjectName(QString::fromUtf8("pushButton1"));

        gridLayout->addWidget(pushButton1, 2, 0, 1, 1);

        pushButton_2 = new QPushButton(Wuyeyueduchuqin);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        gridLayout->addWidget(pushButton_2, 2, 1, 1, 1);


        retranslateUi(Wuyeyueduchuqin);
        QObject::connect(pushButton_2, SIGNAL(clicked()), Wuyeyueduchuqin, SLOT(close()));

        QMetaObject::connectSlotsByName(Wuyeyueduchuqin);
    } // setupUi

    void retranslateUi(QWidget *Wuyeyueduchuqin)
    {
        Wuyeyueduchuqin->setWindowTitle(QApplication::translate("Wuyeyueduchuqin", "Form", nullptr));
        label->setText(QApplication::translate("Wuyeyueduchuqin", "<html><head/><body><p><span style=\" font-size:18pt; font-weight:600;\">\346\234\210\345\272\246\345\207\272\345\213\244\346\203\205\345\206\265</span></p></body></html>", nullptr));
        pushButton1->setText(QApplication::translate("Wuyeyueduchuqin", "\350\257\246\347\273\206", nullptr));
        pushButton_2->setText(QApplication::translate("Wuyeyueduchuqin", "\351\200\200\345\207\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Wuyeyueduchuqin: public Ui_Wuyeyueduchuqin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WUYEYUEDUCHUQIN_H
