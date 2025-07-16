/********************************************************************************
** Form generated from reading UI file 'wuyecheweichuzu.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WUYECHEWEICHUZU_H
#define UI_WUYECHEWEICHUZU_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Wuyecheweichuzu
{
public:
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *numlineEdit;
    QLabel *label_2;
    QLineEdit *namelineEdit;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QLineEdit *IDlineEdit;
    QWidget *horizontalLayoutWidget_3;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer;
    QPushButton *selectpushButton;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *yespushButton;
    QSpacerItem *horizontalSpacer_3;
    QTableView *tableView;

    void setupUi(QWidget *Wuyecheweichuzu)
    {
        if (Wuyecheweichuzu->objectName().isEmpty())
            Wuyecheweichuzu->setObjectName(QStringLiteral("Wuyecheweichuzu"));
        Wuyecheweichuzu->resize(641, 529);
        horizontalLayoutWidget = new QWidget(Wuyecheweichuzu);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(110, 30, 431, 31));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(horizontalLayoutWidget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        numlineEdit = new QLineEdit(horizontalLayoutWidget);
        numlineEdit->setObjectName(QStringLiteral("numlineEdit"));

        horizontalLayout->addWidget(numlineEdit);

        label_2 = new QLabel(horizontalLayoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout->addWidget(label_2);

        namelineEdit = new QLineEdit(horizontalLayoutWidget);
        namelineEdit->setObjectName(QStringLiteral("namelineEdit"));

        horizontalLayout->addWidget(namelineEdit);

        horizontalLayoutWidget_2 = new QWidget(Wuyecheweichuzu);
        horizontalLayoutWidget_2->setObjectName(QStringLiteral("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(110, 60, 431, 31));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(horizontalLayoutWidget_2);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_2->addWidget(label_3);

        IDlineEdit = new QLineEdit(horizontalLayoutWidget_2);
        IDlineEdit->setObjectName(QStringLiteral("IDlineEdit"));

        horizontalLayout_2->addWidget(IDlineEdit);

        horizontalLayoutWidget_3 = new QWidget(Wuyecheweichuzu);
        horizontalLayoutWidget_3->setObjectName(QStringLiteral("horizontalLayoutWidget_3"));
        horizontalLayoutWidget_3->setGeometry(QRect(110, 90, 431, 31));
        horizontalLayout_3 = new QHBoxLayout(horizontalLayoutWidget_3);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        selectpushButton = new QPushButton(horizontalLayoutWidget_3);
        selectpushButton->setObjectName(QStringLiteral("selectpushButton"));

        horizontalLayout_3->addWidget(selectpushButton);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        yespushButton = new QPushButton(horizontalLayoutWidget_3);
        yespushButton->setObjectName(QStringLiteral("yespushButton"));

        horizontalLayout_3->addWidget(yespushButton);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        tableView = new QTableView(Wuyecheweichuzu);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setGeometry(QRect(20, 140, 601, 361));

        retranslateUi(Wuyecheweichuzu);

        QMetaObject::connectSlotsByName(Wuyecheweichuzu);
    } // setupUi

    void retranslateUi(QWidget *Wuyecheweichuzu)
    {
        Wuyecheweichuzu->setWindowTitle(QApplication::translate("Wuyecheweichuzu", "Form", Q_NULLPTR));
        label->setText(QApplication::translate("Wuyecheweichuzu", "\350\275\246\344\275\215\347\274\226\345\217\267", Q_NULLPTR));
        label_2->setText(QApplication::translate("Wuyecheweichuzu", "\347\247\237\350\265\201\344\272\272\345\247\223\345\220\215", Q_NULLPTR));
        label_3->setText(QApplication::translate("Wuyecheweichuzu", "\347\247\237\350\265\201\344\272\272\350\272\253\344\273\275\350\257\201\345\217\267", Q_NULLPTR));
        selectpushButton->setText(QApplication::translate("Wuyecheweichuzu", "\346\234\252\347\247\237\350\265\201\350\275\246\344\275\215", Q_NULLPTR));
        yespushButton->setText(QApplication::translate("Wuyecheweichuzu", "\347\241\256\350\256\244\347\247\237\350\265\201", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Wuyecheweichuzu: public Ui_Wuyecheweichuzu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WUYECHEWEICHUZU_H
