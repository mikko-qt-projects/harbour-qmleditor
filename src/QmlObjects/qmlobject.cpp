#include "qmlobject.h"
#include <QPainter>
#include <QStyleOption>

QmlObject::QmlObject(QWidget *parent) : QWidget(parent)
{   
    m_anchor_fill_checked = false;
    m_anchor_horizontalCenter_checked = false;
    m_anchor_verticalCenter_checked = false;
    m_anchor_top_checked = false;
    m_anchor_bottom_checked = false;
    m_anchor_left_checked = false;
    m_anchor_right_checked = false;

    m_x_enabled = true;
    m_y_enabled = true;
    m_width_enabled = true;
    m_height_enabled = true;

    m_x_combobox_enabled = true;
    m_width_combobox_enabled = true;
    m_height_combobox_enabled = true;

    m_x_combobox_index = 0;
    m_width_combobox_index = 0;
    m_height_combobox_index = 0;

    m_dragging_enabled = true;

    m_anchor_top_margin = 0;
    m_anchor_bottom_margin = 0;
    m_anchor_left_margin = 0;
    m_anchor_right_margin = 0;
    m_anchor_horizontalCenter_margin = 0;
    m_anchor_verticalCenter_margin = 0;

    m_anchor_fill_enabled = true;
    m_anchor_positions_enabled = true;
}

void QmlObject::paintEvent(QPaintEvent *)
{
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}

void QmlObject::mousePressEvent(QMouseEvent *event)
{
    offset = event->pos();
    emit clicked();
}

void QmlObject::mouseMoveEvent(QMouseEvent *event)
{
    if (dragging_enabled()) {
        this->move(mapToParent(event->pos() - offset));
    }
}

void QmlObject::mouseReleaseEvent(QMouseEvent*)
{
    if (dragging_enabled()) {
        emit holdandpressed(this);
    }
}

