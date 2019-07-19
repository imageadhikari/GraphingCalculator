#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QMainWindow>

namespace Ui {
class Calculator;
}

class Calculator : public QMainWindow
{
    Q_OBJECT

public:
    explicit Calculator(QWidget *parent = nullptr);
    ~Calculator();

private slots:
    void on_backButton_clicked();
    void NumPressed();
    void MathButtonPressed();
    void EqualButtonPressed();

private:
    Ui::Calculator *ui;
    double clacVal;
    bool divTrigger;
    bool multTrigger;
    bool addTrigger;
    bool subTrigger;
};

#endif // CALCULATOR_H
