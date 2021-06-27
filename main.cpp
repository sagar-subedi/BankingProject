#include "mainwindow.h"
#include <QtSql/QSql>
#include <QtSql/QSqlDatabase>
#include <QtSql>
#include <QDebug>

#include <QApplication>

int main(int argc, char *argv[])
{



    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
