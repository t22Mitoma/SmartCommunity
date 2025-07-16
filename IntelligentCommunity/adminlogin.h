#ifndef ADMINLOGIN_H
#define ADMINLOGIN_H

#include <QDialog>

namespace Ui {
class adminlogin;
}

class adminlogin : public QDialog
{
    Q_OBJECT

public:
    explicit adminlogin(QWidget *parent = 0);
    ~adminlogin();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_commandLinkButton_clicked();

    void on_lineEdit_2_cursorPositionChanged(int arg1, int arg2);

private:
    Ui::adminlogin *ui;
};

#endif // ADMINLOGIN_H
