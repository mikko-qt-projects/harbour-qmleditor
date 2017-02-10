#include "basictab.h"
#include "../navigatorwidget.h"
#include <QPainter>

BasicTab::BasicTab(NavigatorWidget *nw, QWidget *parent) : QWidget(parent), n(nw)
{   
    component_id = 0;
    image_id = 0;
    item_id = 0;
    mouseArea_id = 0;
    rectangle_id = 0;
    text_id = 0;
    column_id = 0;
    row_id = 0;

    QPalette p(palette());
    p.setColor(QPalette::Background, QColor("#3f3f3f"));
    setAutoFillBackground(true);
    setPalette(p);

    component_btn = new CustomButton("Component");
    image_btn = new CustomButton("Image");
    item_btn = new CustomButton("Item");
    mouseArea_btn = new CustomButton("Mouse\nArea");
    rectangle_btn = new CustomButton("Rectangle");
    text_btn = new CustomButton("Text");
    column_btn = new CustomButton("Column");
    row_btn = new CustomButton("Row");

    QGridLayout *basicgrid = new QGridLayout;
    basicgrid->addWidget(component_btn, 0, 0);
    basicgrid->addWidget(item_btn, 0, 1);
    basicgrid->addWidget(image_btn, 0, 2);
    basicgrid->addWidget(mouseArea_btn, 0, 3);
    basicgrid->addWidget(rectangle_btn, 1, 0);
    basicgrid->addWidget(text_btn, 1, 1);
    basicgrid->addWidget(column_btn, 1, 2);
    basicgrid->addWidget(row_btn, 1, 3);
    basicgrid->addItem(new QSpacerItem(160, 160), 2, 0);
    setLayout(basicgrid);

    connect(rectangle_btn, SIGNAL(pressed()),   this, SLOT(rectanglePressed()));
    connect(text_btn, SIGNAL(pressed()),        this, SLOT(textPressed()));
    connect(column_btn, SIGNAL(pressed()),      this, SLOT(columnPressed()));
    connect(row_btn, SIGNAL(pressed()),         this, SLOT(rowPressed()));
    connect(mouseArea_btn, SIGNAL(pressed()),   this, SLOT(mouseAreaPressed()));
    connect(image_btn, SIGNAL(pressed()),       this, SLOT(imagePressed()));
    connect(item_btn, SIGNAL(pressed()),        this, SLOT(itemPressed()));
    connect(component_btn, SIGNAL(pressed()),   this, SLOT(componentPressed()));

    connect(this, SIGNAL(columnSignal(QmlObject*)),     n, SLOT(qmlobject_pressed(QmlObject*)));
    connect(this, SIGNAL(componentSignal(QmlObject*)),  n, SLOT(qmlobject_pressed(QmlObject*)));
    connect(this, SIGNAL(itemSignal(QmlObject*)),       n, SLOT(qmlobject_pressed(QmlObject*)));
    connect(this, SIGNAL(imageSignal(QmlObject*)),      n, SLOT(qmlobject_pressed(QmlObject*)));
    connect(this, SIGNAL(rectangleSignal(QmlObject*)),  n, SLOT(qmlobject_pressed(QmlObject*)));
    connect(this, SIGNAL(rowSignal(QmlObject*)),        n, SLOT(qmlobject_pressed(QmlObject*)));
    connect(this, SIGNAL(mouseAreaSignal(QmlObject*)),  n, SLOT(qmlobject_pressed(QmlObject*)));

}

void BasicTab::componentPressed()
{
    QmlObject *component = new Component;
    component->setObjectName("component_" + QString::number(component_id));
    component_id++;
    emit componentSignal(component);
}

void BasicTab::imagePressed()
{
    QmlObject *image = new Image;
    image->setObjectName("image_" + QString::number(image_id));
    image_id++;
    emit imageSignal(image);
}

void BasicTab::itemPressed()
{
    QmlObject *item = new Item;
    item->setObjectName("item_" + QString::number(item_id));
    item_id++;
    emit itemSignal(item);
}

void BasicTab::mouseAreaPressed()
{
    QmlObject *mouseArea = new MouseArea;
    mouseArea->setObjectName("mouseArea_" + QString::number(mouseArea_id));
    mouseArea_id++;
    emit mouseAreaSignal(mouseArea);
}

void BasicTab::rectanglePressed()
{
    QmlObject *rectangle = new Rectangle;
    rectangle->setObjectName("rectangle_" + QString::number(rectangle_id));
    rectangle_id++;
    emit rectangleSignal(rectangle);
}

void BasicTab::textPressed()
{
    QmlObject *text = new Text;
    text->setObjectName("text_" + QString::number(text_id));
    text_id++;
    emit textSignal(text);
}

void BasicTab::columnPressed()
{
    QmlObject *column = new Column;
    column->setObjectName("column_" + QString::number(column_id));
    column_id++;
    emit columnSignal(column);
}

void BasicTab::rowPressed()
{
    QmlObject *row = new Row;
    row->setObjectName("row_" + QString::number(row_id));
    row_id++;
    emit rowSignal(row);
}

