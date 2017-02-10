#include "mouseareatab.h"

MouseAreaTab::MouseAreaTab(QWidget *parent) : CustomTab(parent)
{
    mouseAreaEnabled = new QCheckBox(tr("Enabled"));
    mouseAreaHoverEnabled = new QCheckBox(tr("hoverEnabled"));

    actionCombo = new ActionComboBox;
    actionEdit = new QLineEdit;

    grid->addWidget(mouseAreaEnabled, 0, 0, Qt::AlignTop);
    grid->addWidget(mouseAreaHoverEnabled, 1, 0, 1, 2, Qt::AlignTop);
    grid->addItem(new QSpacerItem(60, 50), 2, 0);
    grid->addWidget(new QLabel(tr("action")), 3, 0, Qt::AlignTop);
    grid->addWidget(actionCombo, 3, 1, Qt::AlignTop);
    grid->addItem(new QSpacerItem(pagewidth/3.6, 50), 3, 2);
    grid->addWidget(actionEdit, 4, 1, 4, 2, Qt::AlignTop);
}

void MouseAreaTab::setCurrent(QmlObject *cur)
{
    mouseArea = qobject_cast<MouseArea*>(cur);

    if (mouseArea) {
        mouseAreaEnabled->setChecked(mouseArea->mouseAreaEnabled());
        mouseAreaHoverEnabled->setChecked(mouseArea->mouseAreaHoverEnabled());

        actionCombo->setCurrentIndex(mouseArea->action());
        actionEdit->setText(mouseArea->actionText());
    }
}
