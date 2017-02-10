#include "row.h"

Row::Row(QWidget *parent) : QmlObject(parent)
{
    objectType = "Row";

    horizontalLayout = new QHBoxLayout(this);
    setLayout(horizontalLayout);
}

void Row::mousePressEvent(QMouseEvent*)
{
    emit clicked();
}

void Row::mouseMoveEvent(QMouseEvent*)
{
    emit clicked();
}
