#include "moreopr.h"
#include <QGraphicsDropShadowEffect>

MoreOpr::MoreOpr(QWidget *parent) : QWidget(parent)
{
    initUI();
    setAttribute(Qt::WA_StyledBackground);
//    QGraphicsDropShadowEffect *shadow  = new QGraphicsDropShadowEffect();
//    shadow->setColor(Qt::black);
//    shadow->setOffset(0, 0);
//    this->setGraphicsEffect(shadow);
}

void MoreOpr::initUI()
{
    hlayout = new QVBoxLayout(this);

    vlayout1 = new QHBoxLayout();
    vlayout2 = new QHBoxLayout();
    vlayout3 = new QHBoxLayout();
    vlayout4 = new QHBoxLayout();
    vlayout5 = new QHBoxLayout();

    Pi = new QPushButton("PI");
    E  = new QPushButton("E");
    AC = new QPushButton("AC");
    Del= new QPushButton("Del");
    vlayout1->addWidget(Pi);
    vlayout1->addWidget(E);
    vlayout1->addWidget(AC);
    vlayout1->addWidget(Del);
    connect(Pi, &QPushButton::released, this, [=](){
        emit btnStr(QString("PI()"));
    });
    connect(E, &QPushButton::released, this, [=](){
        emit btnStr(QString("E"));
    });
    connect(AC, &QPushButton::released, this, [=](){
        emit btnStr(QString("AC"));
    });
    connect(Del, &QPushButton::released, this, [=](){
        emit btnStr(QString("Del"));
    });

    Sin  = new QPushButton("Sin");
    Asin = new QPushButton("asin");
    Ln   = new QPushButton("ln");
    Sign = new QPushButton("sign");
    vlayout2->addWidget(Sin);
    vlayout2->addWidget(Asin);
    vlayout2->addWidget(Ln);
    vlayout2->addWidget(Sign);
    connect(Sin, &QPushButton::released, this, [=](){
        emit btnStr(QString("Sin("));
    });
    connect(Asin, &QPushButton::released, this, [=](){
        emit btnStr(QString("asin("));
    });
    connect(Ln, &QPushButton::released, this, [=](){
        emit btnStr(QString("ln("));
    });
    connect(Sign, &QPushButton::released, this, [=](){
        emit btnStr(QString("sign("));
    });

    Cos  = new QPushButton("cos");
    Acos = new QPushButton("acos");
    log  = new QPushButton("log");
    Floor= new QPushButton("floor");
    vlayout3->addWidget(Cos);
    vlayout3->addWidget(Acos);
    vlayout3->addWidget(log);
    vlayout3->addWidget(Floor);
    connect(Cos, &QPushButton::released, this, [=](){
        emit btnStr(QString("cos("));
    });
    connect(Acos, &QPushButton::released, this, [=](){
        emit btnStr(QString("acos("));
    });
    connect(log, &QPushButton::released, this, [=](){
        emit btnStr(QString("log("));
    });
    connect(Floor, &QPushButton::released, this, [=](){
        emit btnStr(QString("floor("));
    });

    Tan = new QPushButton("tan");
    Atan= new QPushButton("atan");
    Log2= new QPushButton("log2");
    Cell= new QPushButton("cell");

    vlayout4->addWidget(Tan);
    vlayout4->addWidget(Atan);
    vlayout4->addWidget(Log2);
    vlayout4->addWidget(Cell);

    connect(Tan, &QPushButton::released, this, [=](){
        emit btnStr(QString("tan("));
    });
    connect(Atan, &QPushButton::released, this, [=](){
        emit btnStr(QString("atan("));
    });
    connect(Log2, &QPushButton::released, this, [=](){
        emit btnStr(QString("log2("));
    });
    connect(Cell, &QPushButton::released, this, [=](){
        emit btnStr(QString("cell("));
    });

    Abs  = new QPushButton("abs");
    sqrt = new QPushButton("sqrt");
    sqrt2= new QPushButton("sqrt");
    Power= new QPushButton("^");

    vlayout5->addWidget(Abs);
    vlayout5->addWidget(sqrt);
    vlayout5->addWidget(sqrt2);
    vlayout5->addWidget(Power);

    connect(Abs, &QPushButton::released, this, [=](){
        emit btnStr(QString("abs("));
    });
    connect(sqrt, &QPushButton::released, this, [=](){
        emit btnStr(QString("sqrt("));
    });
    connect(sqrt2, &QPushButton::released, this, [=](){
        emit btnStr(QString("sqrt("));
    });
    connect(Power, &QPushButton::released, this, [=](){
        emit btnStr(QString("^"));
    });

    hlayout->addLayout(vlayout1);
    hlayout->addLayout(vlayout2);
    hlayout->addLayout(vlayout3);
    hlayout->addLayout(vlayout4);
    hlayout->addLayout(vlayout5);

    QFile file("://Resource/btnwidget.css");
    if(file.open(QIODevice::ReadOnly|QIODevice::Text)){
        this->setStyleSheet(file.readAll());
    }
    this->setFixedSize(220,265);
    file.close();
}

void MoreOpr::connnetStr()
{

}
