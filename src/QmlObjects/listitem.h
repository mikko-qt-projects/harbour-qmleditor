#ifndef LISTITEM_H
#define LISTITEM_H

#include <QWidget>
#include "qmlobject.h"

class ListItem : public QmlObject
{
    Q_OBJECT
public:
    explicit ListItem(QWidget *parent = 0);

signals:

public slots:
};

#endif // LISTITEM_H
