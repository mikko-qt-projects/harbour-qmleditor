#ifndef NAVIGATORLIBRARYWIDGET_H
#define NAVIGATORLIBRARYWIDGET_H

#include <QTabWidget>
#include <QWidget>
#include <QPointer>
#include <QHBoxLayout>
#include <QGroupBox>
#include <QListWidget>
#include "../QmlObjects/qmlobject.h"
#include "navigatoritems.h"
#include "Tabs/basictab.h"
#include "Tabs/silicaviewtab.h"
#include "Tabs/silicacontroltab.h"
#include "Tabs/silicaitemtab.h"
#include "Tabs/silicatexttab.h"
#include "Tabs/silicamenutab.h"

class NavigatorWidget : public QWidget
{
    Q_OBJECT

public:
    explicit NavigatorWidget(QWidget *parent = 0);

signals:
    void nav_clicked(QListWidgetItem *item);
    void qmlobject_signal(QmlObject *obj);
    void name_changed(QString s);
    void remove_nav_item(QmlObject *obj);

public slots:
    void add_nav_item(QmlObject *obj);
    void nav_changed(QmlObject *obj);
    void qmlobject_pressed(QmlObject *obj);

private:
    QVBoxLayout *verticalLayout;
    NavigatorItems *navItems;

    QTabWidget *tabWidget;
    BasicTab *basic;
    SilicaViewTab *silicaView;
    SilicaControlTab *silicaControl;
    SilicaItemTab *silicaItem;
    SilicaTextTab *silicaText;
    SilicaMenuTab *silicaMenu;

};

#endif // NAVIGATORLIBRARYWIDGET_H
