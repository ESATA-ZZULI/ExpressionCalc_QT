#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "moreopr.h"
#include "numberbtn.h"
#include "oprbtns.h"
#include <QPushButton>
#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <calcer.h>
#include <stack>

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void initUI();
    void check_and_add(QString str);
private:
    MoreOpr* moreopr;
    NumberBtn* numberbtn;
    Oprbtns* oprbtns;

    QLabel* ExpressionLabel;
    QString* Expression;

    Calcer* calcer;
    std::stack<QString>* lastStr;
};
#endif // WIDGET_H
