#include "verticalscrolldecorator.h"

VerticalScrollDecorator::VerticalScrollDecorator(QWidget *parent) : QmlObject(parent)
{
    objectType = "VerticalScrollDecorator";

    m_flickable = 0;
}
