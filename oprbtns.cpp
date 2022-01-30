#include "oprbtns.h"

Oprbtns::Oprbtns(QWidget *parent) : QWidget(parent)
{
    initUI();
    setAttribute(Qt::WA_StyledBackground);
}

void Oprbtns::initUI()
{
    hlayout = new QVBoxLayout(this);

    vlayout1 = new QHBoxLayout();
    vlayout2 = new QHBoxLayout();
    vlayout3 = new QHBoxLayout();
    vlayout4 = new QHBoxLayout();

    left = new QPushButton("(");
    right  = new QPushButton(")");
    vlayout1->addWidget(left);
    vlayout1->addWidget(right);
    connect(left, &QPushButton::released, this, [=](){
        emit btnStr(QString("("));
    });
    connect(right, &QPushButton::released, this, [=](){
        emit btnStr(QString(")"));
    });

    chu  = new QPushButton("/");
    jia = new QPushButton("+");
    vlayout2->addWidget(chu);
    vlayout2->addWidget(jia);
    connect(chu, &QPushButton::released, this, [=](){
        emit btnStr(QString("/"));
    });
    connect(jia, &QPushButton::released, this, [=](){
        emit btnStr(QString("+"));
    });

    cheng  = new QPushButton("*");
    jian = new QPushButton("-");
    vlayout3->addWidget(cheng);
    vlayout3->addWidget(jian);
    connect(cheng, &QPushButton::released, this, [=](){
        emit btnStr(QString("*"));
    });
    connect(jian, &QPushButton::released, this, [=](){
        emit btnStr(QString("-"));
    });

    youxie = new QPushButton("\\");
    mod= new QPushButton("%");

    vlayout4->addWidget(youxie);
    vlayout4->addWidget(mod);
    connect(youxie, &QPushButton::released, this, [=](){
        emit btnStr(QString("\\"));
    });
    connect(mod, &QPushButton::released, this, [=](){
        emit btnStr(QString("%"));
    });

    Equl = new QPushButton("=");
    connect(Equl, &QPushButton::released, this, [=](){
        emit btnStr(QString("="));
    });

    hlayout->addLayout(vlayout1);
    hlayout->addLayout(vlayout2);
    hlayout->addLayout(vlayout3);
    hlayout->addLayout(vlayout4);
    hlayout->addWidget(Equl);

    QFile file("://Resource/btnwidget.css");
    if(file.open(QIODevice::ReadOnly|QIODevice::Text)){
        this->setStyleSheet(file.readAll());
    }
    this->setFixedSize(120,265);
    file.close();
}
