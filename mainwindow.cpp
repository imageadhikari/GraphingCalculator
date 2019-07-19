#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtMath>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    MainWindow::MakePlot();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::MakePlot()
{

    phase = 0;
    multiplier = 1;
    angleTimes = 1;
    // generate some data:
    int num = 720;
    QVector<double> x(num), y(num); // initialize with entries 0..100
    showGraph();
}

void MainWindow::on_aButton_clicked()
{
    this->multiplier++;
    showGraph();
}

void MainWindow::on_nButton_clicked()
{
    this->angleTimes+=1;
    showGraph();
}

void MainWindow::on_bButton_clicked()
{
    this->phase+=15;
    showGraph();
}

void MainWindow::showGraph(){
    int num = 720;
    QVector<double> x(num), y(num); // initialize with entries 0..100
    for (int i=0; i<num; ++i)
    {
      x[i] = i; // x goes from -1 to 1
      double finalAngle = angleTimes * double(i) + phase;
      double rad = qDegreesToRadians(finalAngle);
      y[i] = multiplier * qSin(rad); // let's plot a quadratic function
    }

    // create graph and assign data to it:
    ui->customPlot->addGraph();
    ui->customPlot->graph(0)->setData(x, y);
    // give the axes some labels:
    ui->customPlot->xAxis->setLabel("x");
    ui->customPlot->yAxis->setLabel("y");
    // set axes ranges, so we see all data:
    ui->customPlot->xAxis->setRange(0, num);
    ui->customPlot->yAxis->setRange(-10, 10);
    ui->customPlot->replot();
}



void MainWindow::on_multiplierSpin_valueChanged(int arg1)
{
    this->multiplier = arg1;
    showGraph();
}

void MainWindow::on_angletimesSpin_valueChanged(int arg1)
{
    this->angleTimes = arg1;
    showGraph();
}

void MainWindow::on_phaseSpin_valueChanged(int arg1)
{
    this->phase = arg1;
    showGraph();
}

void MainWindow::on_pushButton_clicked()
{
    //show sine graph
    graph = new Graphs();
    this->hide();
    graph->show();
}
