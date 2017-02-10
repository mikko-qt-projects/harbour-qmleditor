#include "columnviewtab.h"

ColumnViewTab::ColumnViewTab(QWidget *parent) : CustomTab(parent)
{
    cache = new QCheckBox;
    cacheBuffer = new QSpinBox;

    itemHeight = new QCheckBox;

    maxVisibleHeight = new QCheckBox;

    model = new QCheckBox;

    delegate = new QCheckBox;

    grid->addWidget(cache, 0, 0);
    grid->addWidget(cacheBuffer, 0, 1);
    grid->addWidget(itemHeight, 1, 0);
    grid->addWidget(maxVisibleHeight, 2, 0);
    grid->addWidget(model, 3, 0);
    grid->addWidget(delegate, 4, 0);

}

