#ifndef OPRBTNS_H
#define OPRBTNS_H

#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QFile>

class Oprbtns : public QWidget
{
    Q_OBJECT
public:
    explicit Oprbtns(QWidget *parent = nullptr);
    void initUI();
private:
    QVBoxLayout* hlayout;

    QPushButton* left;
    QPushButton* right;


    QHBoxLayout* vlayout1;

    QPushButton* chu;
    QPushButton* jia;

    QHBoxLayout* vlayout2;

    QPushButton* cheng;
    QPushButton* jian;

    QHBoxLayout* vlayout3;

    QPushButton* youxie;
    QPushButton* mod;

    QHBoxLayout* vlayout4;

    QPushButton* Equl;

signals:
    void btnStr(QString btnstr);
};

#endif // OPRBTNS_H
