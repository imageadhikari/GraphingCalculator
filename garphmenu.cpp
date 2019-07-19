#include "garphmenu.h"
#include "ui_garphmenu.h"

GarphMenu::GarphMenu(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GarphMenu)
{
    ui->setupUi(this);
}

GarphMenu::~GarphMenu()
{
    delete ui;
}

void GarphMenu::on_pushButton_clicked()
{
    this->close();
    graph = new Graphs(this,"sin");
    graph->show();
}

void GarphMenu::on_backButton_clicked()
{
    this->hide();
    QWidget *parent = this->parentWidget();
    parent->show();
}

void GarphMenu::on_pushButton_2_clicked()
{
    this->close();
    graph = new Graphs(this,"cos");
    graph->show();
}

void GarphMenu::on_pushButton_3_clicked()
{
    this->close();
    graph = new Graphs(this,"tan");
    graph->show();
}

void GarphMenu::on_pushButton_4_clicked()
{
    this->close();
    graph = new Graphs(this,"sec");
    graph->show();
}

void GarphMenu::on_pushButton_6_clicked()
{
    this->close();
    graph = new Graphs(this,"cosec");
    graph->show();
}

void GarphMenu::on_pushButton_5_clicked()
{
    this->close();
    graph = new Graphs(this,"cot");
    graph->show();
}
