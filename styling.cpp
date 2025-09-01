#include "styling.h"

#include <QLabel>
#include <QLineEdit>
#include <QString>
#include <QRegularExpression>

void Styling::colouredSuits(QLabel* label, const QString& cardText) {

    QRegularExpression redSuitsRegex(R"((\b(?:[AKQJ]|10|[2-9])([HD])))");
    QRegularExpression blackSuitsRegex(R"((\b(?:[AKQJ]|10|[2-9])([CS])))");

    QString styled = cardText;

    styled.replace(redSuitsRegex, "<span style=\"color:red;\">\\1</span>");
    styled.replace(blackSuitsRegex, "<span style=\"color:black;\">\\1</span>");

    label->setTextFormat(Qt::RichText);
    label->setText(styled);
}
