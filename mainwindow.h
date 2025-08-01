#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "blackjack.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_buttonDeal_clicked();

    void on_buttonHit_clicked();

    void on_buttonStand_clicked();

    void on_buttonQuit_clicked();

private:
    Ui::MainWindow *ui;
    BlackJack game;
};
#endif // MAINWINDOW_H
