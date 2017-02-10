#include "backgrounditemtab.h"

BackgroundItemTab::BackgroundItemTab(QWidget *parent) : CustomTab(parent)
{
    widget->setFixedHeight(smallHeight);

    contHeight = new ItemSizeComboBox;
    contWidth = new ComponentComboBox;

    grid->addWidget(new QLabel(tr("contentHeight")), 0, 0, Qt::AlignTop);
    grid->addWidget(contHeight, 0, 1, Qt::AlignTop);
    grid->addItem(new QSpacerItem(pagewidth/3.6, 50), 0, 2);
    grid->addWidget(new QLabel(tr("contentWidth")), 1, 0, Qt::AlignTop);
    grid->addWidget(contWidth, 1, 1, Qt::AlignTop);

    QWidget *widget_2 = new QWidget;
    widget_2->setFixedHeight(largeHeight);

    mouseAreaEnabled = new QCheckBox(tr("Enabled"));
    mouseAreaHoverEnabled = new QCheckBox(tr("hoverEnabled"));
    actionCombo = new ActionComboBox;
    actionEdit = new QLineEdit;

    QGridLayout *grid_2 = new QGridLayout;
    grid_2->addWidget(mouseAreaEnabled, 0, 0, Qt::AlignTop);
    grid_2->addWidget(mouseAreaHoverEnabled, 1, 0, 1, 2, Qt::AlignTop);
    grid_2->addItem(new QSpacerItem(pagewidth/12, 50), 2, 0);
    grid_2->addWidget(new QLabel(tr("action")), 3, 0, Qt::AlignTop);
    grid_2->addWidget(actionCombo, 3, 1, Qt::AlignTop);
    grid_2->addItem(new QSpacerItem(pagewidth/3.6, 50), 3, 2);
    grid_2->addWidget(actionEdit, 4, 1, 4, 2, Qt::AlignTop);

    widget_2->setLayout(grid_2);

    verticalLayout->addWidget(widget_2);


}

void BackgroundItemTab::setCurrent(QmlObject *cur)
{
    bgItem = qobject_cast<BackgroundItem*>(cur);

    if (bgItem) {
        contWidth->setCurrentIndex(bgItem->contentWidth());
        contHeight->setCurrentIndex(bgItem->contentHeight());

        mouseAreaEnabled->setChecked(bgItem->mouseAreaEnabled());
        mouseAreaHoverEnabled->setChecked(bgItem->mouseAreaHoverEnabled());

        actionCombo->setCurrentIndex(bgItem->action());
        actionEdit->setText(bgItem->actionText());
    }
}
