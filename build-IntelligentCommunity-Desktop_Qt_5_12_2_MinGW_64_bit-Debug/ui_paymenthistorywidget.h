/********************************************************************************
** Form generated from reading UI file 'paymenthistorywidget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PAYMENTHISTORYWIDGET_H
#define UI_PAYMENTHISTORYWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_paymenthistorywidget
{
public:

    void setupUi(QWidget *paymenthistorywidget)
    {
        if (paymenthistorywidget->objectName().isEmpty())
            paymenthistorywidget->setObjectName(QString::fromUtf8("paymenthistorywidget"));
        paymenthistorywidget->resize(400, 300);

        retranslateUi(paymenthistorywidget);

        QMetaObject::connectSlotsByName(paymenthistorywidget);
    } // setupUi

    void retranslateUi(QWidget *paymenthistorywidget)
    {
        paymenthistorywidget->setWindowTitle(QApplication::translate("paymenthistorywidget", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class paymenthistorywidget: public Ui_paymenthistorywidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PAYMENTHISTORYWIDGET_H
