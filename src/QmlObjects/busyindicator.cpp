#include "busyindicator.h"

#include <QPainter>

BusyIndicator::BusyIndicator(QWidget *parent) : QmlObject(parent)
{
    objectType = "BusyIndicator";

    m_dragging_enabled = false;
    m_anchor_fill_enabled = false;
    m_anchor_positions_enabled = false;
    m_x_enabled = false;
    m_y_enabled = false;
    m_width_enabled = false;
    m_height_enabled = false;
    m_x_combobox_enabled = false;
    m_width_combobox_enabled = false;
    m_height_combobox_enabled = false;

    m_busyIndicatorSizeIndex = 2;
    m_runningText = "";

    setGeometry(0, 0, 32, 32);

    QColor c("white");
    QPalette p(palette());
    p.setColor(QPalette::Foreground, c);
    setPalette(p);
}

void BusyIndicator::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);

    QRect rect(this->rect().x(),
               this->rect().y(),
               this->rect().width(),
               this->rect().height());

    painter.drawRect(rect);

    QWidget::paintEvent(e);
}
