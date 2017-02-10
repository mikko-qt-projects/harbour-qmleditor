#include "layouttab.h"

LayoutTab::LayoutTab(QWidget *parent) : CustomTab(parent)
{
    widget->setFixedHeight(smallHeight);

    x_padding = new PaddingComboBox;
    width_target = new ComponentComboBox;
    height_size = new ItemSizeComboBox;

    grid->addWidget(new QLabel(tr("x")), 0, 0, Qt::AlignTop);
    grid->addWidget(x_padding, 0, 1, Qt::AlignTop);
    grid->addItem(new QSpacerItem(pagewidth/160, 50), 0, 2);
    grid->addItem(new QSpacerItem(pagewidth/160, 50), 0, 3);
    grid->addWidget(new QLabel(tr("width")), 1, 0, Qt::AlignTop);
    grid->addWidget(width_target, 1, 1, Qt::AlignTop);
    grid->addWidget(new QLabel(tr("height")), 1, 2, Qt::AlignTop);
    grid->addWidget(height_size, 1, 3, Qt::AlignTop);

    QWidget *widget_2 = new QWidget;
    widget_2->setFixedHeight(extraLargeHeight);

    anchor_fill = new QCheckBox(tr("Fill"));
    anchor_fill->setChecked(false);
    anchor_fill_target = new ComponentComboBox;
    anchor_fill_margin = new CustomSpinBox;

    anchor_horizontalCenter = new QCheckBox(tr("H.Center"));
    anchor_horizontalCenter->setChecked(false);
    anchor_horizontalCenter_target = new ComponentComboBox;
    anchor_horizontalCenter_margin = new CustomSpinBox;

    anchor_top = new QCheckBox(tr("Top"));
    anchor_top->setChecked(false);
    anchor_top_target = new ComponentComboBox;
    anchor_top_margin = new CustomSpinBox;

    anchor_bottom = new QCheckBox(tr("Bottom"));
    anchor_bottom->setChecked(false);
    anchor_bottom_target = new ComponentComboBox;
    anchor_bottom_margin = new CustomSpinBox;

    anchor_verticalCenter = new QCheckBox(tr("V.Center"));
    anchor_verticalCenter->setChecked(false);
    anchor_verticalCenter_target = new ComponentComboBox;
    anchor_verticalCenter_margin = new CustomSpinBox;

    anchor_left = new QCheckBox(tr("Left"));
    anchor_left->setChecked(false);
    anchor_left_target = new ComponentComboBox;
    anchor_left_margin = new CustomSpinBox;

    anchor_right = new QCheckBox(tr("Right"));
    anchor_right->setChecked(false);
    anchor_right_target = new ComponentComboBox;
    anchor_right_margin = new CustomSpinBox;

    QGridLayout *grid_2 = new QGridLayout;
    grid_2->addWidget(anchor_fill, 0, 0, Qt::AlignTop);
    grid_2->addWidget(new QLabel(tr("Target")), 0, 1, Qt::AlignTop);
    grid_2->addWidget(anchor_fill_target, 0, 2, 0, 2, Qt::AlignTop);
    grid_2->addWidget(new QLabel(tr("Margin")), 1, 1, Qt::AlignTop);
    grid_2->addWidget(anchor_fill_margin, 1, 2, Qt::AlignTop);

    grid_2->addWidget(anchor_top, 2, 0, Qt::AlignTop);
    grid_2->addWidget(new QLabel(tr("Target")), 2, 1, Qt::AlignTop);
    grid_2->addWidget(anchor_top_target, 2, 2, 2, 2, Qt::AlignTop);
    grid_2->addWidget(new QLabel(tr("Margin")), 3, 1, Qt::AlignTop);
    grid_2->addWidget(anchor_top_margin, 3, 2, Qt::AlignTop);

    grid_2->addWidget(anchor_bottom, 4, 0, Qt::AlignTop);
    grid_2->addWidget(new QLabel(tr("Target")), 4, 1, Qt::AlignTop);
    grid_2->addWidget(anchor_bottom_target, 4, 2, 4, 2, Qt::AlignTop);
    grid_2->addWidget(new QLabel(tr("Margin")), 5, 1, Qt::AlignTop);
    grid_2->addWidget(anchor_bottom_margin, 5, 2, Qt::AlignTop);

    grid_2->addWidget(anchor_left, 6, 0, Qt::AlignTop);
    grid_2->addWidget(new QLabel(tr("Target")), 6, 1, Qt::AlignTop);
    grid_2->addWidget(anchor_left_target, 6, 2, 6, 2, Qt::AlignTop);
    grid_2->addWidget(new QLabel(tr("Margin")), 7, 1, Qt::AlignTop);
    grid_2->addWidget(anchor_left_margin, 7, 2, Qt::AlignTop);

    grid_2->addWidget(anchor_right, 8, 0, Qt::AlignTop);
    grid_2->addWidget(new QLabel(tr("Target")), 8, 1, Qt::AlignTop);
    grid_2->addWidget(anchor_right_target, 8, 2, 8, 2, Qt::AlignTop);
    grid_2->addWidget(new QLabel(tr("Margin")), 9, 1, Qt::AlignTop);
    grid_2->addWidget(anchor_right_margin, 9, 2, Qt::AlignTop);

    grid_2->addWidget(anchor_horizontalCenter, 10, 0, Qt::AlignTop);
    grid_2->addWidget(new QLabel(tr("Target")), 10, 1, Qt::AlignTop);
    grid_2->addWidget(anchor_horizontalCenter_target, 10, 2, 10, 2, Qt::AlignTop);
    grid_2->addWidget(new QLabel(tr("Margin")), 11, 1, Qt::AlignTop);
    grid_2->addWidget(anchor_horizontalCenter_margin, 11, 2, Qt::AlignTop);

    grid_2->addWidget(anchor_verticalCenter, 12, 0, Qt::AlignTop);
    grid_2->addWidget(new QLabel(tr("Target")), 12, 1, Qt::AlignTop);
    grid_2->addWidget(anchor_verticalCenter_target, 12, 2, 12, 2, Qt::AlignTop);
    grid_2->addWidget(new QLabel(tr("Margin")), 13, 1, Qt::AlignTop);
    grid_2->addWidget(anchor_verticalCenter_margin, 13, 2, Qt::AlignTop);
    widget_2->setLayout(grid_2);

    verticalLayout->addWidget(widget_2);

    itemSizeList.append(0);
    itemSizeList.append(88);
    itemSizeList.append(100);
    itemSizeList.append(126);
    itemSizeList.append(138);
    itemSizeList.append(168);
    itemSizeList.append(224);

    paddingList.append(0);
    paddingList.append(4);
    paddingList.append(8);
    paddingList.append(16);

    connect(anchor_fill,                SIGNAL(clicked(bool)),              this, SLOT(anchor_fill_clicked(bool)));
    connect(anchor_horizontalCenter,    SIGNAL(clicked(bool)),              this, SLOT(anchor_horizontalCenter_clicked(bool)));
    connect(anchor_verticalCenter,      SIGNAL(clicked(bool)),              this, SLOT(anchor_verticalCenter_clicked(bool)));
    connect(anchor_top,                 SIGNAL(clicked(bool)),              this, SLOT(anchor_top_clicked(bool)));
    connect(anchor_bottom,              SIGNAL(clicked(bool)),              this, SLOT(anchor_bottom_clicked(bool)));
    connect(anchor_left,                SIGNAL(clicked(bool)),              this, SLOT(anchor_left_clicked(bool)));
    connect(anchor_right,               SIGNAL(clicked(bool)),              this, SLOT(anchor_right_clicked(bool)));
    connect(anchor_top_margin,          SIGNAL(valueChanged(int)),          this, SLOT(anchor_top_margin_changed(int)));
    connect(anchor_bottom_margin,       SIGNAL(valueChanged(int)),          this, SLOT(anchor_bottom_margin_changed(int)));
    connect(anchor_left_margin,         SIGNAL(valueChanged(int)),          this, SLOT(anchor_left_margin_changed(int)));
    connect(anchor_right_margin,        SIGNAL(valueChanged(int)),          this, SLOT(anchor_right_margin_changed(int)));
    connect(x_padding,                  SIGNAL(currentIndexChanged(int)),   this, SLOT(x_padding_changed(int)));
    connect(width_target,               SIGNAL(currentIndexChanged(int)),   this, SLOT(width_target_changed(int)));
    connect(height_size,                SIGNAL(currentIndexChanged(int)),   this, SLOT(height_size_changed(int)));

}

void LayoutTab::setCurrent(QmlObject *cur)
{
    current = cur;

    anchor_fill->setEnabled(current->anchor_fill_enabled());

    anchor_horizontalCenter->setChecked(current->anchor_horizontalCenter_checked());
    anchor_horizontalCenter->setEnabled(current->anchor_positions_enabled());
    anchor_verticalCenter->setChecked(current->anchor_verticalCenter_checked());
    anchor_verticalCenter->setEnabled(current->anchor_positions_enabled());
    anchor_top->setChecked(current->anchor_top_checked());
    anchor_top->setEnabled(current->anchor_positions_enabled());
    anchor_bottom->setChecked(current->anchor_bottom_checked());
    anchor_bottom->setEnabled(current->anchor_positions_enabled());
    anchor_left->setChecked(current->anchor_left_checked());
    anchor_left->setEnabled(current->anchor_positions_enabled());
    anchor_right->setChecked(current->anchor_right_checked());
    anchor_right->setEnabled(current->anchor_positions_enabled());

    anchor_top_margin->setValue(current->anchor_top_margin());
    anchor_bottom_margin->setValue(current->anchor_bottom_margin());
    anchor_left_margin->setValue(current->anchor_left_margin());
    anchor_right_margin->setValue(current->anchor_right_margin());
    anchor_horizontalCenter_margin->setValue(current->anchor_horizontalCenter_margin());
    anchor_verticalCenter_margin->setValue(current->anchor_verticalCenter_margin());

    x_padding->setCurrentIndex(current->x_combobox_index());
    width_target->setCurrentIndex(current->width_combobox_index());
    height_size->setCurrentIndex(current->height_combobox_index());

    x_padding->setEnabled(current->x_combobox_enabled());
    width_target->setEnabled(current->width_combobox_enabled());
    height_size->setEnabled(current->height_combobox_enabled());

    if (!current->x_enabled() || !current->y_enabled()) {
        current->set_dragging_enabled(false);
    } else {
        current->set_dragging_enabled(true);
    }

}

void LayoutTab::anchor_fill_clicked(bool b)
{
    current->setGeometry(0, 0, current->parentWidget()->width(), current->parentWidget()->height());

    current->set_x_enabled(!b);
    current->set_y_enabled(!b);
    current->set_width_enabled(!b);
    current->set_height_enabled(!b);

    current->setX_combobox_enabled(!b);
    current->setWidth_combobox_enabled(!b);
    current->setHeight_combobox_enabled(!b);

    current->setAnchor_positions_enabled(!b);

    current->setAnchor_top_checked(false);
    current->setAnchor_bottom_checked(false);
    current->setAnchor_left_checked(false);
    current->setAnchor_right_checked(false);
    current->setAnchor_horizontalCenter_checked(false);
    current->setAnchor_verticalCenter_checked(false);
    setCurrent(current);
}

void LayoutTab::anchor_top_clicked(bool b)
{
    current->setAnchor_top_checked(b);
    if (current->anchor_bottom_checked())
        current->setAnchor_bottom_checked(!b);
    if (current->anchor_verticalCenter_checked())
        current->setAnchor_verticalCenter_checked(!b);
    current->setGeometry(current->x(), 0 + current->anchor_top_margin(), current->width(), current->height());
    current->set_y_enabled(!b);
    setCurrent(current);
}

void LayoutTab::anchor_bottom_clicked(bool b)
{
    current->setAnchor_bottom_checked(b);
    if (current->anchor_top_checked())
        current->setAnchor_top_checked(!b);
    if (current->anchor_verticalCenter_checked())
        current->setAnchor_verticalCenter_checked(!b);
    current->setGeometry(current->x(), current->parentWidget()->height() - current->height() - current->anchor_bottom_margin(), current->width(), current->height());
    current->set_y_enabled(!b);
    setCurrent(current);
}

void LayoutTab::anchor_left_clicked(bool b)
{
    current->setAnchor_left_checked(b);
    if (current->anchor_right_checked())
        current->setAnchor_right_checked(!b);
    if (current->anchor_horizontalCenter_checked())
        current->setAnchor_horizontalCenter_checked(!b);
    current->setGeometry(0 + current->anchor_left_margin(), current->y(), current->width(), current->height());
    current->set_x_enabled(!b);
    current->setX_combobox_enabled(!b);
    setCurrent(current);
}

void LayoutTab::anchor_right_clicked(bool b)
{
    current->setAnchor_right_checked(b);
    if (current->anchor_left_checked())
        current->setAnchor_left_checked(!b);
    if (current->anchor_horizontalCenter_checked())
        current->setAnchor_horizontalCenter_checked(!b);
    current->setGeometry(current->parentWidget()->width() - current->width() - current->anchor_right_margin(), current->y(), current->width(), current->height());
    current->set_x_enabled(!b);
    current->setX_combobox_enabled(!b);
    setCurrent(current);
}

void LayoutTab::anchor_horizontalCenter_clicked(bool b)
{
    current->setAnchor_horizontalCenter_checked(b);
    if (current->anchor_right_checked())
        current->setAnchor_right_checked(!b);
    if (current->anchor_left_checked())
        current->setAnchor_left_checked(!b);
    current->set_x_enabled(!b);
    current->setX_combobox_enabled(!b);
    current->setGeometry((current->parentWidget()->width() / 2) - (current->width() /2), current->y(), current->width(), current->height());
    setCurrent(current);
}

void LayoutTab::anchor_verticalCenter_clicked(bool b)
{
    current->setAnchor_verticalCenter_checked(b);
    if (current->anchor_top_checked())
        current->setAnchor_top_checked(!b);
    if (current->anchor_bottom_checked())
        current->setAnchor_bottom_checked(!b);
    current->set_y_enabled(!b);
    current->setGeometry(current->x(), (current->parentWidget()->height() /2) - (current->height() /2), current->width(), current->height());
    setCurrent(current);
}

void LayoutTab::anchor_top_margin_changed(int i)
{
    current->setAnchor_top_margin(i);
    if (current->anchor_top_checked())
        anchor_top_clicked(true);
    setCurrent(current);
}

void LayoutTab::anchor_bottom_margin_changed(int i)
{
    current->setAnchor_bottom_margin(i);
    if (current->anchor_bottom_checked())
        anchor_bottom_clicked(true);
    setCurrent(current);
}

void LayoutTab::anchor_left_margin_changed(int i)
{
    current->setAnchor_left_margin(i);
    if (current->anchor_left_checked())
        anchor_left_clicked(true);
    setCurrent(current);
}

void LayoutTab::anchor_right_margin_changed(int i)
{
    current->setAnchor_right_margin(i);
    if (current->anchor_right_checked())
        anchor_right_clicked(true);
    setCurrent(current);
}

void LayoutTab::anchor_horizontalCenter_margin_changed(int i)
{
    current->setAnchor_horizontalCenter_margin(i);
    setCurrent(current);
}

void LayoutTab::anchor_verticalCenter_margin_changed(int i)
{
    current->setAnchor_verticalCenter_margin(i);
    setCurrent(current);
}

void LayoutTab::x_padding_changed(int i)
{
    current->setX_combobox_index(i);

    if (x_padding->currentIndex() != 0) {
        current->setGeometry(paddingList.at(i), current->y(), current->width(), current->height());
        current->set_x_enabled(false);
    }
    else {
        current->set_x_enabled(true);
    }
    setCurrent(current);
}

void LayoutTab::width_target_changed(int i)
{
    current->setWidth_combobox_index(i);
    if (width_target->currentIndex() != 0) {
        current->setGeometry(0, current->y(), current->parentWidget()->width(), current->height());
        current->set_x_enabled(false);
    }
    else {
        current->set_x_enabled(true);
    }
    setCurrent(current);
}

void LayoutTab::height_size_changed(int i)
{
    current->setHeight_combobox_index(i);
    if (height_size->currentIndex() != 0) {
        current->setGeometry(current->x(), current->y(), current->width(), itemSizeList.at(i));
        current->set_height_enabled(false);
    } else {
        current->set_height_enabled(true);
    }
    setCurrent(current);
}
