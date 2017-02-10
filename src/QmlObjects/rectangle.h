#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "qmlobject.h"


class Rectangle : public QmlObject
{
    Q_OBJECT

public:
    explicit Rectangle(QWidget *parent = 0);
    void paintEvent(QPaintEvent *e);

    void setRadius(int i) {m_radius = i;}
    void setBorderSize(int i) {m_borderSize = i;}
    void setBorderColor(QColor c) {m_borderColor = c;}
    void setBackgroundColor(QColor c) {m_backgroundColor = c;}

    int radius() {return m_radius;}
    int borderSize() {return m_borderSize;}
    QColor borderColor() {return m_borderColor;}
    QColor backgroundColor() {return m_backgroundColor;}

protected:
    int m_radius;
    int m_borderSize;
    QColor m_borderColor;
    QColor m_backgroundColor;

};


#endif // RECTANGLE_H
