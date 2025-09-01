#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "styling.h"
//#include "deck.h"
//#include "hand.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    //, game(nullptr)
{
    ui->setupUi(this);
    ui->labelDealer->setText("");
    ui->labelPlayer->setText("");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_buttonDeal_clicked()
{
    game.reset();
    //ui->viewTextPlayer->setText(QString::fromStdString(game.getPlayer()));
    Styling::colouredSuits(ui->labelPlayer, QString::fromStdString(game.getPlayer()));
    //ui->labelPlayer->setText(QString::fromStdString(game.getPlayer()));
    ui->scoreUser->setText(QString::number(game.scorePlayer()));
    //ui->viewTextDealer->setText("");
    ui->labelDealer->setText("");
    ui->scoreDealer->setText("");
}

void MainWindow::on_buttonHit_clicked()
{
    if (game.status()) {
        game.hit();
        Styling::colouredSuits(ui->labelPlayer, QString::fromStdString(game.getPlayer()));
        //ui->viewTextPlayer->setText(QString::fromStdString(game.getPlayer()));
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
        Styling::colouredSuits(ui->labelDealer, QString::fromStdString(game.getDealer()));
        //ui->viewTextDealer->setText(QString::fromStdString(game.getDealer()));
        ui->scoreDealer->setText(QString::number(game.scoreDealer()));
    }
}

void MainWindow::on_buttonQuit_clicked()
{

}
