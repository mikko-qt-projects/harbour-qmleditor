#include "drawer.h"

Drawer::Drawer(QWidget *parent) : QmlObject(parent)
{
    objectType = "Drawer";

    m_open = true;
    m_background = 0;
    m_foreground = 0;
    m_dock = 0;
}
