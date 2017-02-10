#include "layoutproperty.h"
#include "../editorwidget.h"
#include <QStyleOption>

LayoutProperty::LayoutProperty(EditorWidget *ew, QWidget *parent) : QWidget(parent), e(ew)
{
    setMinimumHeight(660);

    QPalette p(palette());
    p.setColor(QPalette::Background, QColor("#3f3f3f"));
    p.setColor(QPalette::Foreground, QColor("white"));
    setAutoFillBackground(true);
    setPalette(p);

    QWidget *layoutwidget = new QWidget;
    layoutwidget->setMaximumHeight(300);

    anchors_fill = new QCheckBox(tr("Anchors.fill: parent"));
    anchors_fill->setChecked(false);

    anchors_horizontalCenter = new QCheckBox(tr("horizontalCenter"));
    anchors_horizontalCenter->setChecked(false);

    anchors_top = new QCheckBox(tr("top"));
    anchors_top->setChecked(false);

    anchors_bottom = new QCheckBox(tr("bottom"));
    anchors_bottom->setChecked(false);

    anchors_verticalCenter = new QCheckBox(tr("verticalCenter"));
    anchors_verticalCenter->setChecked(false);

    anchors_left = new QCheckBox(tr("left"));
    anchors_left->setChecked(false);

    anchors_right = new QCheckBox(tr("right"));
    anchors_right->setChecked(false);

    QGridLayout *layoutgrid = new QGridLayout;
    layoutgrid->setRowStretch(0, 2);
    layoutgrid->addWidget(anchors_fill, 0, 0, Qt::AlignTop);
    layoutgrid->addWidget(anchors_horizontalCenter, 1, 0, Qt::AlignTop);
    layoutgrid->addWidget(anchors_verticalCenter, 1, 1, Qt::AlignTop);
    layoutgrid->addWidget(anchors_top, 2, 0, Qt::AlignTop);
    layoutgrid->addWidget(anchors_bottom, 2, 1, Qt::AlignTop);
    layoutgrid->addWidget(anchors_left, 3, 0, Qt::AlignTop);
    layoutgrid->addWidget(anchors_right, 3, 1, Qt::AlignTop);
    layoutwidget->setLayout(layoutgrid);

    QVBoxLayout *verticalLayout = new QVBoxLayout;
    verticalLayout->addWidget(layoutwidget);
    verticalLayout->setAlignment(Qt::AlignTop);
    setLayout(verticalLayout);

    connect(anchors_fill, SIGNAL(clicked(bool)), this, SLOT(anchors_fill_clicked(bool)));
    connect(anchors_horizontalCenter, SIGNAL(clicked(bool)), this, SLOT(anchors_horizontalCenter_clicked(bool)));
    connect(anchors_verticalCenter, SIGNAL(clicked(bool)), this, SLOT(anchors_verticalCenter_clicked(bool)));
    connect(anchors_top, SIGNAL(clicked(bool)), this, SLOT(anchors_top_clicked(bool)));
    connect(anchors_bottom, SIGNAL(clicked(bool)), this, SLOT(anchors_bottom_clicked(bool)));
    connect(anchors_left, SIGNAL(clicked(bool)), this, SLOT(anchors_left_clicked(bool)));
    connect(anchors_right, SIGNAL(clicked(bool)), this, SLOT(anchors_right_clicked(bool)));
}

void LayoutProperty::paintEvent(QPaintEvent *)
{
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}

void LayoutProperty::setCurrent(QmlObject *cur)
{
    current = cur;

    anchors_fill->setEnabled(current->anchor_fill_visible());

    anchors_horizontalCenter->setChecked(current->anchor_horizontalCenter_checked());
    anchors_horizontalCenter->setEnabled(current->anchor_positions_visible());
    anchors_verticalCenter->setChecked(current->anchor_verticalCenter_checked());
    anchors_verticalCenter->setEnabled(current->anchor_positions_visible());
    anchors_top->setChecked(current->anchor_top_checked());
    anchors_top->setEnabled(current->anchor_positions_visible());
    anchors_bottom->setChecked(current->anchor_bottom_checked());
    anchors_bottom->setEnabled(current->anchor_positions_visible());
    anchors_left->setChecked(current->anchor_left_checked());
    anchors_left->setEnabled(current->anchor_positions_visible());
    anchors_right->setChecked(current->anchor_right_checked());
    anchors_right->setEnabled(current->anchor_positions_visible());
}

void LayoutProperty::anchors_fill_clicked(bool b)
{
    current->setGeometry(0, 0, current->parentWidget()->width(), current->parentWidget()->height());
    current->setGeometryhided(b);
    current->setAnchor_positions_visible(!b);
    anchors_horizontalCenter->setChecked(false);
    anchors_verticalCenter->setChecked(false);
    anchors_top->setChecked(false);
    anchors_bottom->setChecked(false);
    anchors_left->setChecked(false);
    anchors_right->setChecked(false);
    e->setCurrent(current);
}

void LayoutProperty::anchors_horizontalCenter_clicked(bool b)
{
    current->setAnchor_horizontalCenter_checked(b);
    current->setGeometry((current->parentWidget()->width() / 2) - (current->width() /2), current->y(), current->width(), current->height());
    e->setCurrent(current);
}

void LayoutProperty::anchors_verticalCenter_clicked(bool b)
{
    current->setAnchor_verticalCenter_checked(b);
    current->setGeometry(current->x(), (current->parentWidget()->height() /2) - (current->height() /2), current->width(), current->height());
    e->setCurrent(current);
}

void LayoutProperty::anchors_top_clicked(bool b)
{
    current->setAnchor_top_checked(b);
    current->setGeometry(current->x(), 0, current->width(), current->height());
    e->setCurrent(current);
}

void LayoutProperty::anchors_bottom_clicked(bool b)
{
    current->setAnchor_bottom_checked(b);
    current->setGeometry(current->x(), current->parentWidget()->height() - current->height(), current->width(), current->height());
    e->setCurrent(current);
}

void LayoutProperty::anchors_left_clicked(bool b)
{
    current->setAnchor_left_checked(b);
    current->setGeometry(0, current->y(), current->width(), current->height());
    e->setCurrent(current);
}

void LayoutProperty::anchors_right_clicked(bool b)
{
    current->setAnchor_right_checked(b);
    current->setGeometry(current->parentWidget()->width() - current->width(), current->y(), current->width(), current->height());
    e->setCurrent(current);
}
