#ifndef GRAPHS_H
#define GRAPHS_H

#include <QMainWindow>

namespace Ui {
class Graphs;
}

class Graphs : public QMainWindow
{
    Q_OBJECT

public:
    explicit Graphs(QWidget *parent = nullptr, QString curve="sin");
    ~Graphs();

private slots:

    void on_angletimesSpin_valueChanged(int arg1);

    void on_multiplierSpin_valueChanged(int arg1);

    void on_phaseSpin_valueChanged(int arg1);

    void on_backButton_clicked();

private:
    Ui::Graphs *ui;

    double phase;
    double multiplier;
    double angleTimes;

    QString curveType;

    void showGraph();

    double getFunctionValue(double finalTheta);
};

#endif // GRAPHS_H
