#include "mainwindow.h"
#include "./ui_mainwindow.h"
//#include "deck.h"
//#include "hand.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    //, game(nullptr)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_buttonDeal_clicked()
{
    game.reset();
    ui->viewTextPlayer->setText(QString::fromStdString(game.getPlayer()));
    ui->scoreUser->setText(QString::number(game.scorePlayer()));
    ui->viewTextDealer->setText("");
    ui->scoreDealer->setText("");
}

void MainWindow::on_buttonHit_clicked()
{
    if (game.status()) {
        game.hit();
        ui->viewTextPlayer->setText(QString::fromStdString(game.getPlayer()));
        ui->scoreUser->setText(QString::number(game.scorePlayer()));
    }
    if (game.playerBust()) {
        game.stopPlay();
    }
}

void MainWindow::on_buttonStand_clicked()
{
    if (game.status()) {
        game.stand();
        ui->viewTextDealer->setText(QString::fromStdString(game.getDealer()));
        ui->scoreDealer->setText(QString::number(game.scoreDealer()));
    }
}

void MainWindow::on_buttonQuit_clicked()
{

}
