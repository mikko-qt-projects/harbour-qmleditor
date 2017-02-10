#include "rowproperty.h"
#include "../editorwidget.h"

#include <QStyleOption>

RowProperty::RowProperty(EditorWidget *ew, QWidget *parent) : QWidget(parent), e(ew)
{
    setMinimumHeight(660);
    QPalette p(palette());
    p.setColor(QPalette::Background, QColor("#3f3f3f"));
    p.setColor(QPalette::Foreground, QColor("white"));
    setAutoFillBackground(true);
    setPalette(p);

    QWidget *rowwidget = new QWidget;

    spacing = new QSpinBox;
    spacing->setFixedWidth(100);
    spacing->setRange(0, 100);
    spacing->setSingleStep(1);

    QGridLayout *rowgrid = new QGridLayout;
    rowgrid->addWidget(new QLabel(tr("Spacing")), 0, 0, Qt::AlignTop);
    rowgrid->addWidget(spacing, 0, 1, Qt::AlignTop);
    rowgrid->addItem(new QSpacerItem(400, 50), 0, 2);
    rowwidget->setLayout(rowgrid);

    QVBoxLayout *verticalLayout = new QVBoxLayout;
    verticalLayout->addWidget(rowwidget);
    verticalLayout->setAlignment(Qt::AlignTop);
    setLayout(verticalLayout);

    connect(spacing, SIGNAL(valueChanged(int)), this, SLOT(setSpacing(int)));
}

void RowProperty::paintEvent(QPaintEvent *)
{
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}

void RowProperty::setCurrent(QmlObject *cur)
{
    row = qobject_cast<Row*>(cur);
    if (row) {
        spacing->setValue(row->getLayout()->spacing());
    }
}

void RowProperty::setSpacing(int i)
{
    row->getLayout()->setSpacing(i);
    e->setCurrent(row);
}
