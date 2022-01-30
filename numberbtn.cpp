#include "numberbtn.h"

NumberBtn::NumberBtn(QWidget *parent) : QWidget(parent)
{
    initUI();
    setAttribute(Qt::WA_StyledBackground);
}

void NumberBtn::initUI()
{
    hlayout = new QVBoxLayout(this);

    vlayout1 = new QHBoxLayout();
    vlayout2 = new QHBoxLayout();
    vlayout3 = new QHBoxLayout();
    vlayout4 = new QHBoxLayout();

    Number7 = new QPushButton("7");
    Number8  = new QPushButton("8");
    Number9 = new QPushButton("9");
    vlayout1->addWidget(Number7);
    vlayout1->addWidget(Number8);
    vlayout1->addWidget(Number9);
    connect(Number7, &QPushButton::released, this, [=](){
        emit btnStr(QString("7"));
    });
    connect(Number8, &QPushButton::released, this, [=](){
        emit btnStr(QString("8"));
    });
    connect(Number9, &QPushButton::released, this, [=](){
        emit btnStr(QString("9"));
    });

    Number4  = new QPushButton("4");
    Number5 = new QPushButton("5");
    Number6   = new QPushButton("6");
    vlayout2->addWidget(Number4);
    vlayout2->addWidget(Number5);
    vlayout2->addWidget(Number6);
    connect(Number4, &QPushButton::released, this, [=](){
        emit btnStr(QString("4"));
    });
    connect(Number5, &QPushButton::released, this, [=](){
        emit btnStr(QString("5"));
    });
    connect(Number6, &QPushButton::released, this, [=](){
        emit btnStr(QString("6"));
    });


    Number1  = new QPushButton("1");
    Number2 = new QPushButton("2");
    Number3  = new QPushButton("3");
    vlayout3->addWidget(Number1);
    vlayout3->addWidget(Number2);
    vlayout3->addWidget(Number3);
    connect(Number1, &QPushButton::released, this, [=](){
        emit btnStr(QString("1"));
    });
    connect(Number2, &QPushButton::released, this, [=](){
        emit btnStr(QString("2"));
    });
    connect(Number3, &QPushButton::released, this, [=](){
        emit btnStr(QString("3"));
    });

    Number0 = new QPushButton("0");
    dot= new QPushButton(".");
    connect(Number0, &QPushButton::released, this, [=](){
        emit btnStr(QString("0"));
    });
    connect(dot, &QPushButton::released, this, [=](){
        emit btnStr(QString("."));
    });

    vlayout4->addWidget(Number0);
    vlayout4->addWidget(dot);

    hlayout->addLayout(vlayout1);
    hlayout->addLayout(vlayout2);
    hlayout->addLayout(vlayout3);
    hlayout->addLayout(vlayout4);

    QFile file("://Resource/btnwidget.css");
    if(file.open(QIODevice::ReadOnly|QIODevice::Text)){
        this->setStyleSheet(file.readAll());
    }
    this->setFixedSize(200,265);
    file.close();
}
