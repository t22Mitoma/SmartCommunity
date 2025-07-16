#ifndef GUANLIYUANQINGJIASHENGPI_H
#define GUANLIYUANQINGJIASHENGPI_H

#include <QWidget>
#include <QTableView>
#include <QSqlTableModel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>

class guanliyuanqingjiashenpi : public QWidget
{
    Q_OBJECT

public:
    guanliyuanqingjiashenpi(QWidget *parent = nullptr);
    ~guanliyuanqingjiashenpi();

private slots:
    void approveSelectedLeave();
    void rejectSelectedLeave();
    void refreshTable();

private:
    QTableView *leaveTableView;
    QSqlTableModel *model;
    QPushButton *approveButton;
    QPushButton *rejectButton;
    QPushButton *refreshButton;
};

#endif // GUANLIYUANQINGJIASHENGPI_H
