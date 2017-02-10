#ifndef RECTANGLEPROPERTY_H
#define RECTANGLEPROPERTY_H

#include <QCheckBox>
#include <QLineEdit>
#include <QSpinBox>
#include <QWidget>
#include "colorpicker/colorpickerwidget.h"
#include "../../qmlobject.h"

class EditorWidget;

class RectangleProperty : public QWidget
{
    Q_OBJECT
public:
    explicit RectangleProperty(EditorWidget *ew, QWidget *parent = 0);
    void paintEvent(QPaintEvent *);
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
    EditorWidget *e;
    Rectangle *rectangle;
    ColorPickerWidget *picker;
    QCheckBox *bgcheck;
    QCheckBox *bordercheck;
    QSpinBox *border;
    QSpinBox *radius;
};

#endif // RECTANGLEPROPERTY_H
