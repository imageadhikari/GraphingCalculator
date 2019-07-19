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
    explicit Graphs(QWidget *parent = nullptr);
    ~Graphs();

private:
    Ui::Graphs *ui;
};

#endif // GRAPHS_H
