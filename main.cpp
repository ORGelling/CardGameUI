#include "mainwindow.h"
#include "cards.h"
#include "deck.h"
#include "hand.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
