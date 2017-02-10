#include "geometryproperty.h"
#include <QApplication>
#include <QLabel>

GeometryProperty::GeometryProperty(QWidget *parent) : QWidget(parent)
{
    int pagewidth = qApp->property("pagewidth").toInt();
    int pageheight = qApp->property("pageheight").toInt();

    setFixedHeight(pageheight/9.143);

    xpos = new QSpinBox;
    xpos->setFixedWidth(pagewidth/3.6);
    xpos->setRange(1, 720);
    xpos->setSingleStep(1);

    ypos = new QSpinBox;
    ypos->setFixedWidth(pagewidth/3.6);
    ypos->setRange(1, 1280);
    ypos->setSingleStep(1);

    width = new QSpinBox;
    width->setFixedWidth(pagewidth/3.6);
    width->setRange(1, 720);
    width->setSingleStep(1);

    height = new QSpinBox;
    height->setFixedWidth(pagewidth/3.6);
    height->setRange(1, 1280);
    height->setSingleStep(1);

    QGridLayout *geometrygrid = new QGridLayout(this);
    geometrygrid->addWidget(new QLabel(tr("x")), 0, 0, Qt::AlignTop);
    geometrygrid->addWidget(xpos, 0, 1, Qt::AlignTop);
    geometrygrid->addWidget(new QLabel(tr("y")), 0, 2, Qt::AlignTop);
    geometrygrid->addWidget(ypos, 0, 3, Qt::AlignTop);
    geometrygrid->addWidget(new QLabel(tr("width")), 1, 0, Qt::AlignTop);
    geometrygrid->addWidget(width, 1, 1, Qt::AlignTop);
    geometrygrid->addWidget(new QLabel(tr("height")), 1, 2, Qt::AlignTop);
    geometrygrid->addWidget(height, 1, 3, Qt::AlignTop);
    setLayout(geometrygrid);

    connect(xpos, SIGNAL(valueChanged(int)), this, SLOT(set_xpos(int)));
    connect(ypos, SIGNAL(valueChanged(int)), this, SLOT(set_ypos(int)));
    connect(width, SIGNAL(valueChanged(int)), this, SLOT(set_width(int)));
    connect(height, SIGNAL(valueChanged(int)), this, SLOT(set_height(int)));
}

void GeometryProperty::setCurrent(QmlObject *cur)
{
    current = cur;

    xpos->setValue(current->x());
    ypos->setValue(current->y());
    width->setValue(current->width());
    height->setValue(current->height());

    set_xpos_enabled(current->x_enabled());
    set_ypos_enabled(current->y_enabled());
    set_width_enabled(current->width_enabled());
    set_height_enabled(current->height_enabled());
}

void GeometryProperty::set_xpos(int x)
{
    current->setGeometry(x, current->y(), current->width(), current->height());
}

void GeometryProperty::set_ypos(int y)
{
    current->setGeometry(current->x(), y, current->width(), current->height());
}

void GeometryProperty::set_width(int w)
{
    current->setGeometry(current->x(), current->y(), w, current->height());
}

void GeometryProperty::set_height(int h)
{
    current->setGeometry(current->x(), current->y(), current->width(), h);
}

void GeometryProperty::set_xpos_enabled(bool b)
{
    xpos->setEnabled(b);
}

void GeometryProperty::set_ypos_enabled(bool b)
{
    ypos->setEnabled(b);
}

void GeometryProperty::set_width_enabled(bool b)
{
    width->setEnabled(b);
}

void GeometryProperty::set_height_enabled(bool b)
{
    height->setEnabled(b);
}
