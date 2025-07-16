/********************************************************************************
** Form generated from reading UI file 'adminlogin.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMINLOGIN_H
#define UI_ADMINLOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCommandLinkButton>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_adminlogin
{
public:
    QCommandLinkButton *commandLinkButton;
    QPushButton *pushButton;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit;

    void setupUi(QDialog *adminlogin)
    {
        if (adminlogin->objectName().isEmpty())
            adminlogin->setObjectName(QStringLiteral("adminlogin"));
        adminlogin->resize(424, 303);
        adminlogin->setStyleSheet(QLatin1String("#adminlogin{border-image: url(:/1111.png);}\n"
"#adminlogin *{image: url();}"));
        commandLinkButton = new QCommandLinkButton(adminlogin);
        commandLinkButton->setObjectName(QStringLiteral("commandLinkButton"));
        commandLinkButton->setGeometry(QRect(-30, 260, 71, 41));
        commandLinkButton->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        pushButton = new QPushButton(adminlogin);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(100, 220, 231, 31));
        pushButton->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        lineEdit_2 = new QLineEdit(adminlogin);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(120, 150, 191, 41));
        lineEdit = new QLineEdit(adminlogin);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(120, 110, 191, 41));

        retranslateUi(adminlogin);

        QMetaObject::connectSlotsByName(adminlogin);
    } // setupUi

    void retranslateUi(QDialog *adminlogin)
    {
        adminlogin->setWindowTitle(QApplication::translate("adminlogin", "Dialog", Q_NULLPTR));
        commandLinkButton->setText(QApplication::translate("adminlogin", "\350\277\224\345\233\236", Q_NULLPTR));
        pushButton->setText(QApplication::translate("adminlogin", "\347\231\273\345\275\225", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class adminlogin: public Ui_adminlogin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINLOGIN_H
