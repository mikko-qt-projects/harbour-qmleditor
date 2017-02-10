#ifndef VERTICALSCROLLDECORATOR_H
#define VERTICALSCROLLDECORATOR_H

#include <QWidget>
#include "qmlobject.h"

class VerticalScrollDecorator : public QmlObject
{
    Q_OBJECT
public:
    explicit VerticalScrollDecorator(QWidget *parent = 0);
    void setFlickable(int i) {m_flickable = i;}
    int flickable() {return m_flickable;}

signals:

public slots:

private:
    int m_flickable;            //combobox
};

#endif // VERTICALSCROLLDECORATOR_H
