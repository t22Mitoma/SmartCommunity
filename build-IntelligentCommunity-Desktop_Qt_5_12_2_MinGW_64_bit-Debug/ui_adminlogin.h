/********************************************************************************
** Form generated from reading UI file 'adminlogin.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMINLOGIN_H
#define UI_ADMINLOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCommandLinkButton>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_adminlogin
{
public:
    QCommandLinkButton *commandLinkButton;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QPushButton *pushButton;

    void setupUi(QDialog *adminlogin)
    {
        if (adminlogin->objectName().isEmpty())
            adminlogin->setObjectName(QString::fromUtf8("adminlogin"));
        adminlogin->resize(1024, 768);
        adminlogin->setMinimumSize(QSize(1024, 768));
        adminlogin->setMaximumSize(QSize(1024, 768));
        adminlogin->setStyleSheet(QString::fromUtf8("#adminlogin{border-image: url(:/1111.png);}\n"
"#adminlogin *{image: url();}"));
        commandLinkButton = new QCommandLinkButton(adminlogin);
        commandLinkButton->setObjectName(QString::fromUtf8("commandLinkButton"));
        commandLinkButton->setGeometry(QRect(40, 660, 121, 61));
        commandLinkButton->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        layoutWidget = new QWidget(adminlogin);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(280, 80, 451, 471));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        lineEdit = new QLineEdit(layoutWidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        verticalLayout->addWidget(lineEdit);

        lineEdit_2 = new QLineEdit(layoutWidget);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));

        verticalLayout->addWidget(lineEdit_2);

        pushButton = new QPushButton(layoutWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setStyleSheet(QString::fromUtf8(""));

        verticalLayout->addWidget(pushButton);


        retranslateUi(adminlogin);

        QMetaObject::connectSlotsByName(adminlogin);
    } // setupUi

    void retranslateUi(QDialog *adminlogin)
    {
        adminlogin->setWindowTitle(QApplication::translate("adminlogin", "Dialog", nullptr));
        commandLinkButton->setText(QApplication::translate("adminlogin", "\350\277\224\345\233\236", nullptr));
        pushButton->setText(QApplication::translate("adminlogin", "\347\231\273\345\275\225", nullptr));
    } // retranslateUi

};

namespace Ui {
    class adminlogin: public Ui_adminlogin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINLOGIN_H
