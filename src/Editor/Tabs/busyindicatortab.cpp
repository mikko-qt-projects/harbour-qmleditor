#include "busyindicatortab.h"

BusyIndicatorComboBox::BusyIndicatorComboBox(QWidget *parent) : QComboBox(parent)
{
    addItem("ExtraSmall");
    addItem("Small");
    addItem("Medium");
    addItem("Large");
}

BusyIndicatorTab::BusyIndicatorTab(QWidget *parent) : CustomTab(parent)
{
    widget->setFixedHeight(largeHeight);

    sizeCombo = new BusyIndicatorComboBox;
    runningLine = new QLineEdit;

    grid->addWidget(new QLabel(tr("busyIndicatorSize")), 0, 0, Qt::AlignTop);
    grid->addWidget(sizeCombo, 0, 1, Qt::AlignTop);
    grid->addItem(new QSpacerItem(pagewidth/3.6, 50), 0, 2);
    grid->addWidget(new QLabel(tr("running")), 1, 0, Qt::AlignTop);
    grid->addWidget(runningLine, 1, 1, 1, 2, Qt::AlignTop);
    grid->addWidget(new QLabel(tr("Anchors.CenterIn: parent")), 2, 0, 2, 3, Qt::AlignTop);

    QSize extraSmall(12, 12);
    QSize small(16, 16);
    QSize medium(32, 32);
    QSize large(64, 64);
    size.append(extraSmall);
    size.append(small);
    size.append(medium);
    size.append(large);

    connect(sizeCombo, SIGNAL(currentIndexChanged(int)), this, SLOT(sizeChanged(int)));
    connect(runningLine, SIGNAL(textChanged(QString)), this, SLOT(textChanged(QString)));
}

void BusyIndicatorTab::setCurrent(QmlObject *cur)
{
    busyIndicator = qobject_cast<BusyIndicator*>(cur);
    if (busyIndicator) {
        sizeCombo->setCurrentIndex(busyIndicator->busyIndicatorSizeIndex());
        runningLine->setText(busyIndicator->runningText());

        busyIndicator->setGeometry(busyIndicator->parentWidget()->width() / 2 - busyIndicator->width() /2,
                                   busyIndicator->parentWidget()->height() /2 - busyIndicator->height() /2,
                                   busyIndicator->width(), busyIndicator->height());
    }
}

void BusyIndicatorTab::sizeChanged(int i)
{
    QRect r(busyIndicator->parentWidget()->width() /2 - size.at(i).width() /2,
            busyIndicator->parentWidget()->height() /2 - size.at(i).height() /2,
            size.at(i).width(),
            size.at(i).height());
    busyIndicator->setGeometry(r);
    busyIndicator->setBusyIndicatorSizeIndex(i);
}

void BusyIndicatorTab::textChanged(QString t)
{
    busyIndicator->setRunningText(t);
}
