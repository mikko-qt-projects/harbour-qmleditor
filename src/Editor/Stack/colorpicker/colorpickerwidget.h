/*

Copyright (C) 2009, Etienne Moutot <e.moutot@gmail.com>

This file is part of colorPickerWidget.

    colorPickerWidget is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    colorPickerWidget is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with Foobar.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef COLORPICKERWIDGET_H
#define COLORPICKERWIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QGridLayout>
#include "qtcolortriangle.h"
#include "colorviewer.h"

class ColorPickerWidget : public QWidget
{
    Q_OBJECT

public:
    ColorPickerWidget(QWidget *parent = 0);
    ~ColorPickerWidget();

Q_SIGNALS:
    void colorChanged(const QColor &col);
    void colortoparent(QColor c);

public Q_SLOTS:
    void setColor(const QColor &col);

private slots:
    void pickMode();
    void colorChgd();

private:
    QtColorTriangle *colorTriangle;
    ColorViewer *colorView;
    QPushButton *pickColor;

    QGridLayout *layout;
};

#endif // COLORPICKERWIDGET_H
