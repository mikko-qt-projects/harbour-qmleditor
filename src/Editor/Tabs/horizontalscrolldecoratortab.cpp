#include "horizontalscrolldecoratortab.h"

HorizontalScrollDecoratorTab::HorizontalScrollDecoratorTab(QWidget *parent) : CustomTab(parent)
{
    component = new ComponentComboBox;
    grid->addWidget(new QLabel(tr("flickable")), 0, 0, Qt::AlignTop);
    grid->addWidget(component, 0, 1, Qt::AlignTop);
    grid->addItem(new QSpacerItem(pagewidth/3.6, 50), 0, 2);

}

void HorizontalScrollDecoratorTab::setCurrent(QmlObject *cur)
{
    hScroll = qobject_cast<HorizontalScrollDecorator*>(cur);
    if (hScroll) {
        component->setCurrentIndex(hScroll->flickable());
    }
}
