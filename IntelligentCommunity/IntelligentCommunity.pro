#-------------------------------------------------
#
# Project created by QtCreator 2020-06-04T09:36:23
#
#-------------------------------------------------

QT       += core gui
QT       += sql
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = IntelligentCommunity
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
        mainwindow.cpp \
    adminlogin.cpp \
    admin_mainwindow.cpp \
    worker_mainwindow.cpp \
    owner_mainwindow.cpp \
    guanliyuanrenshiguanli.cpp \
    wuyerenyuanguanli.cpp \
    wuyeweixiuguanli.cpp \
    yezhuguzhuangbaoxiu.cpp \
    yezhuguzhangchaxunpingjia.cpp \
    wuyeqingxiaojia.cpp \
    wuyeyueduchuqin.cpp \
    wuyeshangxiabandengji.cpp \
    wuyecheweixinxiguanli.cpp \
    wuyecheweichuzu.cpp \
    guanliyuanqingjiashenpi.cpp \
    yezhucheweiguanli.cpp \
    yezhujiaofei.cpp \
    wuyejiaofei.cpp \
    paymenthistorywidget.cpp

HEADERS  += mainwindow.h \
    adminlogin.h \
    admin_mainwindow.h \
    worker_mainwindow.h \
    owner_mainwindow.h \
    guanliyuanrenshiguanli.h \
    wuyerenyuanguanli.h \
    wuyeweixiuguanli.h \
    yezhuguzhuangbaoxiu.h \
    yezhuguzhangchaxunpingjia.h \
    wuyeqingxiaojia.h \
    wuyeyueduchuqin.h \
    wuyeshangxiabandengji.h \
    wuyecheweixinxiguanli.h \
    wuyecheweichuzu.h \
    guanliyuanqingjiashenpi.h \
    yezhucheweiguanli.h \
    yezhujiaofei.h \
    wuyejiaofei.h \
    paymenthistorywidget.h

FORMS    += mainwindow.ui \
    adminlogin.ui \
    admin_mainwindow.ui \
    worker_mainwindow.ui \
    owner_mainwindow.ui \
    guanliyuanrenshiguanli.ui \
    wuyerenyuanguanli.ui \
    wuyeweixiuguanli.ui \
    yezhuguzhuangbaoxiu.ui \
    yezhuguzhangchaxunpingjia.ui \
    wuyeqingxiaojia.ui \
    wuyeyueduchuqin.ui \
    wuyeshangxiabandengji.ui \
    wuyecheweixinxiguanli.ui \
    wuyecheweichuzu.ui \
    guanliyuanqingjiashenpi.ui \
    yezhucheweiguanli.ui \
    yezhujiaofei.ui \
    wuyejiaofei.ui \
    paymenthistorywidget.ui

RESOURCES += \
    ../ResourceFile/resourcefile.qrc \
    ../ResourceFile/resourcefile.qrc \

DISTFILES += \
    ../ResourceFile/智慧背景.png \
    ../ResourceFile/111.png \
    ../ResourceFile/1111.png \
    ../ResourceFile/adminlogin.png \
    ../ResourceFile/background1.png \
    ../ResourceFile/background2.png \
    ../ResourceFile/Snipaste_2020-06-04_17-55-02.png
