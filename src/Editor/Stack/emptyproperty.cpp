#include "emptyproperty.h"

#include <QPainter>
#include <QStyleOption>

EmptyProperty::EmptyProperty(QWidget *parent) : QWidget(parent)
{
    setMinimumHeight(660);
    QPalette p(palette());
    p.setColor(QPalette::Background, QColor("#3f3f3f"));
    p.setColor(QPalette::Foreground, QColor("white"));
    setAutoFillBackground(true);
    setPalette(p);
}

void EmptyProperty::paintEvent(QPaintEvent *)
{
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}
