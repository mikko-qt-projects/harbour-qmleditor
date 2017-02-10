#include "backgrounditem.h"

BackgroundItem::BackgroundItem(QWidget *parent) : MouseArea(parent)
{
    objectType = "BackgroundItem";
    m_contentHeight = 0;
    m_contentWidth = 0;

    setGeometry(0, 0, 200, 200);
}
