#include "graphs.h"
#include "ui_graphs.h"

Graphs::Graphs(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Graphs)
{
    ui->setupUi(this);
}

Graphs::~Graphs()
{
    delete ui;
}
