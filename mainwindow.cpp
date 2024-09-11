#include "mainwindow.h"
#include "RenderWidget.h"
#include "./ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    RenderWidget *renderWidget = new RenderWidget(this);
    ui->openGLWidget = renderWidget;
}

MainWindow::~MainWindow()
{
    delete ui;
}
