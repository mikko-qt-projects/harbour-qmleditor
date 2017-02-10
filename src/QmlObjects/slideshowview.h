#ifndef SLIDESHOWVIEW_H
#define SLIDESHOWVIEW_H

#include <QWidget>
#include "qmlobject.h"

class SlideshowView : public QmlObject
{
    Q_OBJECT
public:
    explicit SlideshowView(QWidget *parent = 0);

signals:

public slots:
};

#endif // SLIDESHOWVIEW_H
