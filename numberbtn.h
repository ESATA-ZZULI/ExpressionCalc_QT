#ifndef NUMBERBTN_H
#define NUMBERBTN_H

#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QFile>

class NumberBtn : public QWidget
{
    Q_OBJECT
public:
    explicit NumberBtn(QWidget *parent = nullptr);
    void initUI();
private:
    QVBoxLayout* hlayout;

    QPushButton* Number7;
    QPushButton* Number8;
    QPushButton* Number9;

    QHBoxLayout* vlayout1;

    QPushButton* Number4;
    QPushButton* Number5;
    QPushButton* Number6;

    QHBoxLayout* vlayout2;

    QPushButton* Number1;
    QPushButton* Number2;
    QPushButton* Number3;

    QHBoxLayout* vlayout3;

    QPushButton* Number0;
    QPushButton* dot;

    QHBoxLayout* vlayout4;
signals:
    void btnStr(QString btnstr);
};

#endif // NUMBERBTN_H
