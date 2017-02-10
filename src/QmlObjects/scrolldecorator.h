#ifndef SCROLLDECORATOR_H
#define SCROLLDECORATOR_H

#include <QWidget>
#include "qmlobject.h"

class ScrollDecorator : public QmlObject
{
    Q_OBJECT
public:
    explicit ScrollDecorator(QWidget *parent = 0);

signals:

public slots:
};

#endif // SCROLLDECORATOR_H
