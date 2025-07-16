/********************************************************************************
** Form generated from reading UI file 'wuyecheweixinxiguanli.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WUYECHEWEIXINXIGUANLI_H
#define UI_WUYECHEWEIXINXIGUANLI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Wuyecheweixinxiguanli
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label;
    QLineEdit *numEdit;
    QSpacerItem *horizontalSpacer_4;
    QLabel *label_3;
    QRadioButton *yradioButton;
    QRadioButton *nradioButton;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_2;
    QLineEdit *addrEdit;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_4;
    QLineEdit *useridEdit;
    QTableView *tableView;
    QHBoxLayout *horizontalLayout;
    QPushButton *addButton;
    QPushButton *modifyButton;
    QPushButton *queryButton;

    void setupUi(QWidget *Wuyecheweixinxiguanli)
    {
        if (Wuyecheweixinxiguanli->objectName().isEmpty())
            Wuyecheweixinxiguanli->setObjectName(QStringLiteral("Wuyecheweixinxiguanli"));
        Wuyecheweixinxiguanli->resize(594, 454);
        verticalLayoutWidget = new QWidget(Wuyecheweixinxiguanli);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(60, 10, 461, 431));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label = new QLabel(verticalLayoutWidget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_3->addWidget(label);

        numEdit = new QLineEdit(verticalLayoutWidget);
        numEdit->setObjectName(QStringLiteral("numEdit"));

        horizontalLayout_3->addWidget(numEdit);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_4);

        label_3 = new QLabel(verticalLayoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_3->addWidget(label_3);

        yradioButton = new QRadioButton(verticalLayoutWidget);
        yradioButton->setObjectName(QStringLiteral("yradioButton"));

        horizontalLayout_3->addWidget(yradioButton);

        nradioButton = new QRadioButton(verticalLayoutWidget);
        nradioButton->setObjectName(QStringLiteral("nradioButton"));

        horizontalLayout_3->addWidget(nradioButton);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_2 = new QLabel(verticalLayoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_4->addWidget(label_2);

        addrEdit = new QLineEdit(verticalLayoutWidget);
        addrEdit->setObjectName(QStringLiteral("addrEdit"));

        horizontalLayout_4->addWidget(addrEdit);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_2);

        label_4 = new QLabel(verticalLayoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_4->addWidget(label_4);

        useridEdit = new QLineEdit(verticalLayoutWidget);
        useridEdit->setObjectName(QStringLiteral("useridEdit"));

        horizontalLayout_4->addWidget(useridEdit);


        verticalLayout->addLayout(horizontalLayout_4);

        tableView = new QTableView(verticalLayoutWidget);
        tableView->setObjectName(QStringLiteral("tableView"));

        verticalLayout->addWidget(tableView);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        addButton = new QPushButton(verticalLayoutWidget);
        addButton->setObjectName(QStringLiteral("addButton"));

        horizontalLayout->addWidget(addButton);

        modifyButton = new QPushButton(verticalLayoutWidget);
        modifyButton->setObjectName(QStringLiteral("modifyButton"));

        horizontalLayout->addWidget(modifyButton);

        queryButton = new QPushButton(verticalLayoutWidget);
        queryButton->setObjectName(QStringLiteral("queryButton"));

        horizontalLayout->addWidget(queryButton);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(Wuyecheweixinxiguanli);

        QMetaObject::connectSlotsByName(Wuyecheweixinxiguanli);
    } // setupUi

    void retranslateUi(QWidget *Wuyecheweixinxiguanli)
    {
        Wuyecheweixinxiguanli->setWindowTitle(QApplication::translate("Wuyecheweixinxiguanli", "Form", Q_NULLPTR));
        label->setText(QApplication::translate("Wuyecheweixinxiguanli", "\350\275\246\344\275\215\347\274\226\345\217\267", Q_NULLPTR));
        label_3->setText(QApplication::translate("Wuyecheweixinxiguanli", "\346\230\257\345\220\246\345\224\256\345\207\272", Q_NULLPTR));
        yradioButton->setText(QApplication::translate("Wuyecheweixinxiguanli", "\346\230\257", Q_NULLPTR));
        nradioButton->setText(QApplication::translate("Wuyecheweixinxiguanli", "\345\220\246", Q_NULLPTR));
        label_2->setText(QApplication::translate("Wuyecheweixinxiguanli", "\350\275\246\344\275\215\345\234\260\345\235\200", Q_NULLPTR));
        label_4->setText(QApplication::translate("Wuyecheweixinxiguanli", "\350\264\255\344\271\260\344\272\272\350\264\246\345\217\267", Q_NULLPTR));
        addButton->setText(QApplication::translate("Wuyecheweixinxiguanli", "\346\267\273\345\212\240\350\275\246\344\275\215", Q_NULLPTR));
        modifyButton->setText(QApplication::translate("Wuyecheweixinxiguanli", "\344\277\256\346\224\271\350\275\246\344\275\215", Q_NULLPTR));
        queryButton->setText(QApplication::translate("Wuyecheweixinxiguanli", "\346\237\245\350\257\242\350\275\246\344\275\215", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Wuyecheweixinxiguanli: public Ui_Wuyecheweixinxiguanli {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WUYECHEWEIXINXIGUANLI_H
