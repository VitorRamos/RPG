#include "mainwindow.h"
#include <QApplication>

int x= 0;

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    MainWindow w;
    w.show();

   // while(true)
   // {
    //    a.processEvents();
        // Engine
   // }
   // a.exit();

    return a.exec();
}
