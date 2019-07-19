#ifndef CONVERTER_H
#define CONVERTER_H

#include <QMainWindow>

namespace Ui {
class Converter;
}

class Converter : public QMainWindow
{
    Q_OBJECT

public:
    explicit Converter(QWidget *parent = nullptr);
    ~Converter();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_5_clicked();


    void on_lengthInput_textChanged();

    void on_lIn_currentIndexChanged(int index);

    void on_lOut_currentIndexChanged(int index);

    void on_lengthOutput_textChanged();

    void on_currencyInput_textChanged();

    void on_cIn_currentIndexChanged(int index);

    void on_cOut_currentIndexChanged(int index);

    void on_weightInput_textChanged();

    void on_wIn_currentIndexChanged(int index);

    void on_wOut_currentIndexChanged(int index);

    void on_timeInput_textChanged();

    void on_tIn_currentIndexChanged(int index);

    void on_tOut_currentIndexChanged(int index);

private:
    Ui::Converter *ui;
    double lengthConvert(double inputLength);
    double curConvert(double inputCur);
    double weightConvert(double inputWeight);
    double timeConvert(double inputTime);
};

#endif // CONVERTER_H
