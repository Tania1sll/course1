#include "mainwindow.h"
#include "OpenWindow.h"
#include <QApplication>
#include "createcustomer.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    OpenWindow o;
    o.show();
    return a.exec();
}
