#include "dockedpanel.h"

#include <QPainter>

DockedPanel::DockedPanel(QWidget *parent) : QmlObject(parent)
{
    objectType = "DockedPanel";

    m_dockIndex = 3;

    m_dragging_enabled = false;
    m_anchor_fill_enabled = false;
    m_anchor_positions_enabled = false;
    m_x_enabled = false;
    m_y_enabled = false;
    m_width_enabled = false;
    m_height_enabled = false;

}

void DockedPanel::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);

    QRect rect(this->rect().x(),
               this->rect().y(),
               this->rect().width(),
               this->rect().height());

    painter.fillRect(rect, QColor("#003f3f"));

    QWidget::paintEvent(e);
}
