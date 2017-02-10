#include "detailitemtab.h"

DetailItemTab::DetailItemTab(QWidget *parent) : CustomTab(parent)
{
    widget->setFixedHeight(smallHeight);

    label = new QLineEdit;
    value = new QLineEdit;

    grid->addWidget(new QLabel(tr("label")), 0, 0, Qt::AlignTop);
    grid->addWidget(label, 0, 1, Qt::AlignTop);
    grid->addWidget(new QLabel(tr("value")), 1, 0, Qt::AlignTop);
    grid->addWidget(value, 1, 1, Qt::AlignTop);

    connect(label, SIGNAL(textChanged(QString)), this, SLOT(labelChanged(QString)));
    connect(value, SIGNAL(textChanged(QString)), this, SLOT(valueChanged(QString)));
}

void DetailItemTab::setCurrent(QmlObject *cur)
{
    detailItem = qobject_cast<DetailItem*>(cur);

    if (detailItem) {
        label->setText(detailItem->label()->text());
        value->setText(detailItem->value()->text());

        QFont font;
        font.setPointSize(28);
        QFontMetrics fm(font);

        detailItem->label()->setGeometry(0, 0, fm.width(detailItem->label()->text()), 28);
        detailItem->value()->setGeometry(detailItem->label()->width() + 20, 0, fm.width(detailItem->value()->text()), 28);

        detailItem->setGeometry(detailItem->parentWidget()->width() / 2 - (detailItem->label()->width() + 10),
                                detailItem->y(),
                                detailItem->label()->width() + 20 + detailItem->value()->width(),
                                28);
    }
}

void DetailItemTab::labelChanged(QString s)
{
    detailItem->label()->setText(s);
    setCurrent(detailItem);
}

void DetailItemTab::valueChanged(QString s)
{
    detailItem->value()->setText(s);
    setCurrent(detailItem);
}
