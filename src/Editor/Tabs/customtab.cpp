#include "customtab.h"
#include <QPainter>
#include <QStyleOption>
#include <QAbstractItemView>
#include <QApplication>

ComponentComboBox::ComponentComboBox(QWidget *parent) : QComboBox(parent)
{
    addItem("");
    addItem("Parent");

}

PaddingComboBox::PaddingComboBox(QWidget *parent) : QComboBox(parent)
{
    addItem("");
    addItem("paddingSmall");
    addItem("paddingMedium");
    addItem("paddingLarge");
    addItem("horizontalPageMargin");
}

ItemSizeComboBox::ItemSizeComboBox(QWidget *parent) : QComboBox(parent)
{
    addItem("");
    addItem("itemSizeExtraSmall");
    addItem("itemSizeSmall");
    addItem("itemSizeMedium");
    addItem("itemSizeLarge");
    addItem("itemSizeExtraLarge");
    addItem("ItemSizeHuge");
}

FontSizeComboBox::FontSizeComboBox(QWidget *parent) : QComboBox(parent)
{
    addItem("fontSizeTiny");
    addItem("fontSizeExtraSmall");
    addItem("fontSizeSmall");
    addItem("fontSizeMedium");
    addItem("fontSizeLarge");
    addItem("fontSizeExtraLarge");
    addItem("fontSizeHuge");
}

ActionComboBox::ActionComboBox(QWidget *parent) : QComboBox(parent)
{
    addItem("");
    addItem("onClicked");
    addItem("onPressed");
    addItem("onReleased");
    addItem("onPressandHold");
    addItem("onDoubleClicked");
    addItem("onPositionChanged");
}

ColorComboBox::ColorComboBox(QWidget *parent) : QComboBox(parent)
{
    addItem("primaryColor");
    addItem("secondaryColor");
}

ButtonWidthComboBox::ButtonWidthComboBox(QWidget *parent) : QComboBox(parent)
{
    addItem("buttonWidthSmall");
    addItem("buttonWidthMedium");
    addItem("buttonWidthLarge");
}

void ButtonWidthComboBox::showPopup()
{
    view()->move(this->x(), this->y());
    QComboBox::showPopup();
}

CustomSpinBox::CustomSpinBox(QWidget *parent) : QSpinBox(parent)
{
    setFixedWidth((qApp->property("pagewidth").toInt())/7.2);
    setRange(0, 100);
    setSingleStep(1);
}


CustomTab::CustomTab(QWidget *parent) : QWidget(parent)
{
    pagewidth = qApp->property("pagewidth").toInt();
    pageheight = qApp->property("pageheight").toInt();

    extraSmallHeight = pageheight/32;
    smallHeight = pageheight/9.15;
    mediumHeight = pageheight/6.4;
    largeHeight = pageheight/3.2;
    extraLargeHeight = pageheight/1.6;

    setFixedHeight(pageheight/1.376);

    QPalette p(palette());
    p.setColor(QPalette::Background, QColor("#3f3f3f"));
    p.setColor(QPalette::Foreground, QColor("white"));
    setAutoFillBackground(true);
    setPalette(p);

    widget = new QWidget;
    widget->setMinimumHeight(largeHeight);

    grid = new QGridLayout;

    widget->setLayout(grid);

    verticalLayout = new QVBoxLayout;
    verticalLayout->setAlignment(Qt::AlignTop);
    verticalLayout->addWidget(widget);
    setLayout(verticalLayout);
}

void CustomTab::paintEvent(QPaintEvent *)
{
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}

void CustomTab::setCurrent(QmlObject *cur)
{
    Q_UNUSED(cur);
}
