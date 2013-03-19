#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    tree = new ParseTree;

    connect(ui->calcButton, SIGNAL(clicked()), this, SLOT(calc()));
}

MainWindow::~MainWindow()
{
    delete ui;
    delete tree;
}

void MainWindow::calc()
{
    QString filename = QFileDialog::getOpenFileName(this, "Open file", "/home", "(*.txt)");
    tree->parse(filename);
    QString answ("Answer: ");
    QString result;
    answ += result.number(tree->calc());
    this->ui->answerTextEdit->setText(answ);
    tree->print(this->ui->answerTextEdit);
}
