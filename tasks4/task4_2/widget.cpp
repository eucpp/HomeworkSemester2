#include "widget.h"

Widget::Widget(QWidget *parent) : QWidget(parent), ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::calc()
{
    int argL = ui->argLBox->value();
    int argR = ui->argRBox->value();
    QString opr = ui->oprBox->currentText();
    double result;
    if (opr == "+")
        result = argL + argR;
    if (opr == "-")
        result = argL - argR;
    if (opr == "*")
        result = argL * argR;
    if (opr == "/")
    {
        if (argR == 0)
        {
            ui->resultLineEdit->setText("Dividing by zero");
            return;
        }
        else
            result = static_cast<double>(argL) / argR;
    }
    QString resultStr;
    resultStr.setNum(result, 'g', 8);
    ui->resultLineEdit->setText(resultStr);
}
