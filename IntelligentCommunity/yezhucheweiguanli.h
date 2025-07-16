#ifndef YEZHUCHEWEIGUANLI_H
#define YEZHUCHEWEIGUANLI_H

#include <QWidget>
#include <QSqlDatabase>    // 数据库核心类
#include <QSqlQuery>       // SQL 执行类
#include <QSqlError>       // 数据库错误类
#include <QVBoxLayout>     // 垂直布局
#include <QHBoxLayout>     // 水平布局
#include <QPushButton>     // 按钮
#include <QLineEdit>       // 单行输入框
#include <QTableWidget>    // 表格控件
#include <QLabel>          // 文本标签
#include <QMessageBox>     // 消息框
#include <QHeaderView>
class YeZhuCheWeiGuanLi : public QWidget
{
    Q_OBJECT

public:
    explicit YeZhuCheWeiGuanLi(QWidget *parent = nullptr);
    ~YeZhuCheWeiGuanLi();

private:
    // 数据库相关
    QSqlDatabase db;

    // UI 控件
    QLabel *labelCheWeiID;      // 车位 ID 标签
    QLineEdit *editCheWeiID;    // 车位 ID 输入框
    QLabel *labelCheLiangInfo;  // 车辆信息标签
    QLineEdit *editCheLiangInfo;// 车辆信息输入框

    QPushButton *btnShenQing;   // 申请车位按钮
    QPushButton *btnChaXun;     // 查询车位按钮
    QPushButton *btnChengZu;    // 车位承租按钮
    QPushButton *btnWoDeCheWei; // 我的车位按钮
    QPushButton *btnRuKu;       // 车辆入库识别按钮

    QTableWidget *tableWidget;  // 结果展示表格

    // 初始化数据库
    void initDatabase();
    // 初始化 UI 控件
    void initUI();
    // 绑定按钮事件
    void bindEvents();

private slots:
    // 按钮点击事件槽函数
    void onBtnShenQingClicked();   // 申请车位
    void onBtnChaXunClicked();     // 查询车位
    void onBtnChengZuClicked();    // 车位承租
    void onBtnWoDeCheWeiClicked(); // 我的车位
    void onBtnRuKuClicked();       // 车辆入库识别
};

#endif // YEZHUCHEWEIGUANLI_H
