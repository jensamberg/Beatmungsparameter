#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QDebug"

#include "littlehelper.h"

#define PAWMAX   60 // Max 60 mbar
#define PINSPMAX 55 // Max 55 mbar



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
    this->on_Pinsp_valueChanged(1);
    this->on_dPsupp_valueChanged(1);
    this->on_Paw_valueChanged(1);
}


void MainWindow::on_Pinsp_editingFinished()
{
   qDebug() << "Edit Pinps einsteller editingFinished\r\n";

   this->on_Paw_valueChanged(1);
   this->on_PEEP_valueChanged(1);
   this->on_dPsupp_valueChanged(1);
}

void MainWindow::on_Paw_editingFinished()
{
    qDebug() << "Edit Pinps einsteller editingFinished\r\n";

    this->on_Pinsp_valueChanged(1);
    this->on_PEEP_valueChanged(1);
    this->on_dPsupp_valueChanged(1);
}

void MainWindow::on_dPsupp_editingFinished()
{
   qDebug() << "Edit Pinps einsteller editingFinished\r\n";

   this->on_Pinsp_valueChanged(1);
   this->on_PEEP_valueChanged(1);
   this->on_Paw_valueChanged(1);
}

void MainWindow::on_PEEP_valueChanged(int arg1)
{
    qDebug() << "Edit PEEP einsteller Value Changed\r\n";

    // Read out all 3 parameters which are have dependecies for PEEP

    int actualpinsp  = ui->Pinsp->value();
    int actualpaw    = ui->Paw->value();
    int actualdpsupp = ui->dPsupp->value();
    int actualpeep   = ui->PEEP->value();

    qDebug() << "Pinsp ="<<actualpinsp<<"Paw"<<actualpaw<<"dPsupp"<<actualdpsupp;



    // Find the lowest number from
    int lowernumber_peepmax = smallest(actualpinsp-5,actualpaw-1,(actualpaw-actualdpsupp)-1);

    if(lowernumber_peepmax<=0)
    {
       lowernumber_peepmax=0;
    }


    qDebug() << "Smallest is"<<lowernumber_peepmax;

    ui->PEEP->setMaximum(lowernumber_peepmax);
    ui->PEEP->setMinimum(0);

    ui->PEEPMAX->display(lowernumber_peepmax);
}

void MainWindow::on_Pinsp_valueChanged(int arg1)
{


   qDebug() << "Edit Pinps einsteller Value Changed\r\n";

   int actualpinsp  = ui->Pinsp->value();
   int actualpaw    = ui->Paw->value();
   int actualdpsupp = ui->dPsupp->value();
   int actualpeep   = ui->PEEP->value();

   qDebug() << "Pinsp ="<<actualpinsp<<"Paw"<<actualpaw<<"dPsupp"<<actualdpsupp;

   // Find the lowest number from
   int lowernumber = smallest(99,actualpaw-1,PINSPMAX);

   ui->Pinsp->setMaximum(lowernumber);
   ui->Pinsp->setMinimum(actualpeep+5);

}

void MainWindow::on_Paw_valueChanged(int arg1)
{
    qDebug() << "Edit Paw einsteller Value Changed\r\n";

    int actualpinsp  = ui->Pinsp->value();
    int actualpaw    = ui->Paw->value();
    int actualdpsupp = ui->dPsupp->value();
    int actualpeep   = ui->PEEP->value();

     qDebug() << "Pinsp ="<<actualpinsp<<"Paw"<<actualpaw<<"dPsupp"<<actualdpsupp;

     // Find the lowest number from
     int lowernumber = smallest(PAWMAX,PAWMAX,PAWMAX);


     ui->Paw->setMaximum(lowernumber);
     ui->Paw->setMinimum(actualpinsp+1);
}

void MainWindow::on_dPsupp_valueChanged(int arg1)
{

}


