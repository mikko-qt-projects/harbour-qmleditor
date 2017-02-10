#ifndef NAVIGATORITEMS_H
#define NAVIGATORITEMS_H

#include <QGroupBox>
#include <QWidget>
#include <QVBoxLayout>
#include <QListWidget>
#include "../QmlObjects/qmlobject.h"

class NavigatorWidget;

class NavigatorItems : public QWidget
{
    Q_OBJECT
public:
    explicit NavigatorItems(NavigatorWidget *nlw, QWidget *parent = 0);

signals:

public slots:
    void add_object(QmlObject *obj);
    void remove_object(QmlObject *obj);
    void change_object(QmlObject *obj);
    void change_name(QString name);

private:
    NavigatorWidget *n;
    QListWidget *navList;
    QListWidgetItem *pageItem;
};

#endif // NAVIGATORITEMS_H
