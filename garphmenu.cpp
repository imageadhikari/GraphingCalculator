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
    graph = new Graphs();
    graph->show();
}

void GarphMenu::on_backButton_clicked()
{
//    this->hide();
//    QWidget *parent = this->parentWidget();
//    parent->show();
}
