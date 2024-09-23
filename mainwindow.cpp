#include "mainwindow.h"
#include "RenderWidget.h"
#include "./ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    RenderWidget* renderWidget = new RenderWidget(this);
    ui->horizontalLayout->addWidget(renderWidget, 1);
}

MainWindow::~MainWindow()
{
    delete ui;
}
