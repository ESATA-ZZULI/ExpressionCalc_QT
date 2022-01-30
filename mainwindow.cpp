#include "mainwindow.h"
#include<QGraphicsDropShadowEffect>
#include <string>
#include <QDebug>


MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
{
    initUI();
    //setAttribute(Qt::WA_TranslucentBackground);
//    QGraphicsDropShadowEffect *shadow_effect = new QGraphicsDropShadowEffect(this);
//    shadow_effect->setOffset(5, 5);
//    shadow_effect->setBlurRadius(9.0);
//    shadow_effect->setColor(QColor(0, 0, 0, 160)); //阴影的颜色

//    this->moreopr->setGraphicsEffect(shadow_effect);
//    this->numberbtn->setGraphicsEffect(shadow_effect);
//    this->oprbtns->setGraphicsEffect(shadow_effect);
    connect(moreopr,QOverload<QString>::of(&MoreOpr::btnStr), this, [=](QString str){
        check_and_add(str);
    });
    connect(numberbtn,QOverload<QString>::of(&NumberBtn::btnStr), this, [=](QString str){
        check_and_add(str);
    });
    connect(oprbtns,QOverload<QString>::of(&Oprbtns::btnStr), this, [=](QString str){
        check_and_add(str);
    });

    calcer = new Calcer();
    lastStr = new std::stack<QString>();
    this->setWindowTitle("简易计算器");
}

MainWindow::~MainWindow()
{
}

void MainWindow::initUI(){
    moreopr = new MoreOpr();
    numberbtn = new NumberBtn();
    oprbtns = new Oprbtns();
    moreopr->setObjectName("moreopr");
    numberbtn->setObjectName("numberbtn");
    oprbtns->setObjectName("oprbtns");
    auto* hlayout = new QHBoxLayout();
    auto* vlayout = new QVBoxLayout(this);
    hlayout->addWidget(moreopr);
    hlayout->addWidget(numberbtn);
    hlayout->addWidget(oprbtns);
    hlayout->setSpacing(30);
    Expression = new QString("");
    ExpressionLabel = new QLabel(Expression->toStdString().c_str());
    ExpressionLabel->setAlignment(Qt::AlignRight);
    auto* hlayout2 = new QHBoxLayout();
    hlayout2->addWidget(ExpressionLabel);
    vlayout->addLayout(hlayout2);
    hlayout2->setContentsMargins(10,10,10,10);

    vlayout->addLayout(hlayout);

    vlayout->setContentsMargins(0, 0, 0, 0);

    QFile file("://Resource/main.css");
    if(file.open(QIODevice::ReadOnly|QIODevice::Text)){
        this->setStyleSheet(file.readAll());
    }
    file.close();
}

void MainWindow::check_and_add(QString str)
{
    if(str=="AC"){
        this->Expression->clear();
    }
    else if(str=="Del"){
        //回退一个数字
        if(!this->Expression->isEmpty()&&!this->lastStr->empty()){
            int lastStrLen = this->lastStr->top().length();
            qDebug()<<lastStrLen;
            this->Expression->remove(this->Expression->length()-lastStrLen, lastStrLen);
            this->lastStr->pop();
        }
//        while(!this->lastStr->empty()){
//            qDebug()<<this->lastStr->top();
//            this->lastStr->pop();
//        }
    }
    else if(str=="="){
        //运算
        std::string res = calcer->calc(this->Expression->toStdString());
        this->Expression->clear();
        this->Expression->append("Result: ");
        this->Expression->append(res.c_str());
    }
    else{
        this->Expression->append(str);
        this->lastStr->push(str);
    }
    this->ExpressionLabel->setText(this->Expression->toStdString().c_str());
}

