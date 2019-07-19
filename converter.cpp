#include "converter.h"
#include "ui_converter.h"

Converter::Converter(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Converter)
{
    ui->setupUi(this);
}

Converter::~Converter()
{
    delete ui;
}
