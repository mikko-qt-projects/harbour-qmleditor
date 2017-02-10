#include "columnproperty.h"
#include "../editorwidget.h"

#include <QStyleOption>

ColumnProperty::ColumnProperty(EditorWidget *ew, QWidget *parent) : QWidget(parent), e(ew)
{
    setMinimumHeight(660);

    QPalette p(palette());
    p.setColor(QPalette::Background, QColor("#3f3f3f"));
    p.setColor(QPalette::Foreground, QColor("white"));
    setAutoFillBackground(true);
    setPalette(p);

    QWidget *columnwidget = new QWidget;

    spacing = new QSpinBox;
    spacing->setFixedWidth(100);
    spacing->setRange(0, 100);
    spacing->setSingleStep(1);

    QGridLayout *columngrid = new QGridLayout;
    columngrid->addWidget(new QLabel(tr("Spacing")), 0, 0, Qt::AlignTop);
    columngrid->addWidget(spacing, 0, 1, Qt::AlignTop);
    columngrid->addItem(new QSpacerItem(400, 50), 0, 2);
    columnwidget->setLayout(columngrid);

    QVBoxLayout *verticalLayout = new QVBoxLayout;
    verticalLayout->addWidget(columnwidget);
    verticalLayout->setAlignment(Qt::AlignTop);
    setLayout(verticalLayout);

    connect(spacing, SIGNAL(valueChanged(int)), this, SLOT(setSpacing(int)));
}

void ColumnProperty::paintEvent(QPaintEvent *)
{
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}

void ColumnProperty::setCurrent(QmlObject *cur)
{
    col = qobject_cast<Column*>(cur);
    if (col) {
        spacing->setValue(col->getLayout()->spacing());
    }
}

void ColumnProperty::setSpacing(int i)
{
    col->getLayout()->setSpacing(i);
    e->setCurrent(col);
}
