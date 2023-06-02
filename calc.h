
#ifndef CALC_H
#define CALC_H

#include <QMainWindow>
#include <QRegularExpression>
//#include <QRegularExpressionMatch>
#include <QRegularExpressionValidator>
QT_BEGIN_NAMESPACE
namespace Ui { class calc; }
QT_END_NAMESPACE

class calc : public QMainWindow

{
    Q_OBJECT

public:
    calc(QWidget *parent = nullptr);
    ~calc();

private slots:
    void on_pushButton_plus_clicked();
    //void on_pushButton_6_clicked();
    void on_pushButton_7_clicked();
    void on_lineEdit_returnPressed();

private:
    Ui::calc *ui;
    QString input, output;
    double  operand1, operand2, result;
    int     operation;
    QString r= "^(-?)[1-9][0-9]{1,6}([\.][0-9]{1,3})?$";
    //QString r="^[^a-zA-Z~!@#$%\^&\*\(\)\+/=:;'\?\[\]\{\} ]{1,7}([,\.][0-9]{1,3})?$";
    //QString r = "^-?[0-9]{1,7}([,\.][0-9]{1,3})?[\+\*\-\/%]?$";
    QRegularExpression regular = QRegularExpression(r);
};

#endif // CALC_H
