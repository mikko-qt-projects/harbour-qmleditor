#ifndef IMAGE_H
#define IMAGE_H

#include <QWidget>
#include "qmlobject.h"

class Image : public QmlObject
{
    Q_OBJECT
public:
    explicit Image(QWidget *parent = 0);

signals:

public slots:
};

#endif // IMAGE_H
