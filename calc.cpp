#include "calc.h"
#include "./ui_calc.h"
calc::calc(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::calc)
{
    ui->setupUi(this);
    //маска #	дозволяє цифри і знаки +,-
    //ui->lineEdit->setInputMask("#");
    QRegularExpression rx("^(-?)[1-9][0-9]{1,7}([\.][0-9]{1,2})?$");
    QValidator *validator = new QRegularExpressionValidator(rx, this);
    ui->lineEdit->setValidator(validator);
}
calc::~calc()
{
    delete ui;
}

void calc::on_pushButton_plus_clicked()
{
    input = ui->lineEdit->text();
    ui->lineEdit->setText(input+"+");
    operation = 1;
    operand1  = input.toDouble();
    output    = input+"+";
    ui->lineEdit_2->setText(output);
    ui->lineEdit->setText("");
}

void calc::on_pushButton_7_clicked()
{
    input = ui->lineEdit->text();
    operand2 = input.toDouble();
    output+=input;
    ui->lineEdit_2->setText(output);
    switch (operation) {
    case 1:
        result = operand1 + operand2;
        break;
    case 2:

        break;
    default:
        break;
    }
    output+="="+QString::number(result);
    ui->lineEdit_2->setText(output);
    ui->lineEdit->  setText(QString::number(result));
    output=input="";
}

void calc::on_lineEdit_returnPressed()
{
    QString temp=ui->lineEdit->text();
    QRegularExpressionMatch obj = regular.match(temp);
    if (obj.hasMatch())
    {
        ui->lineEdit_2->setText("Число");
        //qDebug("Число");
    }
    else
    {
        ui->lineEdit_2->setText("Не число");
        //qDebug("Не число");
    };
}
