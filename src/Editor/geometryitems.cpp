#include "geometryitems.h"
#include "editorwidget.h"

#include <QLabel>

GeometryItems::GeometryItems(EditorWidget *plw, QWidget *parent) : QGroupBox(parent), p(plw)
{
    QGroupBox *geometry = new QGroupBox(tr("Geometry"), this);
    setMinimumHeight(200);
    setMinimumWidth(640);
    xpos = new QLineEdit;
    xpos->setFixedWidth(200);
    ypos = new QLineEdit;
    ypos->setFixedWidth(200);
    width = new QLineEdit;
    width->setFixedWidth(200);
    height = new QLineEdit;
    height->setFixedWidth(200);

    QGridLayout *geometrygrid = new QGridLayout(geometry);
    geometrygrid->addWidget(new QLabel(tr("x ")), 0, 0, Qt::AlignTop);
    geometrygrid->addWidget(xpos, 0, 1, Qt::AlignTop);
    geometrygrid->addWidget(new QLabel(tr("y ")), 0, 2, Qt::AlignTop);
    geometrygrid->addWidget(ypos, 0, 3, Qt::AlignTop);
    geometrygrid->addWidget(new QLabel(tr("width ")), 1, 0, Qt::AlignTop);
    geometrygrid->addWidget(width, 1, 1, Qt::AlignTop);
    geometrygrid->addWidget(new QLabel(tr("height ")), 1, 2, Qt::AlignTop);
    geometrygrid->addWidget(height, 1, 3, Qt::AlignTop);
    setLayout(geometrygrid);

    connect(xpos, SIGNAL(textChanged(QString)), p, SLOT(x_changed(QString)));
    connect(ypos, SIGNAL(textChanged(QString)), p, SLOT(y_changed(QString)));
    connect(width, SIGNAL(textChanged(QString)), p, SLOT(width_changed(QString)));
    connect(height, SIGNAL(textChanged(QString)), p, SLOT(height_changed(QString)));
}

void GeometryItems::setXpos(int x)
{
    xpos->setText(QString::number(x));
}

void GeometryItems::setYpos(int y)
{
    ypos->setText(QString::number(y));
}

void GeometryItems::setWidth(int w)
{
    width->setText(QString::number(w));
}

void GeometryItems::setHeight(int h)
{
    height->setText(QString::number(h));
}

void GeometryItems::setXposVisible(bool b)
{
    xpos->setVisible(b);
}

void GeometryItems::setYposVisible(bool b)
{
    ypos->setVisible(b);
}

void GeometryItems::setWidthVisible(bool b)
{
    width->setVisible(b);
}

void GeometryItems::setHeightVisible(bool b)
{
    height->setVisible(b);
}
