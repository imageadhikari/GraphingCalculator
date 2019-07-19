#ifndef GARPHMENU_H
#define GARPHMENU_H

#include <QMainWindow>
#include <graphs.h>
namespace Ui {
class GarphMenu;
}

class GarphMenu : public QMainWindow
{
    Q_OBJECT

public:
    explicit GarphMenu(QWidget *parent = nullptr);
    ~GarphMenu();

private slots:
    void on_pushButton_clicked();

    void on_backButton_clicked();

private:
    Ui::GarphMenu *ui;
    Graphs* graph;
};

#endif // GARPHMENU_H
