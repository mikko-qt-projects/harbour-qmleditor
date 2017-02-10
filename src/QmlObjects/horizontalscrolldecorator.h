#ifndef HORIZONTALSCROLLDECORATOR_H
#define HORIZONTALSCROLLDECORATOR_H

#include <QWidget>
#include "qmlobject.h"

class HorizontalScrollDecorator : public QmlObject
{
    Q_OBJECT
public:
    explicit HorizontalScrollDecorator(QWidget *parent = 0);
    void setFlickable(int i) {m_flickable = i;}
    int flickable() {return m_flickable;}

signals:

public slots:

private:
    int m_flickable;        //combobox
};

#endif // HORIZONTALSCROLLDECORATOR_H
