#include "rectangletab.h"
#include <QGridLayout>
#include <QLabel>


RectangleTab::RectangleTab(QWidget *parent) : CustomTab(parent)
{
    widget->setFixedHeight(largeHeight);

    picker = new ColorPickerWidget;
    bgcheck = new QCheckBox(tr("Background"));
    bgcheck->setChecked(true);
    bordercheck = new QCheckBox(tr("Border"));
    bordercheck->setChecked(false);

    grid->addWidget(picker, 0, 0, 4, 4);
    grid->addWidget(bgcheck, 4, 0);
    grid->addWidget(bordercheck, 4, 2);

    QWidget *borderwidget = new QWidget;
    borderwidget->setFixedHeight(smallHeight);

    border = new QSpinBox;
    border->setFixedWidth(pagewidth/3.6);
    border->setRange(0, 100);
    border->setSingleStep(1);

    radius = new QSpinBox;
    radius->setFixedWidth(pagewidth/3.6);
    radius->setRange(0, 360);

    QGridLayout *bordergrid = new QGridLayout;
    bordergrid->addWidget(new QLabel(tr("Border ")), 0, 0, Qt::AlignTop);
    bordergrid->addWidget(border, 0, 1, Qt::AlignTop);
    bordergrid->addWidget(new QLabel(tr("Radius ")), 0, 2, Qt::AlignTop);
    bordergrid->addWidget(radius, 0, 3, Qt::AlignTop);
    borderwidget->setLayout(bordergrid);

    verticalLayout->addWidget(borderwidget);

    connect(bgcheck, SIGNAL(clicked(bool)),             this, SLOT(bgcheck_clicked(bool)));
    connect(bordercheck, SIGNAL(clicked(bool)),         this, SLOT(bordercheck_clicked(bool)));
    connect(picker, SIGNAL(colortoparent(QColor)),      this, SLOT(ColorChanged(QColor)));
    connect(border, SIGNAL(valueChanged(int)),          this, SLOT(changeBorderSize(int)));
    connect(radius, SIGNAL(valueChanged(int)),          this, SLOT(changeRadius(int)));
}

void RectangleTab::setCurrent(QmlObject *cur)
{
    rectangle = qobject_cast<Rectangle*>(cur);

    if (rectangle != NULL) {
        border->setValue(rectangle->borderSize());
        setColors(rectangle->backgroundColor(), rectangle->borderColor());
        radius->setValue(rectangle->radius());
    }
}

void RectangleTab::changeBGColor(QColor c)
{
    rectangle->setBackgroundColor(c);
    rectangle->update();
    setCurrent(rectangle);
}

void RectangleTab::changeBorderColor(QColor c)
{
    rectangle->setBorderColor(c);
    rectangle->update();
    setCurrent(rectangle);
}

void RectangleTab::changeBorderSize(int s)
{
    rectangle->setBorderSize(s);
    rectangle->update();
    setCurrent(rectangle);
}

void RectangleTab::changeRadius(int s)
{
    rectangle->setRadius(s);
    rectangle->update();
    setCurrent(rectangle);
}

void RectangleTab::setColors(QColor bg, QColor border)
{
    if (bgcheck->isChecked()) {
        picker->setColor(bg);
    } else {
        picker->setColor(border);
    }
}

void RectangleTab::ColorChanged(QColor c)
{
    if (bgcheck->isChecked()) {
        changeBGColor(c);
    } else {
        changeBorderColor(c);
    }
}

void RectangleTab::bgcheck_clicked(bool b)
{
    bordercheck->setChecked(!b);
    setCurrent(rectangle);
}

void RectangleTab::bordercheck_clicked(bool b)
{
    bgcheck->setChecked(!b);
    setCurrent(rectangle);
}
