#ifndef TOUCHBLOCKER_H
#define TOUCHBLOCKER_H

#include <QWidget>
#include "qmlobject.h"

class TouchBlocker : public QmlObject
{
    Q_OBJECT
public:
    explicit TouchBlocker(QWidget *parent = 0);

signals:

public slots:
};

#endif // TOUCHBLOCKER_H
