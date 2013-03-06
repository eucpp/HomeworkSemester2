#pragma once

#include <string>
#include <exception>
#include <QWidget>
#include <QPushButton>
#include <QSignalMapper>
#include <QString>
#include "ui_widget.h"
#include "../../tasks2/task2_2/calculator.h"

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT
    
public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
private:
    Calculator calculator;
    Ui::Widget *ui;
    QSignalMapper* buttons;
private slots:
    void calculate();
    void changeExpression(const QString& str);
};

