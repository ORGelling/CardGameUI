#include "styling.h"

#include <QLabel>
#include <QLineEdit>
#include <QString>
#include <QRegularExpression>

// Example: In your widget class or in a utility namespace/class
void Styling::colouredSuits(QLabel* label, const QString& cardText) {
    // Replace hearts/diamonds with red span, spades/clubs as normal (you can style them too if needed)
    QRegularExpression redSuitsRegex(R"((\b(?:[AKQJ]|10|[2-9])([HD])))");
    QRegularExpression blackSuitsRegex(R"((\b(?:[AKQJ]|10|[2-9])([CS])))");
    QString styled = cardText;
    styled.replace(redSuitsRegex, "<span style=\"color:red;\">\\1</span>");
    // styled.replace(QRegularExpression("([HD])"), "<span style=\"color:red;\">\\1</span>");
    // styled.replace(QRegularExpression("([♥♦])"), "<span style=\"color:red;\">\\1</span>");
    styled.replace(blackSuitsRegex, "<span style=\"color:black;\">\\1</span>");

    // Set HTML text (need to use setTextFormat and setText)
    label->setTextFormat(Qt::RichText);
    label->setText(styled);
}
