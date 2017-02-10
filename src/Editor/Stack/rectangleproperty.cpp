#include "rectangleproperty.h"
#include "../editorwidget.h"
#include <QGridLayout>
#include <QLabel>
#include <QStyleOption>

RectangleProperty::RectangleProperty(EditorWidget *ew, QWidget *parent) : QWidget(parent), e(ew)
{
    setMinimumHeight(660);
    QPalette p(palette());
    p.setColor(QPalette::Background, QColor("#3f3f3f"));
    p.setColor(QPalette::Foreground, QColor("white"));
    setAutoFillBackground(true);
    setPalette(p);

    QWidget *colorwidget = new QWidget;
    colorwidget->setMinimumHeight(390);

    picker = new ColorPickerWidget;
    bgcheck = new QCheckBox(tr("Background"));
    bgcheck->setChecked(true);
    bordercheck = new QCheckBox(tr("Border"));
    bordercheck->setChecked(false);

    QGridLayout *colorgrid = new QGridLayout;
    colorgrid->addWidget(picker, 0, 0, 4, 4);
    colorgrid->addWidget(bgcheck, 4, 0);
    colorgrid->addWidget(bordercheck, 4, 2);
    colorwidget->setLayout(colorgrid);

    QWidget *borderwidget = new QWidget;
    borderwidget->setMinimumHeight(190);

    border = new QSpinBox;
    border->setFixedWidth(200);
    border->setRange(0, 100);
    border->setSingleStep(1);

    radius = new QSpinBox;
    radius->setFixedWidth(200);
    radius->setRange(0, 360);

    QGridLayout *bordergrid = new QGridLayout;
    bordergrid->addWidget(new QLabel(tr("Border ")), 0, 0, Qt::AlignTop);
    bordergrid->addWidget(border, 0, 1, Qt::AlignTop);
    bordergrid->addWidget(new QLabel(tr("Radius ")), 0, 2, Qt::AlignTop);
    bordergrid->addWidget(radius, 0, 3, Qt::AlignTop);
    borderwidget->setLayout(bordergrid);

    QVBoxLayout *verticalLayout = new QVBoxLayout;
    verticalLayout->addWidget(colorwidget);
    verticalLayout->addWidget(borderwidget);

    setLayout(verticalLayout);

    connect(bgcheck, SIGNAL(clicked(bool)),             this, SLOT(bgcheck_clicked(bool)));
    connect(bordercheck, SIGNAL(clicked(bool)),         this, SLOT(bordercheck_clicked(bool)));
    connect(picker, SIGNAL(colortoparent(QColor)),      this, SLOT(ColorChanged(QColor)));
    connect(border, SIGNAL(valueChanged(int)),          this, SLOT(changeBorderSize(int)));
    connect(radius, SIGNAL(valueChanged(int)),          this, SLOT(changeRadius(int)));
}

void RectangleProperty::paintEvent(QPaintEvent *)
{
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}

void RectangleProperty::setCurrent(QmlObject *cur)
{
    rectangle = qobject_cast<Rectangle*>(cur);

    if (rectangle != NULL) {
        border->setValue(rectangle->borderSize());
        setColors(rectangle->backgroundColor(), rectangle->borderColor());
        radius->setValue(rectangle->radius());
    }
}

void RectangleProperty::changeBGColor(QColor c)
{
    rectangle->setBackgroundColor(c);
    rectangle->update();
    e->setCurrent(rectangle);
}

void RectangleProperty::changeBorderColor(QColor c)
{
    rectangle->setBorderColor(c);
    rectangle->update();
    e->setCurrent(rectangle);
}

void RectangleProperty::changeBorderSize(int s)
{
    rectangle->setBorderSize(s);
    rectangle->update();
    e->setCurrent(rectangle);
}

void RectangleProperty::changeRadius(int s)
{
    rectangle->setRadius(s);
    rectangle->update();
    e->setCurrent(rectangle);
}

void RectangleProperty::setColors(QColor bg, QColor border)
{
    if (bgcheck->isChecked()) {
        picker->setColor(bg);
    } else {
        picker->setColor(border);
    }
}

void RectangleProperty::ColorChanged(QColor c)
{
    if (bgcheck->isChecked()) {
        changeBGColor(c);
    } else {
        changeBorderColor(c);
    }
}

void RectangleProperty::bgcheck_clicked(bool b)
{
    bordercheck->setChecked(!b);
    e->setCurrent(rectangle);
}

void RectangleProperty::bordercheck_clicked(bool b)
{
    bgcheck->setChecked(!b);
    e->setCurrent(rectangle);
}
