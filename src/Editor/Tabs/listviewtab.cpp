#include "listviewtab.h"
#include <QLabel>


SilicaListViewTab::SilicaListViewTab(QWidget *parent) : CustomTab(parent)
{
    widget->setFixedHeight(extraSmallHeight);

    spacing = new QSpinBox;
    spacing->setFixedWidth(pagewidth/7.2);
    spacing->setRange(0, 100);
    spacing->setSingleStep(1);

    grid->addWidget(new QLabel(tr("Spacing")), 0, 0, Qt::AlignTop);
    grid->addWidget(spacing, 0, 1, Qt::AlignTop);
    grid->addItem(new QSpacerItem(pagewidth/1.8, 50), 0, 2);

    QWidget *widget_2 = new QWidget;
    widget_2->setFixedHeight(largeHeight);

    modelbox = new QComboBox;
    modelbox->addItem("");
    modelbox->addItem("ListModel");

    delegatebox = new QComboBox;
    delegatebox->addItem("");

    highlightbox = new QComboBox;
    highlightbox->addItem("");
    headerbox = new QComboBox;
    headerbox->addItem("");
    footerbox = new QComboBox;
    footerbox->addItem("");

    highlightcheck = new QCheckBox(tr("highlight"));
    headercheck = new QCheckBox(tr("header"));
    footercheck = new QCheckBox(tr("footer"));

    QGridLayout *grid_2 = new QGridLayout;
    grid_2->addWidget(new QLabel(tr("Required:")), 0, 0, Qt::AlignTop);
    grid_2->addWidget(new QLabel(tr("model")), 1, 0, Qt::AlignTop);
    grid_2->addWidget(modelbox, 1, 1, Qt::AlignTop);
    grid_2->addItem(new QSpacerItem(pagewidth/5.143, 40), 1, 2);
    grid_2->addItem(new QSpacerItem(pagewidth/5.143, 40), 1, 3);
    grid_2->addWidget(new QLabel(tr("delegate")), 2, 0, Qt::AlignTop);
    grid_2->addWidget(delegatebox, 2, 1, Qt::AlignTop);
    grid_2->addWidget(new QLabel(tr("Optional:")), 3, 0, Qt::AlignTop);
    grid_2->addWidget(highlightcheck, 4, 0, Qt::AlignTop);
    grid_2->addWidget(highlightbox, 4, 1, Qt::AlignTop);
    grid_2->addWidget(headercheck, 5, 0, Qt::AlignTop);
    grid_2->addWidget(headerbox, 5, 1, Qt::AlignTop);
    grid_2->addWidget(footercheck, 6, 0, Qt::AlignTop);
    grid_2->addWidget(footerbox, 6, 1, Qt::AlignTop);
    widget_2->setLayout(grid_2);

    verticalLayout->addWidget(widget_2);

}

void SilicaListViewTab::setCurrent(QmlObject *cur)
{
    listView = qobject_cast<SilicaListView*>(cur);

    if (listView != NULL) {
        spacing->setValue(listView->spacing());
    }
}

