#include "silicamenutab.h"
#include "../navigatorwidget.h"

SilicaMenuTab::SilicaMenuTab(NavigatorWidget *nw, QWidget *parent) : QWidget(parent), n(nw)
{
    contextMenu_id = 0;
    menuItem_id = 0;
    menuLabel_id = 0;
    pullDownMenu_id = 0;
    pushUpMenu_id = 0;

    QPalette p(palette());
    p.setColor(QPalette::Background, QColor("#3f3f3f"));
    setAutoFillBackground(true);
    setPalette(p);

    contextMenu_btn = new CustomButton("Context\nMenu");
    menuItem_btn = new CustomButton("Menu\nItem");
    menuLabel_btn = new CustomButton("Menu\nLabel");
    pullDownMenu_btn = new CustomButton("PullDown\nMenu");
    pushUpMenu_btn = new CustomButton("PushUp\nMenu");

    QGridLayout *grid = new QGridLayout;
    grid->addWidget(contextMenu_btn, 0, 0);
    grid->addWidget(menuItem_btn, 0, 1);
    grid->addWidget(menuLabel_btn, 0, 2);
    grid->addWidget(pullDownMenu_btn, 0, 3);
    grid->addWidget(pushUpMenu_btn, 1, 0);
    grid->addItem(new QSpacerItem(160, 160), 2, 0);
    setLayout(grid);

    connect(contextMenu_btn, SIGNAL(pressed()),     this, SLOT(contextMenuPressed()));
    connect(menuItem_btn, SIGNAL(pressed()),        this, SLOT(menuItemPressed()));
    connect(menuLabel_btn, SIGNAL(pressed()),       this, SLOT(menuLabelPressed()));
    connect(pullDownMenu_btn, SIGNAL(pressed()),    this, SLOT(pullDownMenuPressed()));
    connect(pushUpMenu_btn, SIGNAL(pressed()),      this, SLOT(pushUpMenuOressed()));

    connect(this, SIGNAL(contextMenuSignal(QmlObject*)),    n, SLOT(qmlobject_pressed(QmlObject*)));
    connect(this, SIGNAL(menuItemSignal(QmlObject*)),       n, SLOT(qmlobject_pressed(QmlObject*)));
    connect(this, SIGNAL(menuLabelSignal(QmlObject*)),      n, SLOT(qmlobject_pressed(QmlObject*)));
    connect(this, SIGNAL(pullDownMenuSignal(QmlObject*)),   n, SLOT(qmlobject_pressed(QmlObject*)));
    connect(this, SIGNAL(pushUpMenuSignal(QmlObject*)),     n, SLOT(qmlobject_pressed(QmlObject*)));

}

void SilicaMenuTab::contextMenuPressed()
{
    QmlObject *contextMenu = new ContextMenu;
    contextMenu->setObjectName("contextMenu_" + QString::number(contextMenu_id));
    contextMenu_id++;
    emit contextMenuSignal(contextMenu);
}

void SilicaMenuTab::menuItemPressed()
{
    QmlObject *menuItem = new MenuItem;
    menuItem->setObjectName("menuItem_" + QString::number(menuItem_id));
    menuItem_id++;
    emit menuItemSignal(menuItem);
}

void SilicaMenuTab::menuLabelPressed()
{
    QmlObject *menuLabel = new MenuLabel;
    menuLabel->setObjectName("menuLabel_" + QString::number(menuLabel_id));
    menuLabel_id++;
    emit menuLabelSignal(menuLabel);
}

void SilicaMenuTab::pullDownMenuPressed()
{
    QmlObject *pullDownMenu = new PullDownMenu;
    pullDownMenu->setObjectName("pullDownMenu_" + QString::number(pullDownMenu_id));
    pullDownMenu_id++;
    emit pullDownMenuSignal(pullDownMenu);
}

void SilicaMenuTab::pushUpMenuOressed()
{
    QmlObject *pushUpMenu = new PushUpMenu;
    pushUpMenu->setObjectName("pushUpMenu_" + QString::number(pushUpMenu_id));
    pushUpMenu_id++;
    emit pushUpMenuSignal(pushUpMenu);
}
