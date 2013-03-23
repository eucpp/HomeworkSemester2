#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    set1 = new Set<int>;
    set2 = new Set<int>;

    connect(ui->add1Button, SIGNAL(clicked()), this, SLOT(addElementToSet1()));
    connect(ui->add2Button, SIGNAL(clicked()), this, SLOT(addElementToSet2()));
    connect(ui->unionButton, SIGNAL(clicked()), this, SLOT(unionSets()));
    connect(ui->intersectionButton, SIGNAL(clicked()), this, SLOT(intersectionSets()));
    connect(ui->clear1Button, SIGNAL(clicked()), this, SLOT(clearSet1()));
    connect(ui->clear2Button, SIGNAL(clicked()), this, SLOT(clearSet2()));
}

MainWindow::~MainWindow()
{
    delete ui;

    delete set1;
    delete set2;
}

QString MainWindow::printSetElements(Set<int>* set)
{
    QStack<int>elements = set->getSetElements();
    QString result;
    while (!elements.isEmpty())
    {
        result += QString().number(elements.pop());
        result += QString(", ");
    }
    return result;
}
void MainWindow::addElementToSet1()
{
    set1->addElement(ui->added1->text().toInt());
    ui->set1Elements->setText(printSetElements(set1));
}
void MainWindow::addElementToSet2()
{
    set2->addElement(ui->added2->text().toInt());
    ui->set2Elements->setText(printSetElements(set2));
}
void MainWindow::unionSets()
{
    Set<int>* unionSet = Set<int>::unionSets(set1, set2);
    ui->resultLineEdit->setText(printSetElements(unionSet));
    delete unionSet;
}
void MainWindow::intersectionSets()
{
    Set<int>* intersectionSet = Set<int>::intersectionSets(set1, set2);
    ui->resultLineEdit->setText(printSetElements(intersectionSet));
    delete intersectionSet;
}
void MainWindow::clearSet1()
{
    delete set1;
    set1 = new Set<int>;
    ui->set1Elements->setText(" ");
}
void MainWindow::clearSet2()
{
    delete set2;
    set2 = new Set<int>;
    ui->set2Elements->setText(" ");
}
