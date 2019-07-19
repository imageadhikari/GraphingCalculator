#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtMath>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    //show sine graph
    graphMenu = new GarphMenu(this);
    this->hide();
    graphMenu->show();
}

void MainWindow::on_pushButton_2_clicked()
{
    converter = new Converter();
    this->hide();
    converter->show();
}


void MainWindow::on_calcOpen_clicked()
{
    calc = new Calculator(this);
    this->hide();
    calc->show();
}
