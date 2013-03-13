#pragma once

#include <QWidget>
#include "ui_hashTableManager.h"
#include "hashTable.h"
#include "sumHashFunction.h"
#include "xorHashFunction.h"

namespace Ui {
class HashTableManager;
}

class HashTableManager : public QWidget
{
    Q_OBJECT
    
public:
    explicit HashTableManager(QWidget *parent = 0);
    ~HashTableManager();
    
private:
    Ui::HashTableManager *ui;
    HashTable<int>* table;
signals:
    void tableResponse(QString response);
private slots:
    void addElement();
    void deleteElement();
    void searchElement();
    void setSumHash();
    void setXORHash();
    void printStatistics();
    void out(QString text);
};

