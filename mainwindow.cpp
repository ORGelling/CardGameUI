#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_buttonDeal_clicked()
{

}


void MainWindow::on_buttonHit_clicked()
{

}


void MainWindow::on_buttonStand_clicked()
{

}


void MainWindow::on_buttonQuit_clicked()
{

}

