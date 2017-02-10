#ifndef LAYOUTITEMS_H
#define LAYOUTITEMS_H

#include <QCheckBox>
#include <QWidget>
#include "../../qmlobject.h"

class EditorWidget;

class LayoutProperty : public QWidget
{
    Q_OBJECT
public:
    explicit LayoutProperty(EditorWidget *ew, QWidget *parent = 0);
    void paintEvent(QPaintEvent *);
    void setCurrent(QmlObject *cur);

signals:

public slots:
    void anchors_fill_clicked(bool b);
    void anchors_horizontalCenter_clicked(bool b);
    void anchors_verticalCenter_clicked(bool b);
    void anchors_top_clicked(bool b);
    void anchors_bottom_clicked(bool b);
    void anchors_left_clicked(bool b);
    void anchors_right_clicked(bool b);

private:
    EditorWidget *e;

    QmlObject *current;
    QCheckBox *anchors_fill;

    QCheckBox *anchors_horizontalCenter;
    QCheckBox *anchors_top;
    QCheckBox *anchors_bottom;

    QCheckBox *anchors_verticalCenter;
    QCheckBox *anchors_left;
    QCheckBox *anchors_right;

};

#endif // LAYOUTITEMS_H
