#include "rectangle.h"

#include <QPainter>
#include <QPen>

Rectangle::Rectangle(QWidget *parent) : QmlObject(parent)
{
    objectType = "Rectangle";
    m_borderSize = 1;
    m_radius = 0;
    m_borderColor = "white";
    m_backgroundColor = "white";

    setGeometry(10, 10, 200, 100);
}

void Rectangle::paintEvent(QPaintEvent *e)
{
    QPen pen;
    pen.setWidth(m_borderSize);
    pen.setColor(m_borderColor);

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setPen(pen);

    QRectF rect(this->rect().x() + m_borderSize / 2,
                this->rect().y() + m_borderSize / 2,
                this->rect().width() - m_borderSize,
                this->rect().height() - m_borderSize);


    if(m_borderSize % 2 == 0)
    {
        painter.drawRoundedRect(rect,
                                m_borderSize,
                                m_borderSize);
    }
    else
    {
        painter.drawRoundedRect(rect.translated(0.5, 0.5),
                                m_radius,
                                m_radius);
    }

    QBrush brush(m_backgroundColor);
    pen.setBrush(brush);
    painter.setBrush(brush);

    if(m_borderSize % 2 == 0)
    {
        painter.drawRoundedRect(rect,
                                m_radius,
                                m_radius);
    }
    else
    {
        painter.drawRoundedRect(rect.translated(0.5, 0.5),
                                m_radius,
                                m_radius);
    }

    QWidget::paintEvent(e);

}
