#ifndef LAYOUTTAB_H
#define LAYOUTTAB_H

#include <QCheckBox>
#include <QComboBox>
#include <QSpinBox>
#include <QWidget>
#include "customtab.h"
#include "../../QmlObjects/qmlobjects.h"

class LayoutTab : public CustomTab
{
    Q_OBJECT

public:
    explicit LayoutTab(QWidget *parent = 0);
    void setCurrent(QmlObject *cur);

signals:

public slots:
    void anchor_fill_clicked(bool b);
    void anchor_horizontalCenter_clicked(bool b);
    void anchor_verticalCenter_clicked(bool b);
    void anchor_top_clicked(bool b);
    void anchor_bottom_clicked(bool b);
    void anchor_left_clicked(bool b);
    void anchor_right_clicked(bool b);
    void anchor_top_margin_changed(int i);
    void anchor_bottom_margin_changed(int i);
    void anchor_left_margin_changed(int i);
    void anchor_right_margin_changed(int i);
    void anchor_horizontalCenter_margin_changed(int i);
    void anchor_verticalCenter_margin_changed(int i);
    void x_padding_changed(int i);
    void width_target_changed(int i);
    void height_size_changed(int i);

private:
    QmlObject *current;

    PaddingComboBox *x_padding;

    ComponentComboBox *width_target;
    ItemSizeComboBox *height_size;

    QCheckBox *anchor_fill;
    ComponentComboBox *anchor_fill_target;
    CustomSpinBox *anchor_fill_margin;

    QCheckBox *anchor_horizontalCenter;
    ComponentComboBox *anchor_horizontalCenter_target;
    CustomSpinBox *anchor_horizontalCenter_margin;

    QCheckBox *anchor_top;
    ComponentComboBox *anchor_top_target;
    CustomSpinBox *anchor_top_margin;

    QCheckBox *anchor_bottom;
    ComponentComboBox *anchor_bottom_target;
    CustomSpinBox *anchor_bottom_margin;

    QCheckBox *anchor_verticalCenter;
    ComponentComboBox *anchor_verticalCenter_target;
    CustomSpinBox *anchor_verticalCenter_margin;

    QCheckBox *anchor_left;
    ComponentComboBox *anchor_left_target;
    CustomSpinBox *anchor_left_margin;

    QCheckBox *anchor_right;
    ComponentComboBox *anchor_right_target;
    CustomSpinBox *anchor_right_margin;

    QList<int> itemSizeList;
    QList<int> paddingList;

};

#endif // LAYOUTITEMS_H
