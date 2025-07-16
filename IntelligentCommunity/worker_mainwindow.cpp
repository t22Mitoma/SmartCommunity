#include "worker_mainwindow.h"
#include "ui_worker_mainwindow.h"
#include "wuyerenyuanguanli.h"
#include "ui_wuyerenyuanguanli.h"
#include "wuyeweixiuguanli.h"
#include "ui_wuyeweixiuguanli.h"
#include "wuyeqingxiaojia.h"
#include "ui_wuyeqingxiaojia.h"
#include "wuyeyueduchuqin.h"
#include "ui_wuyeyueduchuqin.h"
#include "wuyeshangxiabandengji.h"
#include "ui_wuyeshangxiabandengji.h"
#include "wuyecheweixinxiguanli.h"
#include "ui_wuyecheweixinxiguanli.h"
#include "wuyecheweichuzu.h"
#include "ui_wuyecheweichuzu.h"
#include "wuyejiaofei.h"
#include "ui_wuyejiaofei.h"
#include "paymenthistorywidget.h"
#include "ui_paymenthistorywidget.h"
worker_MainWindow::worker_MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::worker_MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("物业管理面板");
    this->setWindowIcon(QIcon(":/logo.png"));
    Wuyerenyuanguanli *wuyerenyuanguan = new Wuyerenyuanguanli;
    this->setCentralWidget(wuyerenyuanguan);
}

worker_MainWindow::~worker_MainWindow()
{
    delete ui;
}

void worker_MainWindow::on_action_triggered()//人事管理
{

    Wuyerenyuanguanli *wuyerenyuanguan = new Wuyerenyuanguanli;
    this->setCentralWidget(wuyerenyuanguan);

}

void worker_MainWindow::on_actionrenshi_triggered()//请销假
{
    Wuyeqingxiaojia *jia = new Wuyeqingxiaojia;
    setCentralWidget(jia);
}

void worker_MainWindow::on_action_2_triggered()//维修管理
{
    Wuyeweixiuguanli *wuyeweixiuguanli = new Wuyeweixiuguanli;
    setCentralWidget(wuyeweixiuguanli);
}

void worker_MainWindow::on_action_3_triggered()//月度出勤
{
    Wuyeyueduchuqin *qin = new Wuyeyueduchuqin;
    setCentralWidget(qin);
}

void worker_MainWindow::on_action_4_triggered()//上下班登记
{
    Wuyeshangxiabandengji *ji = new Wuyeshangxiabandengji;
    setCentralWidget(ji);
}

void worker_MainWindow::on_action_5_triggered()//车位信息管理
{
    Wuyecheweixinxiguanli *li = new Wuyecheweixinxiguanli;
    setCentralWidget(li);
}

void worker_MainWindow::on_action_6_triggered()//车位出租
{
    Wuyecheweichuzu *zu = new Wuyecheweichuzu;
    setCentralWidget(zu);

}

void worker_MainWindow::on_action_7_triggered()//物业缴费
{
    WuYeJiaoFei *feeWidget = new WuYeJiaoFei(this);  // 创建物业缴费widget
    setCentralWidget(feeWidget);                      // 设置为中心部件
}

void worker_MainWindow::on_action_8_triggered()
{
    PaymentHistoryWidget *historyWidget = new PaymentHistoryWidget(this);
    setCentralWidget(historyWidget);
}
