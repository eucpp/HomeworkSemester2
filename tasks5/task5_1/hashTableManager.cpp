#include "hashTableManager.h"
#include "ui_hashTableManager.h"

HashTableManager::HashTableManager(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::HashTableManager)
{
    ui->setupUi(this);
}

HashTableManager::~HashTableManager()
{
    delete ui;
}
