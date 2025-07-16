#ifndef WUYEJIAOFEI_H
#define WUYEJIAOFEI_H

#include <QWidget>
#include <QLineEdit>
#include <QComboBox>
#include <QPushButton>
#include <QLabel>

class WuYeJiaoFei : public QWidget {
    Q_OBJECT
public:
    explicit WuYeJiaoFei(QWidget *parent = nullptr);

private slots:
    void onSetPriceClicked();

private:
    QComboBox *feeTypeCombo;
    QLineEdit *priceEdit;
    QPushButton *setPriceButton;
};

#endif // WUYEJIAOFEI_H
