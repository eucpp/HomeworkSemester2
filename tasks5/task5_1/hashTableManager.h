#pragma once

#include <QWidget>

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
};

