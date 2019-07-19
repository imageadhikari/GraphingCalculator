#include "converter.h"
#include "ui_converter.h"
#include <QDebug>

Converter::Converter(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Converter)
{
    ui->setupUi(this);

    // length
    ui->lIn->addItem("centimeters");
    ui->lOut->addItem("centimeters");
//    ui->lIn->addItem("inches");
//    ui->lOut->addItem("inches");
    ui->lIn->addItem("meters");
    ui->lOut->addItem("meters");
    ui->lIn->addItem("kilometers");
    ui->lOut->addItem("kilometers");

    // currency
//    ui->cIn->addItem("USD");
//    ui->cOut->addItem("USD");
    ui->cIn->addItem("NPR");
    ui->cOut->addItem("NPR");
    ui->cIn->addItem("INR");
    ui->cOut->addItem("INR");

    // weight
    ui->wIn->addItem("gram");
    ui->wOut->addItem("gram");
    ui->wIn->addItem("kilogram");
    ui->wOut->addItem("kilogram");
//    ui->wIn->addItem("lb");
//    ui->wOut->addItem("lb");

    // time
    ui->tIn->addItem("seconds");
    ui->tOut->addItem("seconds");
    ui->tIn->addItem("minutes");
    ui->tOut->addItem("minutes");
    ui->tIn->addItem("hours");
    ui->tOut->addItem("hours");
//    ui->tIn->addItem("days");
//    ui->tOut->addItem("days");

}

Converter::~Converter()
{
    delete ui;
}



void Converter::on_pushButton_clicked()
{
     ui->mainStack->setCurrentIndex(0);
}

void Converter::on_pushButton_4_clicked()
{
     ui->mainStack->setCurrentIndex(1);
}

void Converter::on_pushButton_2_clicked()
{
     ui->mainStack->setCurrentIndex(2);
}

void Converter::on_pushButton_5_clicked()
{
     ui->mainStack->setCurrentIndex(3);
}

void Converter::on_lengthInput_textChanged()
{
    //qDebug()<<ui->lIn->currentText()<<ui->lOut->currentText()<<ui->lengthInput->toPlainText();
    double convertedValue = lengthConvert(ui->lengthInput->toPlainText().toDouble());
    ui->lengthOutput->setText(QString::number(convertedValue));
}


double Converter::lengthConvert(double inputLength){
    double meterVal = 1;
    if(ui->lIn->currentText() == "centimeters"){
        meterVal = inputLength / 100;
    }else if (ui->lIn->currentText() == "meters") {
        meterVal = inputLength;
    } else if (ui->lIn->currentText() == "kilometers") {
        meterVal = inputLength * 1000;
    }

    QString target = ui->lOut->currentText();
    if(target == "centimeters"){
        return meterVal*100;
    }else if(target == "kilometers" ){
        return  meterVal/1000;
    } else {
        return meterVal;
    }
}

void Converter::on_lIn_currentIndexChanged(int index)
{
    double convertedValue = lengthConvert(ui->lengthInput->toPlainText().toDouble());
    ui->lengthOutput->setText(QString::number(convertedValue));
}

void Converter::on_lOut_currentIndexChanged(int index)
{
    double convertedValue = lengthConvert(ui->lengthInput->toPlainText().toDouble());
    ui->lengthOutput->setText(QString::number(convertedValue));
}

void Converter::on_lengthOutput_textChanged() // not functional yet!!!!
{
//    qDebug()<<ui->lOut->currentText()<<ui->lIn->currentText()<<ui->lengthOutput->toPlainText();
//    double convertedValue = lengthConvert(ui->lengthOutput->toPlainText().toDouble());
//    ui->lengthInput->setText(QString::number(convertedValue));
}

void Converter::on_currencyInput_textChanged()
{
    double convertedValue = curConvert(ui->currencyInput->toPlainText().toDouble());
    ui->currencyOutput->setText(QString::number(convertedValue));
}

double Converter::curConvert(double inputCur){
    double nrsVal=1;
    if(ui->cIn->currentText()=="NPR"){
        nrsVal=inputCur;
    } else if(ui->cIn->currentText()=="INR"){
        nrsVal=inputCur*1.6;
    }

    QString target = ui->cOut->currentText();
    if(target == "INR" ){
        return nrsVal/1.6;
    } else {
        return nrsVal;
    }

}



void Converter::on_cIn_currentIndexChanged(int index)
{
    double convertedValue = curConvert(ui->currencyInput->toPlainText().toDouble());
    ui->currencyOutput->setText(QString::number(convertedValue));
}

void Converter::on_cOut_currentIndexChanged(int index)
{
    double convertedValue = curConvert(ui->currencyInput->toPlainText().toDouble());
    ui->currencyOutput->setText(QString::number(convertedValue));
}

void Converter::on_weightInput_textChanged()
{
    double convertedValue = weightConvert(ui->weightInput->toPlainText().toDouble());
    ui->weightOutput->setText(QString::number(convertedValue));
}

double Converter::weightConvert(double inputWeight){
    double gramVal = 1;
    if(ui->wIn->currentText() == "kilogram"){
        gramVal = inputWeight * 1000;
    }else if (ui->wIn->currentText() == "gram") {
        gramVal = inputWeight;
    }

    QString target = ui->wOut->currentText();
    if(target == "kilogram"){
        return gramVal/1000;
    }else {
        return gramVal;
    }
}

void Converter::on_wIn_currentIndexChanged(int index)
{
    double convertedValue = weightConvert(ui->weightInput->toPlainText().toDouble());
    ui->weightOutput->setText(QString::number(convertedValue));
}

void Converter::on_wOut_currentIndexChanged(int index)
{
    double convertedValue = weightConvert(ui->weightInput->toPlainText().toDouble());
    ui->weightOutput->setText(QString::number(convertedValue));
}

void Converter::on_timeInput_textChanged()
{
    double convertedValue = timeConvert(ui->timeInput->toPlainText().toDouble());
    ui->timeOutput->setText(QString::number(convertedValue));
}

double Converter::timeConvert(double inputTime){
    double minuteVal = 1;
    if(ui->tIn->currentText() == "seconds"){
        minuteVal = inputTime / 60;
    }else if (ui->tIn->currentText() == "hours") {
        minuteVal = inputTime * 60;
    } else if(ui->tIn->currentText()=="minutes"){
        minuteVal=inputTime;
    }

    QString target = ui->tOut->currentText();
    if(target == "seconds"){
        return minuteVal*60;
    }else if(target=="hours"){
        return minuteVal/60;
    } else{
        return minuteVal;
    }
}

void Converter::on_tIn_currentIndexChanged(int index)
{
    double convertedValue = timeConvert(ui->timeInput->toPlainText().toDouble());
    ui->timeOutput->setText(QString::number(convertedValue));
}

void Converter::on_tOut_currentIndexChanged(int index)
{
    double convertedValue = timeConvert(ui->timeInput->toPlainText().toDouble());
    ui->timeOutput->setText(QString::number(convertedValue));
}
