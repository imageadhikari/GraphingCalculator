#include "graphs.h"
#include "ui_graphs.h"

Graphs::Graphs(QWidget *parent,QString curve) :
    QMainWindow(parent),
    ui(new Ui::Graphs)
{
    ui->setupUi(this);
    phase = 0;
    multiplier = 1;
    angleTimes = 1;

    QString titleFormula = "y=A"+curve+"(Ax+b)";
    ui->formula->setText(titleFormula);
    this->curveType = curve;
    showGraph();
}

Graphs::~Graphs()
{
    delete ui;
}


void Graphs::on_angletimesSpin_valueChanged(int arg1)
{
    this->angleTimes=arg1;
    showGraph();
}

void Graphs::on_multiplierSpin_valueChanged(int arg1)
{
    this->multiplier=arg1;
    showGraph();
}

void Graphs::on_phaseSpin_valueChanged(int arg1)
{
    this->phase=arg1;
    showGraph();
}


void Graphs::showGraph(){
    int num = 720;
    QVector<double> x(num), y(num); // initialize with entries 0..100
    for (int i=0; i<num; ++i)
    {
      x[i] = i; // x goes from -1 to 1
      double finalAngle = angleTimes * double(i) + phase;
      double rad = qDegreesToRadians(finalAngle);
      y[i] = multiplier * getFunctionValue(rad); // let's plot a quadratic function
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

void Graphs::on_backButton_clicked()
{
    this->close();
    QWidget *parent = this->parentWidget();
    parent->show();
}

double Graphs::getFunctionValue(double finalTheta){
    if(curveType == "sin"){
        return  qSin(finalTheta);
    }else if (curveType == "cos") {
        return  qCos(finalTheta);
    }else if (curveType == "tan"){
        return  qTan(finalTheta);
    }else if(curveType == "sec"){
        return  1/qCos(finalTheta);
    }else if(curveType == "cot"){
        return  1/qTan(finalTheta);
    }else if(curveType == "cosec"){
        return  1/qSin(finalTheta);
    }
    return  qSin(finalTheta);
}
