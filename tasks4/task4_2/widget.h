#pragma once

#include <QWidget>
#include <QString>
#include "ui_widget.h"

namespace Ui {
class Widget;
}

class Widget : public QWidget//, public Ui::Widget
{
    Q_OBJECT
    
public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
public slots:
    void calc();
private:
    Ui::Widget *ui;

};

