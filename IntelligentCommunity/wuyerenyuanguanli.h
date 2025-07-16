#ifndef WUYERENYUANGUANLI_H
#define WUYERENYUANGUANLI_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QTextEdit>
#include <QTableWidget>
#include <QSqlDatabase>
class Wuyerenyuanguanli : public QWidget
{
    Q_OBJECT

public:
    Wuyerenyuanguanli(QWidget *parent = nullptr);
    ~Wuyerenyuanguanli();

private slots:
    void onAddButtonClicked();
    void onDeleteButtonClicked();
    void onSearchButtonClicked();

private:
    QLabel *labelTitle;
    QLabel *labelName;
    QLabel *labelAge;
    QLabel *labelPhone;
    QLabel *labelAddress;
    QLineEdit *lineEditName;
    QLineEdit *lineEditAge;
    QLineEdit *lineEditPhone;
    QLineEdit *lineEditAddress;
    QPushButton *pushButtonAdd;
    QPushButton *pushButtonDelete;
    QPushButton *pushButtonSearch;
    QTableWidget *tableWidget;
    QSqlDatabase db;
};

#endif // WUYERENYUANGUANLI_H
