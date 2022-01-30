#ifndef MOREOPR_H
#define MOREOPR_H

#include <QObject>
#include <QWidget>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QFile>

class MoreOpr : public QWidget
{
    Q_OBJECT
public:
    explicit MoreOpr(QWidget *parent = nullptr);
    void initUI();
    void connnetStr();
private:
    QVBoxLayout* hlayout;

    QPushButton* Pi;
    QPushButton* E;
    QPushButton* AC;
    QPushButton* Del;

    QHBoxLayout* vlayout1;

    QPushButton* Sin;
    QPushButton* Asin;
    QPushButton* Ln;
    QPushButton* Sign;

    QHBoxLayout* vlayout2;

    QPushButton* Cos;
    QPushButton* Acos;
    QPushButton* log;
    QPushButton* Floor;

    QHBoxLayout* vlayout3;

    QPushButton* Tan;
    QPushButton* Atan;
    QPushButton* Log2;
    QPushButton* Cell;

    QHBoxLayout* vlayout4;

    QPushButton* Abs;
    QPushButton* sqrt;
    QPushButton* sqrt2;
    QPushButton* Power;

    QHBoxLayout* vlayout5;
signals:
    void btnStr(QString btnstr);
};

#endif // MOREOPR_H
