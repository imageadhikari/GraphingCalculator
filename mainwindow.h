#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<garphmenu.h>
#include<converter.h>
#include<calculator.h>

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

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();


    void on_calcOpen_clicked();

private:
    Ui::MainWindow *ui;

    GarphMenu *graphMenu;
    Converter *converter;
    Calculator *calc;
};

#endif // MAINWINDOW_H
