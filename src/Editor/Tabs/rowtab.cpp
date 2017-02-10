#include "rowtab.h"

RowTab::RowTab(QWidget *parent) : CustomTab(parent)
{
    spacing = new QSpinBox;
    spacing->setFixedWidth(smallHeight);
    spacing->setRange(0, 100);
    spacing->setSingleStep(1);

    grid->addWidget(new QLabel(tr("Spacing")), 0, 0, Qt::AlignTop);
    grid->addWidget(spacing, 0, 1, Qt::AlignTop);
    grid->addItem(new QSpacerItem(pagewidth/1.8, 50), 0, 2);

    connect(spacing, SIGNAL(valueChanged(int)), this, SLOT(setSpacing(int)));
}

void RowTab::setCurrent(QmlObject *cur)
{
    row = qobject_cast<Row*>(cur);
    if (row) {
        spacing->setValue(row->getLayout()->spacing());
    }
}

void RowTab::setSpacing(int i)
{
    row->getLayout()->setSpacing(i);
    setCurrent(row);
}
