#ifndef RECTANGLETAB_H
#define RECTANGLETAB_H

#include <QCheckBox>
#include <QLineEdit>
#include <QSpinBox>
#include <QWidget>
#include "colorpicker/colorpickerwidget.h"
#include "customtab.h"
#include "../../QmlObjects/qmlobjects.h"

class RectangleTab : public CustomTab
{
    Q_OBJECT
public:
    explicit RectangleTab(QWidget *parent = 0);
    void setCurrent(QmlObject *cur);

    void changeBGColor(QColor c);
    void changeBorderColor(QColor c);

signals:

public slots:
    void changeBorderSize(int s);
    void changeRadius(int s);
    void setColors(QColor bg, QColor border);
    void ColorChanged(QColor c);
    void bgcheck_clicked(bool b);
    void bordercheck_clicked(bool b);

private:
    Rectangle *rectangle;
    ColorPickerWidget *picker;
    QCheckBox *bgcheck;
    QCheckBox *bordercheck;
    QSpinBox *border;
    QSpinBox *radius;
};

#endif // RECTANGLEPROPERTY_H
