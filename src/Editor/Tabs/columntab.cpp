#include "columntab.h"

ColumnTab::ColumnTab(QWidget *parent) : CustomTab(parent)
{
    spacing = new QSpinBox;
    spacing->setFixedWidth(extraSmallHeight);
    spacing->setRange(0, 100);
    spacing->setSingleStep(1);

    grid->addWidget(new QLabel(tr("Spacing")), 0, 0, Qt::AlignTop);
    grid->addWidget(spacing, 0, 1, Qt::AlignTop);
    grid->addItem(new QSpacerItem(pagewidth/1.8, 50), 0, 2);

    connect(spacing, SIGNAL(valueChanged(int)), this, SLOT(setSpacing(int)));
}

void ColumnTab::setCurrent(QmlObject *cur)
{
    col = qobject_cast<Column*>(cur);
    if (col) {
        spacing->setValue(col->getLayout()->spacing());
    }
}

void ColumnTab::setSpacing(int i)
{
    col->getLayout()->setSpacing(i);
    setCurrent(col);
}
