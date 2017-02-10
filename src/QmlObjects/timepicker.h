#ifndef TIMEPICKER_H
#define TIMEPICKER_H

#include <QWidget>
#include "qmlobject.h"

class TimePicker : public QmlObject
{
    Q_OBJECT
public:
    explicit TimePicker(QWidget *parent = 0);

signals:

public slots:
};

#endif // TIMEPICKER_H
