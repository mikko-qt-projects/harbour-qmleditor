#include "page.h"

Page::Page(QWidget *parent) : QmlObject(parent)
{
    setMinimumWidth(720);
    setGeometry(0, 0, 720, 1220);
    setObjectName("page");

    objectType = "Page";

    m_x_enabled = false;
    m_y_enabled = false;
    m_width_enabled = false;
    m_height_enabled = false;

    m_dragging_enabled = false;

    m_anchor_fill_enabled = false;
    m_anchor_positions_enabled = false;

    QPalette pal;
    pal.setBrush(backgroundRole(), QBrush(QImage(":/res/images/page-background.jpg")));
    setAutoFillBackground(true);
    setPalette(pal);
}

void Page::mousePressEvent(QMouseEvent*)
{
    emit clicked();
}

void Page::mouseMoveEvent(QMouseEvent*)
{
    emit clicked();
}
