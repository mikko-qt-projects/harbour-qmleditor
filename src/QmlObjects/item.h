#ifndef ITEM_H
#define ITEM_H

#include <QWidget>
#include "qmlobject.h"

class Item : public QmlObject
{
    Q_OBJECT
public:
    explicit Item(QWidget *parent = 0);

signals:

public slots:
};

#endif // ITEM_H
