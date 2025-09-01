#include "showresults.h"


void ShowResults::showResults(QWidget* parent, const QString& resultText) {
    QMessageBox msgBox(parent);
    msgBox.setWindowTitle("Game Results");
    msgBox.setText(resultText);
    msgBox.setIconPixmap(QPixmap()); // Sets a blank icon
    msgBox.setStandardButtons(QMessageBox::Ok);
    QPushButton* restartButton = msgBox.addButton("Start Over", QMessageBox::ActionRole);
    msgBox.exec(); // Shows the popup

    if (msgBox.clickedButton() == restartButton) {
        game.reset(); // Call your restart function here
    }
}
