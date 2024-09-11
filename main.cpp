#include "mainwindow.h"
#include "RenderWidget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    RenderWidget r;
    // r.resizeGL(640, 400);
    w.show();
    return a.exec();
}
