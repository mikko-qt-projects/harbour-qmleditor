#include "navigatoritems.h"
#include "navigatorwidget.h"
#include <QPainter>
#include <QDebug>

NavigatorItems::NavigatorItems(NavigatorWidget *nlw, QWidget *parent) : QWidget(parent), n(nlw)
{
    QVBoxLayout *navLayout = new QVBoxLayout(this);

    navList = new QListWidget;
    navList->setBackgroundRole(QPalette::Base);
    QPalette pl = navList->palette();
    pl.setColor(QPalette::Base, QColor("#3f3f3f"));
    pl.setColor(QPalette::Text, QColor("white"));
    navList->setAutoFillBackground(true);
    navList->setPalette(pl);

    navLayout->addWidget(navList);

    pageItem = new QListWidgetItem(navList);
    pageItem->setText("page");
    connect(navList, SIGNAL(itemClicked(QListWidgetItem*)), n, SIGNAL(nav_clicked(QListWidgetItem*)));
}

void NavigatorItems::add_object(QmlObject *obj)
{
    QListWidgetItem *newItem = new QListWidgetItem;
    QList<QListWidgetItem*> itemnr = navList->findItems(obj->parent()->objectName(), Qt::MatchExactly);
    newItem->setText(obj->objectName());
    navList->insertItem(navList->row(itemnr[0]) + 1, newItem);
}

void NavigatorItems::remove_object(QmlObject *obj)
{
    qDebug()<<"removes";
    QList<QListWidgetItem*> itemnr = navList->findItems(obj->objectName(), Qt::MatchExactly);
    QListWidgetItem *item = itemnr[0];
    delete item;
}

void NavigatorItems::change_object(QmlObject *obj)
{
    QList<QListWidgetItem*> itemnr = navList->findItems(obj->objectName(), Qt::MatchExactly);
    navList->setCurrentItem(itemnr[0]);
}

void NavigatorItems::change_name(QString name)
{
    navList->currentItem()->setText(name);
}
