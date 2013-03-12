#include <QObject>
#include <QtTest/QtTest>
#include <iostream>
#include "singleLinkedList.h"
#include "doubleLinkedList.h"
#include "accessToEmptyExc.h"
#include "singleLinkedListTest.h"
#include "doubleLinkedListTest.h"


using namespace std;

namespace Commands
{
    enum Commands
    {
        exit,
        add,
        remove,
        current,
        next,
        prev,
        head,
        print,
        isEmpty,
        isEOL,
        count,
        help
    };
}

void help()
{
    cout << Commands::exit << " - Exit" << endl;
    cout << Commands::add << " - Add new value before the current list element" << endl;
    cout << Commands::remove << " - Remove current element" << endl;
    cout << Commands::current << " - Print current element value" << endl;
    cout << Commands::next << " - Move current list element to next" << endl;
    cout << Commands::prev << " - Move current list element to previous" << endl;
    cout << Commands::head << " - Move current list element to head of the list" << endl;
    cout << Commands::print << " - Print list" << endl;
    cout << Commands::isEmpty << " - Check does list empty" << endl;
    cout << Commands::isEOL << " - Check does current element NULL" << endl;
    cout << Commands::count << " - Print count of elements in the list" << endl;
    cout << Commands::help << " - Print help";
}

void print(AbstractList<int>* list)
{
    list->head();
    while (!list->isEOL())
    {
        cout << list->current() << " --> ";
        list->next();
    }
    cout << "NULL";
    list->head();
}

void acceptCommand(int command, AbstractList<int>* list)
{
    int val;
    switch(command)
    {
    case Commands::exit:
        return;
    case Commands::add:
        cout << "Enter value: ";
        cin >> val;
        list->addElement(val);
        break;
    case Commands::remove:
        cout << "Remove current element ...";
        list->removeElement();
        break;
    case Commands::current:
        try
        {
            cout << "current element: " << list->current();
        }
        catch (std::exception* e)
        {
            cout << e->what();
            delete e;
        }
        break;
    case Commands::next:
        cout << "move current element to next..." << endl;
        list->next();
        break;
    case Commands::prev:
        cout << "move current element to previous..." << endl;
        list->prev();
        break;
    case Commands::head:
        cout << "move current element to head" << endl;
        list->head();
        break;
    case Commands::print:
        cout << "Print list: ";
        print(list);
        break;
    case Commands::isEmpty:
        if (list->isEmpty())
            cout << "List is empty";
        else
            cout << "List isn't empty";
        break;
    case Commands::isEOL:
        if (list->isEOL())
            cout << "Current element is NULL";
        else
            cout << "Current element isn't NULL";
        break;
    case Commands::count:
        cout << "Current cout of elements in list: " << list->count();
        break;
    case Commands::help:
        help();
        break;
    default:
        cout << "Incorrect command!" << endl;
        help();
    }
}

int main()
{
    /*
    QObject* singleListTest = new SingleLinkedListTest();
    QTest::qExec(singleListTest);
    QObject* doubleListTest = new SingleLinkedListTest();
    QTest::qExec(doubleListTest);
    */

    cout << "List manager greets you!" << endl;
    cout << "What kind of list would you like to create?" << endl;
    cout << "0 - single linked list" << endl;
    cout << "1 - double linked list" << endl;

    int listType = 0;
    cin >> listType;
    AbstractList<int>* list;
    if (listType == 0)
        list = new SingleLinkedList<int>();
    else if (listType == 1)
        list = new DoubleLinkedList<int>();

    cout << endl;
    int command = Commands::help;
    while (command != Commands::exit)
    {
        acceptCommand(command, list);
        cout << endl;
        cout << "Waiting your command... ";
        cin >> command;
        cout << endl;
    }
    delete list;

    return 0;
}


