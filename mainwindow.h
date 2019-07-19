#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<graphs.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void MakePlot();

    void on_aButton_clicked();

    void on_nButton_clicked();


    void on_bButton_clicked();

    void on_multiplierSpin_valueChanged(int arg1);

    void on_angletimesSpin_valueChanged(int arg1);

    void on_phaseSpin_valueChanged(int arg1);

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;

    Graphs* graph;

    double phase;
    double multiplier;
    double angleTimes;

    void showGraph();
};

#endif // MAINWINDOW_H
