#include "column.h"
#include <QPainter>

Column::Column(QWidget *parent) : QmlObject(parent)
{
    objectType = "Column";

    verticalLayout = new QVBoxLayout(this);
    setLayout(verticalLayout);

    setGeometry(10, 10, 200, 200);
}

void Column::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);

    QRect rect(this->rect().x(),
               this->rect().y(),
               this->rect().width(),
               this->rect().height());

    painter.drawRect(rect);

    QWidget::paintEvent(e);
}

void Column::mousePressEvent(QMouseEvent*)
{
    emit clicked();
}

void Column::mouseMoveEvent(QMouseEvent*)
{
    emit clicked();
}
