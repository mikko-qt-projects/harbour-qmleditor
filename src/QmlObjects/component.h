#ifndef COMPONENT_H
#define COMPONENT_H

#include <QWidget>
#include "qmlobject.h"

class Component : public QmlObject
{
    Q_OBJECT
public:
    explicit Component(QWidget *parent = 0);

signals:

public slots:
};

#endif // COMPONENT_H
