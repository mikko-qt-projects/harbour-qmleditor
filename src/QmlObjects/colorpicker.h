#ifndef COLORPICKER_H
#define COLORPICKER_H

#include <QWidget>
#include "qmlobject.h"

class ColorPicker : public QmlObject
{
    Q_OBJECT
public:
    explicit ColorPicker(QWidget *parent = 0);

signals:

public slots:
};

#endif // COLORPICKER_H
