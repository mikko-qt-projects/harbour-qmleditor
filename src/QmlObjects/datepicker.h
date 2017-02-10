#ifndef DATEPICKER_H
#define DATEPICKER_H

#include <QWidget>
#include "qmlobject.h"

class DatePicker : public QmlObject
{
    Q_OBJECT
public:
    explicit DatePicker(QWidget *parent = 0);

signals:

public slots:
};

#endif // DATEPICKER_H
