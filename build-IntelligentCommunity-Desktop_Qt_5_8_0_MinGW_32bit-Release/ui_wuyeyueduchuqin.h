/********************************************************************************
** Form generated from reading UI file 'wuyeyueduchuqin.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WUYEYUEDUCHUQIN_H
#define UI_WUYEYUEDUCHUQIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Wuyeyueduchuqin
{
public:
    QLabel *label;
    QPushButton *pushButton_2;
    QTextEdit *textEdit;
    QPushButton *pushButton1;

    void setupUi(QWidget *Wuyeyueduchuqin)
    {
        if (Wuyeyueduchuqin->objectName().isEmpty())
            Wuyeyueduchuqin->setObjectName(QStringLiteral("Wuyeyueduchuqin"));
        Wuyeyueduchuqin->resize(622, 591);
        label = new QLabel(Wuyeyueduchuqin);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(180, 10, 181, 51));
        pushButton_2 = new QPushButton(Wuyeyueduchuqin);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(310, 520, 93, 28));
        textEdit = new QTextEdit(Wuyeyueduchuqin);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(30, 90, 541, 381));
        pushButton1 = new QPushButton(Wuyeyueduchuqin);
        pushButton1->setObjectName(QStringLiteral("pushButton1"));
        pushButton1->setGeometry(QRect(140, 520, 93, 28));

        retranslateUi(Wuyeyueduchuqin);
        QObject::connect(pushButton_2, SIGNAL(clicked()), Wuyeyueduchuqin, SLOT(close()));

        QMetaObject::connectSlotsByName(Wuyeyueduchuqin);
    } // setupUi

    void retranslateUi(QWidget *Wuyeyueduchuqin)
    {
        Wuyeyueduchuqin->setWindowTitle(QApplication::translate("Wuyeyueduchuqin", "Form", Q_NULLPTR));
        label->setText(QApplication::translate("Wuyeyueduchuqin", "<html><head/><body><p><span style=\" font-size:18pt; font-weight:600;\">\346\234\210\345\272\246\345\207\272\345\213\244\346\203\205\345\206\265</span></p></body></html>", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("Wuyeyueduchuqin", "\351\200\200\345\207\272", Q_NULLPTR));
        pushButton1->setText(QApplication::translate("Wuyeyueduchuqin", "\350\257\246\347\273\206", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Wuyeyueduchuqin: public Ui_Wuyeyueduchuqin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WUYEYUEDUCHUQIN_H
