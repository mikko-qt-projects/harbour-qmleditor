#include "verticalscrolldecoratortab.h"

VerticalScrollDecoratorTab::VerticalScrollDecoratorTab(QWidget *parent) : CustomTab(parent)
{
    component = new ComponentComboBox;
    grid->addWidget(new QLabel(tr("flickable")), 0, 0, Qt::AlignTop);
    grid->addWidget(component, 0, 1, Qt::AlignTop);
    grid->addItem(new QSpacerItem(pagewidth/3.6, 50), 0, 2);

}

void VerticalScrollDecoratorTab::setCurrent(QmlObject *cur)
{
    vScroll = qobject_cast<VerticalScrollDecorator*>(cur);
    if (vScroll) {
        component->setCurrentIndex(vScroll->flickable());
    }
}
