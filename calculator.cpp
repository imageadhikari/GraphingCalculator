#include "calculator.h"
#include "ui_calculator.h"




Calculator::Calculator(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Calculator)
{
    ui->setupUi(this);


    double clacVal = 0.0;
    bool divTrigger = false;
    bool multTrigger = false;
    bool addTrigger = false;
    bool subTrigger = false;


    ui->lineEdit->setText(QString::number(clacVal));
    QPushButton *numButtons[10];

    for(int i=0;i<=9;i++){
        QString butName = "button"+ QString::number(i);
        numButtons[i] = Calculator::findChild<QPushButton *>(butName);
        connect(numButtons[i], SIGNAL(released()), this, SLOT(NumPressed()));
    }

    connect(ui->buttonPlus,SIGNAL(released()),this, SLOT(MathButtonPressed()));
    connect(ui->buttonMinus,SIGNAL(released()),this, SLOT(MathButtonPressed()));
    connect(ui->buttonDivide,SIGNAL(released()),this, SLOT(MathButtonPressed()));
    connect(ui->buttonMultiply,SIGNAL(released()),this, SLOT(MathButtonPressed()));
    connect(ui->buttonEquals,SIGNAL(released()),this, SLOT(EqualButtonPressed()));
}

void Calculator::NumPressed(){
    QPushButton *button = (QPushButton *)sender();
    QString butVal = button->text();
    QString displayVal = ui->lineEdit->text();
    if((displayVal.toDouble() == 0) || (displayVal.toDouble() == 0.0)){
        ui->lineEdit->setText(butVal);
    }else{
        QString newVal = displayVal + butVal;
        double dblNewVal = newVal.toDouble();
        ui->lineEdit->setText(QString::number(dblNewVal,'g',16));
    }

}

void Calculator::MathButtonPressed(){
    divTrigger = false;
    multTrigger = false;
    addTrigger = false;
    subTrigger = false;


    QPushButton *button = (QPushButton *)sender();
    QString buttonVal = button->text();

    clacVal = ui->lineEdit->text().toDouble();
    ui->lineEdit->setText("0.0");

    if(QString::compare(buttonVal,"+",Qt::CaseInsensitive) == 0){
        addTrigger =true;
    }else if(QString::compare(buttonVal,"-",Qt::CaseInsensitive)==0){
        subTrigger =true;
    }else if(QString::compare(buttonVal,"/",Qt::CaseInsensitive)==0){
        divTrigger =true;
    }else if(QString::compare(buttonVal,"*",Qt::CaseInsensitive)==0){
        multTrigger =true;
    }
}

void Calculator::EqualButtonPressed(){
    double num = ui->lineEdit->text().toDouble();

    if(addTrigger){
        clacVal += num;
    }
    if(subTrigger){
        clacVal -= num;
    }
    if(multTrigger){
        clacVal *= num;
    }
    if(divTrigger){
        clacVal /= num;
    }

    divTrigger = false;
    multTrigger = false;
    addTrigger = false;
    subTrigger = false;

    ui->lineEdit->setText(QString::number(clacVal,'g',16));

}



Calculator::~Calculator()
{
    delete ui;
}

void Calculator::on_backButton_clicked()
{
    this->hide();
    QWidget *parent = this->parentWidget();
    parent->show();
}
