#include <QtCore/QCoreApplication>
#include "demagedclass.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    try
    {
        DemagedClass obj;
    }
    catch (ConstructException)
    {}
    
    return a.exec();
}
