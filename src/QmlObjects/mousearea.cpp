#include "mousearea.h"

MouseArea::MouseArea(QWidget *parent) : QmlObject(parent)
{
    objectType = "MouseArea";
    m_mouseAreaEnabled = true;
    m_mouseAreaHoverEnabled = false;
    m_action = 0;
    m_actionText = "";
}
