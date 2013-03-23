#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "set.h"

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
    void addElementToSet1();
    void addElementToSet2();
    void clearSet1();
    void clearSet2();
    void unionSets();
    void intersectionSets();
private:
    QString printSetElements(Set<int>* set);
    Ui::MainWindow *ui;
    Set<int>* set1;
    Set<int>* set2;
};

#endif // MAINWINDOW_H
