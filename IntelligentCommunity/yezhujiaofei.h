#ifndef YEZHUJIAOFEI_H
#define YEZHUJIAOFEI_H

#include <QWidget>
#include <QLineEdit>
#include <QComboBox>
#include <QPushButton>
#include <QLabel>

class YeZhuJiaoFei : public QWidget {
    Q_OBJECT
public:
    explicit YeZhuJiaoFei(QWidget *parent = nullptr);

private slots:
    void onPayClicked();

private:
    QLineEdit *nameEdit;
    QComboBox *feeTypeCombo;
    QComboBox *methodCombo;
    QLineEdit *monthsEdit;
    QPushButton *payButton;
    QLabel *totalLabel;
};

#endif // YEZHUJIAOFEI_H
