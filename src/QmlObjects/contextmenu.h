#ifndef CONTEXTMENU_H
#define CONTEXTMENU_H

#include <QWidget>
#include "qmlobject.h"

class ContextMenu : public QmlObject
{
    Q_OBJECT
public:
    explicit ContextMenu(QWidget *parent = 0);

signals:

public slots:
};

#endif // CONTEXTMENU_H
