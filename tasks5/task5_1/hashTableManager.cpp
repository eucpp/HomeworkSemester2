#include "hashTableManager.h"
#include "ui_hashTableManager.h"

HashTableManager::HashTableManager(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::HashTableManager)
{
    ui->setupUi(this);
    const int tableSize = 1001;
    table = new HashTable<int>(tableSize, new SumHashFunction);

    connect(ui->addButton, SIGNAL(clicked()), this, SLOT(addElement()));
    connect(ui->deleteButton, SIGNAL(clicked()), this, SLOT(deleteElement()));
    connect(ui->searchButton, SIGNAL(clicked()), this, SLOT(searchElement()));
    connect(ui->polynomialHashButton, SIGNAL(clicked()), this, SLOT(setSumHash()));
    connect(ui->xorHashButton, SIGNAL(clicked()), this, SLOT(setXORHash()));
    connect(ui->statisticsButton, SIGNAL(clicked()), this, SLOT(printStatistics()));
    connect(this, SIGNAL(tableResponse(QString)), this, SLOT(out(QString)));

    ui->polynomialHashButton->setEnabled(false);
}

HashTableManager::~HashTableManager()
{
    delete ui;
    delete table;
}

void HashTableManager::addElement()
{
    QString key = ui->addKeyEdit->text();
    int value = ui->valAddEdit->text().toInt();
    table->addElement(key, value);
    QString outStr = "Value was successful added";
    emit tableResponse(outStr);
}
void HashTableManager::deleteElement()
{
    QString key = ui->deleteKeyEdit->text();
    table->deleteElement(key);
    QString outStr = "Value was deleted";
    emit tableResponse(outStr);
}
void HashTableManager::searchElement()
{
    QString key = ui->searchKeyEdit->text();
    try
    {
        table->getElement(key);
        QString outStr = "Value was founded in hash table";
        emit tableResponse(outStr);
    }
    catch (AccessToEmptyExc*)
    {
        QString outStr = "Hash table doesn't contain the desired value";
        emit tableResponse(outStr);
    }
}

void HashTableManager::printStatistics()
{
    QString outText = "Hash table statistics: \n";
    outText += "Table size: ";
    outText += QString().setNum(table->getSize());
    outText += "\n Load factor: ";
    outText += QString().setNum(table->getLoadFactor());
    outText += "\n Conflicts: ";
    outText += QString().setNum(table->getConflictCellsNum());
    outText += "\n Most loaded cell: ";
    outText += QString().setNum(table->getMostLoadedCell());
    outText += "\n Length of the most loaded cell: ";
    outText += QString().setNum(table->getMostLoadedCellLength());
    emit tableResponse(outText);
}
void HashTableManager::setXORHash()
{
    ui->xorHashButton->setEnabled(false);
    ui->polynomialHashButton->setChecked(false);
    ui->polynomialHashButton->setEnabled(true);
    table->setHashFunction(new XORHashFunction);
    QString outStr = "Hash function was changed";
    emit tableResponse(outStr);
}
void HashTableManager::setSumHash()
{
    ui->polynomialHashButton->setEnabled(false);
    ui->xorHashButton->setChecked(false);
    ui->xorHashButton->setEnabled(true);
    table->setHashFunction(new SumHashFunction);
    QString outStr = "Hash function was changed";
    emit tableResponse(outStr);
}

void HashTableManager::out(QString text)
{
    ui->output->setText(text);
}
