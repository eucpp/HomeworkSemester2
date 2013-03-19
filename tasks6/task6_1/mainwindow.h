#pragma once

#include <QMainWindow>
#include <QFileDialog>

#include "parseTree.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
public slots:
    void calc();
private:
    Ui::MainWindow *ui;
    ParseTree* tree;
};

