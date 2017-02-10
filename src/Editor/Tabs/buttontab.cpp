#include "buttontab.h"

ButtonTab::ButtonTab(QWidget *parent) : CustomTab(parent)
{
    widget->setFixedHeight(smallHeight);

    buttonWidthCombo = new ButtonWidthComboBox;
    colorCombo = new ColorComboBox;

    grid->addWidget(new QLabel(tr("preferredWidth")), 0, 0, Qt::AlignTop);
    grid->addWidget(buttonWidthCombo, 0, 1, Qt::AlignTop);
    grid->addItem(new QSpacerItem(pagewidth/7.2, 50), 0, 2);
    grid->addWidget(new QLabel(tr("color")), 1, 0, Qt::AlignTop);
    grid->addWidget(colorCombo, 1, 1, Qt::AlignTop);

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

    QSize small(294, 88);
    QSize medium(376, 88);
    QSize large(556, 88);
    buttonWidth.append(small);
    buttonWidth.append(medium);
    buttonWidth.append(large);

    QColor primary("#d6d7d9");
    QColor secondary("#a7aaad");
    color.append(primary);
    color.append(secondary);

    connect(buttonWidthCombo, SIGNAL(currentIndexChanged(int)), this, SLOT(buttonWidthChanged(int)));
    connect(colorCombo, SIGNAL(currentIndexChanged(int)), this, SLOT(buttonColorChanged(int)));
}

void ButtonTab::setCurrent(QmlObject *cur)
{
    button = qobject_cast<Button*>(cur);
    if (button) {
        buttonWidthCombo->setCurrentIndex(button->preferredWidthIndex());
        colorCombo->setCurrentIndex(button->buttonColorIndex());
        mouseAreaEnabled->setChecked(button->mouseAreaEnabled());
        mouseAreaHoverEnabled->setChecked(button->mouseAreaHoverEnabled());

        actionCombo->setCurrentIndex(button->action());
        actionEdit->setText(button->actionText());
    }
}

void ButtonTab::buttonWidthChanged(int i)
{
    button->setPrefferedWidthIndex(i);
    button->setGeometry(button->x(), button->y(), buttonWidth[i].width(), buttonWidth[i].height());
    setCurrent(button);
}

void ButtonTab::buttonColorChanged(int i)
{
    button->setButtonColor(color[i]);
    button->setButtonColorIndex(i);
    setCurrent(button);
    button->update();
}
