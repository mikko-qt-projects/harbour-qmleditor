#include "horizontalscrolldecorator.h"

HorizontalScrollDecorator::HorizontalScrollDecorator(QWidget *parent) : QmlObject(parent)
{
    objectType = "HorizontalScrollDecorator";

    m_flickable = 0;
}
