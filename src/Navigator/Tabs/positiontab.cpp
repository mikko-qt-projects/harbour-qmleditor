#include "positiontab.h"
#include "../navigatorwidget.h"

#include <QPainter>

PositionTab::PositionTab(NavigatorWidget *nw, QWidget *parent) : QWidget(parent), n(nw)
{
    QPalette p(palette());
    p.setColor(QPalette::Background, QColor("#3f3f3f"));
    setAutoFillBackground(true);
    setPalette(p);

    QSize s(160, 160);
    QColor bg("#292929");
    QColor t("white");

    column_btn = new QPushButton("Column");
    column_btn->setFixedSize(s);
    QPalette cpal = column_btn->palette();
    cpal.setColor(QPalette::Button, bg);
    cpal.setColor(QPalette::ButtonText, t);
    column_btn->setAutoFillBackground(true);
    column_btn->setPalette(cpal);

    row_btn = new QPushButton("Row");
    row_btn->setFixedSize(s);
    QPalette rpal = row_btn->palette();
    rpal.setColor(QPalette::Button, bg);
    rpal.setColor(QPalette::ButtonText, t);
    row_btn->setAutoFillBackground(true);
    row_btn->setPalette(rpal);

    QGridLayout *positiongrid = new QGridLayout;
    positiongrid->addWidget(column_btn, 0, 0);
    positiongrid->addWidget(row_btn, 0, 1);
    positiongrid->addItem(new QSpacerItem(175, 175), 0, 2);
    positiongrid->addItem(new QSpacerItem(175, 175), 0, 3);
    positiongrid->addItem(new QSpacerItem(175, 175), 1, 0);
    positiongrid->addItem(new QSpacerItem(175, 175), 2, 0);
    setLayout(positiongrid);

    connect(column_btn, SIGNAL(pressed()), n, SLOT(qml_object_pressed()));
    connect(row_btn, SIGNAL(pressed()), n, SLOT(qml_object_pressed()));
}

