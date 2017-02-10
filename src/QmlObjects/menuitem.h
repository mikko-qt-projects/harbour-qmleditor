#ifndef MENUITEM_H
#define MENUITEM_H

#include <QWidget>
#include "qmlobject.h"

class MenuItem : public QmlObject
{
    Q_OBJECT
public:
    explicit MenuItem(QWidget *parent = 0);

signals:

public slots:
};

#endif // MENUITEM_H
