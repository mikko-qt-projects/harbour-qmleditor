#ifndef SILICAFLICKABLE_H
#define SILICAFLICKABLE_H

#include <QWidget>
#include "qmlobject.h"

class SilicaFlickable : public QmlObject
{
    Q_OBJECT
public:
    explicit SilicaFlickable(QWidget *parent = 0);

signals:

public slots:
};

#endif // SILICAFLICKABLE_H
