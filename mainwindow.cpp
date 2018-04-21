#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QDebug"

#include "littlehelper.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_PEEP_editingFinished()
{
    qDebug() << "Edit PEEP einsteller finished\r\n";
}

void MainWindow::on_PEEP_valueChanged(int arg1)
{
    qDebug() << "Edit PEEP einsteller Value Changed\r\n";

    /*
     *
     *
     *
     */


    int actualpinsp = ui->Pinsp->value();
    int actualpaw = ui->Paw->value();
    int actualdpsupp = ui->dPsupp->value();

    qDebug() << "Pinsp ="<<actualpinsp<<"Paw"<<actualpaw<<"dPsupp"<<actualdpsupp;

    int lowernumber = smallest(actualpinsp,actualpaw,actualdpsupp);


     qDebug() << "Smallest is"<<lowernumber;

    ui->PEEP->setMaximum(lowernumber);
}



