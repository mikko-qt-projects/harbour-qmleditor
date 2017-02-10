#include "navigatorwidget.h"

NavigatorWidget::NavigatorWidget(QWidget *parent) : QWidget(parent)
{
    basic = new BasicTab(this);
    silicaView = new SilicaViewTab(this);
    silicaControl = new SilicaControlTab(this);
    silicaItem = new SilicaItemTab(this);
    silicaText = new SilicaTextTab(this);
    silicaMenu = new SilicaMenuTab(this);

    tabWidget = new QTabWidget;

    QPalette tpal = tabWidget->tabBar()->palette();
    tpal.setColor(QPalette::Button, QColor("#333333"));
    tpal.setColor(QPalette::ButtonText, QColor("white"));
    tabWidget->tabBar()->setAutoFillBackground(true);
    tabWidget->tabBar()->setPalette(tpal);

    tabWidget->addTab(silicaView, tr("View"));
    tabWidget->addTab(silicaControl, tr("Control"));
    tabWidget->addTab(silicaItem, tr("Item"));
    tabWidget->addTab(silicaText, tr("Text"));
    tabWidget->addTab(silicaMenu, tr("Menu"));
    tabWidget->addTab(basic, tr("Basic"));

    verticalLayout = new QVBoxLayout(this);
    navItems = new NavigatorItems(this);
    verticalLayout->addWidget(navItems);
    verticalLayout->addWidget(tabWidget);

    connect(this, SIGNAL(name_changed(QString)),            navItems, SLOT(change_name(QString)));
    connect(this, SIGNAL(remove_nav_item(QmlObject*)),      navItems, SLOT(remove_object(QmlObject*)));
}

void NavigatorWidget::add_nav_item(QmlObject *obj)
{  
    navItems->add_object(obj);
}

void NavigatorWidget::nav_changed(QmlObject *obj)
{
    navItems->change_object(obj);
}

void NavigatorWidget::qmlobject_pressed(QmlObject *obj)
{
    emit qmlobject_signal(obj);
}


