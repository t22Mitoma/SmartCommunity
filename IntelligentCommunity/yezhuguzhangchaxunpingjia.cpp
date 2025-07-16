#include "yezhuguzhangchaxunpingjia.h"
#include "ui_yezhuguzhangchaxunpingjia.h"

Yezhuguzhangchaxunpingjia::Yezhuguzhangchaxunpingjia(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Yezhuguzhangchaxunpingjia)
{
    ui->setupUi(this);
    /**连接数据库**/
    QSqlDatabase db = QSqlDatabase::database();
    if (!db.isOpen()) {
        QMessageBox::critical(this, "错误", "数据库未连接！");
        return;
    }else{
            QMessageBox::information(NULL,"提示","数据库连接成功",QMessageBox::Ok);
        }
}
Yezhuguzhangchaxunpingjia::~Yezhuguzhangchaxunpingjia()
{
    delete ui;
}

void Yezhuguzhangchaxunpingjia::on_pushButton_4_clicked()
{
    QString searchname = ui->lineEdit->text().trimmed();
    if(searchname==NULL)
    {
         QMessageBox::information(NULL,"提示","请输入查询姓名",QMessageBox::Ok);
    }

    QSqlQuery query;
       query.prepare("SELECT * FROM yezhupingjia WHERE owner_name = :ownerName");
       query.bindValue(":ownerName", searchname);
        if(!query.exec())
        {
            qDebug()<<"there is not a table of yezhupingjia in mysql"<<query.lastError();
        }
        QString tel,add,pro,bao,jin,pin;

        bool found = false;
        while(query.next())
        {
             found = true;
            tel=query.value(2).toString();
            add=query.value(3).toString();
            pro=query.value(4).toString();
            bao=query.value(5).toString();
            jin=query.value(6).toString();
            pin=query.value(7).toString();

            ui->lineEdit_2->setText(tel);
            ui->lineEdit_3->setText(add);
            ui->textEdit->setText(pro);
            ui->lineEdit_4->setText(bao);
            ui->lineEdit_5->setText(jin);
            ui->lineEdit_6->setText(pin);

            ui->lineEdit_4->setFocusPolicy(Qt::NoFocus);
            ui->lineEdit_5->setFocusPolicy(Qt::NoFocus);
         }
            if (!found)
               {
                   QMessageBox::information(NULL, "提示", "找不到该姓名对应的记录", QMessageBox::Ok);
                   // 可以选择清空之前可能填充的内容
                   ui->lineEdit_2->clear();
                   ui->lineEdit_3->clear();
                   ui->textEdit->clear();
                   ui->lineEdit_4->clear();
                   ui->lineEdit_5->clear();
                   ui->lineEdit_6->clear();
                   ui->lineEdit->clear();
               }


}
void Yezhuguzhangchaxunpingjia::on_pushButton_2_clicked()
{
    QString evaluation = ui->lineEdit_6->text().trimmed();
    QString searchname = ui->lineEdit->text().trimmed();
     QString jindu = ui->lineEdit_5->text().trimmed(); // 新维修进度

           if (evaluation.isEmpty()) {
               QMessageBox::warning(this, "提示", "请输入评价内容！");
               return;
           }
    QSqlQuery query;
    query.prepare("UPDATE yezhupingjia SET evaluation = :evaluation WHERE owner_name = :ownerName");
       query.bindValue(":evaluation", evaluation);
       query.bindValue(":ownerName", searchname);
       query.bindValue(":jindu", jindu);

       qDebug() << "SQL Statement:" << query.lastQuery();
           qDebug() << "Bound Values:" << query.boundValues();
           qDebug() << "Parameter Count:" << query.boundValues().size();

    if (query.exec()) {
            // 4. 判断是否真的更新了数据
            if (query.numRowsAffected() > 0) {
                QMessageBox::information( this,  "Success",  "评价修改成功!");
                            ui->lineEdit_6->clear();
                             ui->lineEdit_5->clear();
                              ui->lineEdit_4->clear();
                               ui->lineEdit_3->clear();
                                ui->lineEdit_2->clear();
                                 ui->textEdit->clear();
                            ui ->lineEdit->clear();
            } else {
                QMessageBox::warning(
                    this,
                    "提示",
                    "未找到该业主记录，修改失败！",
                    QMessageBox::Ok
                );
            }
        } else {
            // 5. 执行失败时提示错误
            QMessageBox::critical(
                this,
                "错误",
                "SQL 执行失败：" + query.lastError().text(),
                QMessageBox::Ok
            );
}
}
