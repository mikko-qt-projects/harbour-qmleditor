#include "iconbutton.h"
#include <QPainter>

IconButton::IconButton(QWidget *parent) : QmlObject(parent)
{
    objectType = "IconButton";

    m_anchor_fill_enabled = false;
    m_width_enabled = false;
    m_height_enabled = false;
    m_width_combobox_enabled = false;
    m_height_combobox_enabled = false;

    m_imageSource = "";

    setGeometry(QRect(0, 0, 88, 88));
}

void IconButton::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);

    QRect rect(this->rect().x(),
               this->rect().y(),
               this->rect().width(),
               this->rect().height());

    painter.drawRect(rect);

    QWidget::paintEvent(e);
}
