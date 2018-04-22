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

    void readOutActualValues(int arg1);
    void refreshMINMAXLcdDisplays(int arg1);



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

    unsigned int mMAXPAW;
    unsigned int mMINPAW;

    unsigned int mMAXPINSP;
    unsigned int mMINPINSP;

    unsigned int mMAXDPSUPP;
    unsigned int mMINDPSUPP;

    unsigned int mMAXPEEP;
    unsigned int mMINPEEP;

    unsigned int mActualpinsp;
    unsigned int mActualpaw;
    unsigned int mActualdpsupp;
    unsigned int mActualpeep;

};

#endif // MAINWINDOW_H
