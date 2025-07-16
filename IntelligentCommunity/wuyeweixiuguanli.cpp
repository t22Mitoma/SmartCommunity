#include "wuyeweixiuguanli.h"
#include "ui_wuyeweixiuguanli.h"
#include <QSqlQuery>
#include <QPixmap>

Wuyeweixiuguanli::Wuyeweixiuguanli(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Wuyeweixiuguanli)
{
    ui->setupUi(this);


    QSqlDatabase db = QSqlDatabase::database(); // 直接获取默认连接      // 打开数据库

       if(!db.open()){
           QMessageBox::information(NULL,"提示","数据库连接失败",QMessageBox::Ok);
           return; // 连接失败直接返回，避免后续错误
       }
   //   QString imagePath = "C:\Users\mingxyou\Desktop\V1.1-beta1\V1.1\ResourceFile\resourcefile.qrc";

   //   this->setStyleSheet(QString("Wuyeweixiuguanli {"
   //          "background-image: url(%1);"  // 加载图片
    //         "background-repeat: no-repeat;"  // 不重复平铺
    //         "background-position: center center;"  // 图片居中
     //        "background-size: cover;"  // 图片自适应窗口大小（覆盖整个界面）
    //     "}").arg(imagePath));
         // --------------------------------------------------------------



    model = new QSqlTableModel(this,db);
             model->setTable("yezhupingjia");
             model->select();
             model->setEditStrategy(QSqlTableModel::OnManualSubmit);

             ui->tableView->setModel(model);


}

Wuyeweixiuguanli::~Wuyeweixiuguanli()
{
    delete ui;
}


// 新增：刷新表格（故障报修提交后调用，重新查询数据库）
void Wuyeweixiuguanli::refreshTableModel() {
    model->select(); // 重新查询，显示最新数据
}



void Wuyeweixiuguanli::on_pushButton_clicked()
{

    refreshTableModel(); // 直接重新查询
    if (model->rowCount() == 0) {
            QMessageBox::information(this, "错误", "查询失败：" + model->lastError().text());
            return;
        }
        QMessageBox::information(this, "提示", "已加载全部报修记录！");

}

void Wuyeweixiuguanli::on_pushButton_3_clicked()
{
    // 获取选中的行
    int curRow = ui->tableView->currentIndex().row();

    // 删除该行
    model->removeRow(curRow);
    int ok = QMessageBox::warning(this,tr("删除当前行!"),
                                  tr("你确定删除当前行吗？"), QMessageBox::Yes, QMessageBox::No);
    if(ok == QMessageBox::No)
    { // 如果不删除，则撤销
        model->revertAll();
        return;
    } else {
        model->removeRow(curRow);
          model->submitAll(); // 提交修改到数据库
          QMessageBox::information(this, "提示", "删除成功");
    }
}

void Wuyeweixiuguanli::on_pushButton_4_clicked()
{
    QString searchname = ui->lineEdit->text();
        if(searchname==NULL)
        {
             QMessageBox::information(NULL,"提示","请输入查询姓名",QMessageBox::Ok);
        }

        QSqlQuery query(QSqlDatabase::database());
        query.prepare("SELECT * FROM yezhupingjia WHERE owner_name = :ownerName");
        query.bindValue(":ownerName", searchname);
        if(!query.exec())
        {
            qDebug()<<"there is not a table of yezhupingjia in mysql"<<query.lastError();
            return;
        }
        QString tel,add,pro,bao,jin,pin;
        if(query.next())
        {
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
        } else {
            QMessageBox::information(this, "提示", "未找到该姓名的记录");
            // 清空界面
            ui->lineEdit_2->clear();
            ui->lineEdit_3->clear();
            ui->textEdit->clear();
            ui->lineEdit_4->clear();
            ui->lineEdit_5->clear();
            ui->lineEdit_6->clear();
            ui->lineEdit->clear();
        }
}
void Wuyeweixiuguanli::on_pushButton_2_clicked()
{

//    int curRow = ui->tableView->currentIndex().row();
//       if (curRow < 0) {
//           QMessageBox::warning(this, "提示", "请选择要修改的记录");
//           return;}
    QString searchname = ui->lineEdit->text().trimmed();
        if(searchname.isEmpty()) {
            QMessageBox::information(this, "提示", "请输入需要修改的姓名", QMessageBox::Ok);
            return;
        }

    QString jindu = ui->lineEdit_5->text();
    QString pingjia = ui->lineEdit_6->text();
    QString qingkuang = ui->lineEdit_4->text();



    QSqlQuery query(QSqlDatabase::database());
        query.prepare(R"(
                      UPDATE yezhupingjia
                      SET repair_status = :jindu,
                          evaluation = :pingjia,
                          warranty_status = :qingkuang
                      WHERE owner_name = :searchname
                  )");

        query.bindValue(":jindu", jindu);
         query.bindValue(":searchname", searchname);
        query.bindValue(":pingjia", pingjia);
        query.bindValue(":qingkuang", qingkuang);
        if (query.exec()) {
            int affectedRows = query.numRowsAffected();
                    if (affectedRows > 0) {
                        QMessageBox::information(this, "成功", "修改成功！共更新 " + QString::number(affectedRows) + " 条记录");
            // 清空输入框

                        ui->lineEdit_2->clear();
                                   ui->lineEdit_3->clear();
                                   ui->textEdit->clear();
                                   ui->lineEdit_4->clear();
                                   ui->lineEdit_5->clear();
                                   ui->lineEdit_6->clear();
                                   ui->lineEdit->clear();
        }else {
            // 修改失败提示
            QMessageBox::critical(this, "失败", "修改失败：" + query.lastError().text());
            qDebug() << "SQL 执行失败：" << query.lastQuery();
        }
}
}
