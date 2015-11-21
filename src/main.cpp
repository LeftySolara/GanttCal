#include "ui/mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QCoreApplication::setOrganizationName("GanttCal");
    QCoreApplication::setApplicationName("GanttCal");
    QCoreApplication::setApplicationVersion("0.1");

    MainWindow w;
    w.show();

    return a.exec();
}
