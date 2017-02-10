#ifndef SCREENWIDGET_H
#define SCREENWIDGET_H

#include <QListWidget>
#include <QWidget>
#include <QPaintEvent>
#include "QmlObjects/qmlobjects.h"

class ScreenWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ScreenWidget(QWidget *parent = 0);
    //void paintEvent(QPaintEvent *);

signals:
    void qmlobject_to_nav(QmlObject *obj);
    void nav_changed(QmlObject *obj);
    void current_changed(QmlObject *cur);

public slots:
    void set_by_nav(QListWidgetItem *item);
    void set_by_click();
    void change_current(QmlObject *newcurrent);
    void set_qmlobject(QmlObject *obj);

private:
    QmlObject *page;
    QmlObject *current;
    int i;
};


#endif // SCREENWIDGET_H
