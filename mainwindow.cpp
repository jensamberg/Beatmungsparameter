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

    ui->PEEPMINLCD->setPalette(Qt::green);
    ui->PEEPMAXLCD->setPalette(Qt::red);

    ui->PINSPMINLCD->setPalette(Qt::green);
    ui->PINSPMAXLCD->setPalette(Qt::red);

    ui->PAWMINLCD->setPalette(Qt::green);
    ui->PAWMAXLCD->setPalette(Qt::red);

    ui->DSUPPMINLCD->setPalette(Qt::green);
    ui->DSUPPMAXLCD->setPalette(Qt::red);
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

    this->readOutActualValues(1);

    qDebug() << "Pinsp ="<<mActualpinsp<<"Paw"<<mActualpaw<<"dPsupp"<<mActualdpsupp;

    // Find the lowest number from
    int lowernumber_peepmax = smallest(mActualpinsp-5,mActualpaw-1,(mActualpaw-mActualdpsupp)-1);

    qDebug() << "Smallest is"<<lowernumber_peepmax;

    this->mMAXPEEP = lowernumber_peepmax;
    this->mMINPEEP = 0;


    ui->PEEP->setMaximum(this->mMAXPEEP);
    ui->PEEP->setMinimum(this->mMINPEEP);
}

void MainWindow::on_Pinsp_valueChanged(int arg1)
{


   qDebug() << "Edit Pinps einsteller Value Changed\r\n";

   this->readOutActualValues(1);

   qDebug() << "Pinsp ="<<mActualpinsp<<"Paw"<<mActualpaw<<"dPsupp"<<mActualdpsupp;

   // Find the lowest number from
   int lowernumber = smallest(99,mActualpaw-1,PINSPMAX);

   ui->Pinsp->setMaximum(lowernumber);
   ui->Pinsp->setMinimum(mActualpeep+5);

}

void MainWindow::on_Paw_valueChanged(int arg1)
{
    qDebug() << "Edit Paw einsteller Value Changed\r\n";

    this->readOutActualValues(1);

    qDebug() << "Pinsp ="<<mActualpinsp<<"Paw"<<mActualpaw<<"dPsupp"<<mActualdpsupp;

    // Find the lowest number from
    int lowernumber = smallest(PAWMAX,PAWMAX,PAWMAX);


    ui->Paw->setMaximum(lowernumber);
    ui->Paw->setMinimum(mActualpinsp+1);
}

void MainWindow::on_dPsupp_valueChanged(int arg1)
{

}

void MainWindow::readOutActualValues(int arg1)
{
     qDebug() << "arg 1\r\n"<<arg1;

     mActualpinsp  = ui->Pinsp->value();
     mActualpaw    = ui->Paw->value();
     mActualdpsupp = ui->dPsupp->value();
     mActualpeep   = ui->PEEP->value();

}

void MainWindow::refreshMINMAXLcdDisplays(int arg1)
{
    qDebug() << "arg 1\r\n"<<arg1;

    ui->PEEPMAXLCD->display((int)this->mMAXPEEP);
    ui->PEEPMINLCD->display((int)this->mMINPEEP);

    ui->PINSPMAXLCD->display((int)this->mMAXPINSP);
    ui->PINSPMINLCD->display((int)this->mMINPINSP);

    ui->PAWMAXLCD->display((int)this->mMAXPAW);
    ui->PAWMINLCD->display((int)this->mMINPAW);

    ui->DSUPPMAXLCD->display((int)this->mMAXDPSUPP);
    ui->DSUPPMINLCD->display((int)this->mMINDPSUPP);

}


