#include "wuyeshangxiabandengji.h"
#include "ui_wuyeshangxiabandengji.h"
#include <qdebug.h>
#include <QSqlQuery>
#include <QtSql/QSqlError>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQueryModel>
#include <QMessageBox>

Wuyeshangxiabandengji::Wuyeshangxiabandengji(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Wuyeshangxiabandengji)
{
    ui->setupUi(this);
    //建立并打开数据库
    QSqlDatabase db = QSqlDatabase::database(); // 获取默认连接
    if (!db.isOpen()) {
        QMessageBox::critical(this, "错误", "数据库未打开：" + db.lastError().text());
        return;
    }
}

Wuyeshangxiabandengji::~Wuyeshangxiabandengji()
{
    delete ui;
}

void Wuyeshangxiabandengji::on_pushButton_clicked()
{
    QString name = ui->lineEdit->text();
    QString shangban = ui->lineEdit_2->text();
    QString xiaban = ui->lineEdit_3->text();
    QString date = ui->lineEdit_4->text();
    QString str = QString("insert into book (name,shangban,xiaban,date) values('%1','%2','%3','%4') ").arg(name).arg(shangban).arg(xiaban).arg(date);
    QSqlQuery query;

        if(!query.exec(str))
        {
             qDebug()<<"there is not a table of book in mysql!"<<query.lastError();
        }
        else
        {
            QMessageBox::information(NULL,"Success"," 数据写入成功！！");
}
}

void Wuyeshangxiabandengji::on_pushButton_2_clicked()
{
    QString updatename = ui->lineEdit->text();
    //QString updateshangban = ui->lineEdit_2->text();
    QString updatexiaban = ui->lineEdit_3->text();
      if(updatename == NULL )
          {
               QMessageBox::information(NULL,"fail"," 请输入需要修改的人的名字、上班时间、下班时间");
          }
      else
      {
      QString temp = QString("select * from book where name = '%1'").arg(updatename);

      QSqlQuery query;
      query.exec(temp);// 查询信息
      QString c;
      while (query.next())
      {
          c = query.value(1).toString();
      }
      if(c == NULL)
      {
          QString b = QString("没有名叫%1的人，修改失败").arg(updatename);
          QMessageBox::information(NULL,"fail",b);
          ui->lineEdit->clear();
          //ui->lineEdit_2->clear();
          ui->lineEdit_3->clear();
      }
      else
      {

         QString temp = QString("update book set xiaban = '%1' where name = '%2'").arg(updatexiaban).arg(updatename);
         QSqlQuery query;
         query.exec(temp);
         QMessageBox::information(NULL,"Success"," 信息修改成功!!");
            ui->lineEdit->clear();
            //ui->lineEdit_2->clear();
            ui->lineEdit_3->clear();
        }
}
}
