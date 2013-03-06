#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) : QWidget(parent), ui(new Ui::Widget)
{
    ui->setupUi(this);

    buttons = new QSignalMapper;

    QPushButton* button;
    // add 1 - 9 nums
    for (int i = 1; i <= 9; i++)
    {
        QString bName;
        bName.setNum(i);
        button = new QPushButton(bName);
        connect(button, SIGNAL(clicked()), buttons, SLOT(map()));
        buttons->setMapping(button, bName);
        ui->numsLayout->addWidget(button, (i - 1) / 3, (i - 1) % 3);
    }
    // add 0, dot & brackets
    const int otherNums = 3;
    const char otherButtons[otherNums] = {'0', '(', ')'};
    for (int i = 0; i < otherNums; ++i)
    {
        QString bName = QChar(otherButtons[i]);
        button = new QPushButton(bName);
        connect(button, SIGNAL(clicked()), buttons, SLOT(map()));
        buttons->setMapping(button, bName);
        ui->numsLayout->addWidget(button, 3, i % 3);
    }
    // add space button
    connect(ui->spaceButton, SIGNAL(clicked()), buttons, SLOT(map()));
    buttons->setMapping(ui->spaceButton, " ");
    // add operators
    const int operatorsNums = 4;
    const char operators[operatorsNums] = {'+', '-', '*', '/'};
    for (int i = 0; i < operatorsNums; ++i)
    {
        QString bName = QChar(operators[i]);
        button = new QPushButton(bName);
        connect(button, SIGNAL(clicked()), buttons, SLOT(map()));
        buttons->setMapping(button, bName);
        ui->oprsLayout->addWidget(button, i);
    }
    connect(buttons, SIGNAL(mapped(const QString&)),
            this, SLOT(changeExpression(const QString&)));

    button = new QPushButton("=");
    connect(button, SIGNAL(clicked()), this, SLOT(calculate()));
    ui->oprsLayout->addWidget(button, operatorsNums + 1);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::calculate()
{
    QString text = ui->expressionLineEdit->text();
    std::string expr = text.toStdString();
    try
    {
        double result = calculator.calc(expr);
        QString resultStr;
        resultStr.setNum(result, 'g', 8);
        ui->expressionLineEdit->setText(resultStr);
    }
    catch (std::exception *exc)
    {
        ui->expressionLineEdit->setText(QString(exc->what()));
    }
}

void Widget::changeExpression(const QString& str)
{
    QString newText = ui->expressionLineEdit->text();
    newText.append(str);
    ui->expressionLineEdit->setText(newText);
}
