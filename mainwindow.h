#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();



private slots:
    void on_PEEP_editingFinished();

    void on_PEEP_valueChanged(int arg1);

    void on_Pinsp_valueChanged(int arg1);

    void on_Paw_valueChanged(int arg1);

    void on_Paw_editingFinished();

    void on_Pinsp_editingFinished();

    void on_dPsupp_editingFinished();

    void on_dPsupp_valueChanged(int arg1);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
