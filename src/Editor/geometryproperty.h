#ifndef GEOMETRYITEMS_H
#define GEOMETRYITEMS_H

#include <QLineEdit>
#include <QWidget>
#include <QGroupBox>
#include <QGridLayout>
#include <QSpinBox>
#include "../QmlObjects/qmlobject.h"

class GeometryProperty : public QWidget
{
    Q_OBJECT
public:
    explicit GeometryProperty(QWidget *parent = 0);
    void setCurrent(QmlObject *cur);

    void set_xpos_enabled(bool b);
    void set_ypos_enabled(bool b);
    void set_width_enabled(bool b);
    void set_height_enabled(bool b);

signals:

public slots:
    void set_xpos(int x);
    void set_ypos(int y);
    void set_width(int w);
    void set_height(int h);

private:
    QmlObject *current;
    QSpinBox *xpos;
    QSpinBox *ypos;
    QSpinBox *width;
    QSpinBox *height;
};

#endif // GEOMETRYITEMS_H
