#include "custombutton.h"
#include <QScreen>
#include <QApplication>

CustomButton::CustomButton(QString text, QWidget *parent) : QPushButton(parent)
{
    int pagewidth = qApp->property("pagewidth").toInt();
    int pageheight = qApp->property("pageheight").toInt();

    setFixedSize(pagewidth/4.5, pageheight/8);
    setText(text);

    QFont font;
    font.setPointSize(pageheight/60);
    setFont(font);

    QPalette p = this->palette();
    p.setColor(QPalette::Button, QColor("#292929"));
    p.setColor(QPalette::ButtonText, QColor("white"));
    setAutoFillBackground(true);
    setPalette(p);
}
