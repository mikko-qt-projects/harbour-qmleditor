#ifndef PAGE_H
#define PAGE_H

#include <QWidget>
#include "qmlobject.h"

class Page : public QmlObject
{
    Q_OBJECT

public:
    explicit Page(QWidget *parent);
    void mousePressEvent(QMouseEvent*);
    void mouseMoveEvent(QMouseEvent*);

};


#endif // PAGE_H
