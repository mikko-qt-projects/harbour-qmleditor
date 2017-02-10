#include "silicaitemtab.h"
#include "../navigatorwidget.h"

SilicaItemTab::SilicaItemTab(NavigatorWidget *nw, QWidget *parent) : QWidget(parent), n(nw)
{
    backGroundItem_id = 0;
    busyIndicator_id = 0;
    keypad_id = 0;
    listItem_id = 0;
    progressBar_id = 0;
    remorseItem_id = 0;;
    remorsePopup_id = 0;
    separator_id = 0;
    touchBlocker_id = 0;

    QPalette p(palette());
    p.setColor(QPalette::Background, QColor("#3f3f3f"));
    setAutoFillBackground(true);
    setPalette(p);

    backgroundItem_btn = new CustomButton("Background\nItem");
    busyIndicator_btn = new CustomButton("Busy\nIndicator");
    keypad_btn = new CustomButton("Keypad");
    listItem_btn = new CustomButton("ListItem");
    progressBar_btn = new CustomButton("Progress\nBar");
    remorseItem_btn = new CustomButton("Remorse\nItem");
    remorsePopup_btn = new CustomButton("Remorse\nPopup");
    separator_btn = new CustomButton("Separator");
    touchBlocker_btn = new CustomButton("Touch\nBlocker");

    QGridLayout *grid = new QGridLayout;
    grid->addWidget(listItem_btn, 0, 0);
    grid->addWidget(backgroundItem_btn, 0, 1);
    grid->addWidget(progressBar_btn, 0, 2);
    grid->addWidget(separator_btn, 0, 3);
    grid->addWidget(keypad_btn, 1, 0);
    grid->addWidget(remorseItem_btn, 1, 1);
    grid->addWidget(remorsePopup_btn, 1, 2);
    grid->addWidget(busyIndicator_btn, 1, 3);
    grid->addWidget(touchBlocker_btn, 2, 0);
    setLayout(grid);

    connect(backgroundItem_btn, SIGNAL(pressed()), this, SLOT(backGroundItemPressed()));
    connect(busyIndicator_btn,  SIGNAL(pressed()), this, SLOT(busyIndicatorPressed()));
    connect(listItem_btn,       SIGNAL(pressed()), this, SLOT(listItemPressed()));
    connect(progressBar_btn,    SIGNAL(pressed()), this, SLOT(progressBarPressed()));
    connect(separator_btn,      SIGNAL(pressed()), this, SLOT(separatorPressed()));
    connect(remorseItem_btn,    SIGNAL(pressed()), this, SLOT(remorseItemPressed()));
    connect(remorsePopup_btn,   SIGNAL(pressed()), this, SLOT(remorsePopupPressed()));
    connect(touchBlocker_btn,   SIGNAL(pressed()), this, SLOT(touchBlockerPressed()));
    connect(keypad_btn,         SIGNAL(pressed()), this, SLOT(keypadPressed()));

    connect(this, SIGNAL(backGroundItemSignal(QmlObject*)),     n, SLOT(qmlobject_pressed(QmlObject*)));
    connect(this, SIGNAL(busyIndicatorSignal(QmlObject*)),      n, SLOT(qmlobject_pressed(QmlObject*)));
    connect(this, SIGNAL(listItemSignal(QmlObject*)),           n, SLOT(qmlobject_pressed(QmlObject*)));
    connect(this, SIGNAL(progressBarSignal(QmlObject*)),        n, SLOT(qmlobject_pressed(QmlObject*)));
    connect(this, SIGNAL(separatorSignal(QmlObject*)),          n, SLOT(qmlobject_pressed(QmlObject*)));
    connect(this, SIGNAL(remorseItemSignal(QmlObject*)),        n, SLOT(qmlobject_pressed(QmlObject*)));
    connect(this, SIGNAL(remorsePopupSignal(QmlObject*)),       n, SLOT(qmlobject_pressed(QmlObject*)));
    connect(this, SIGNAL(touchBlockerSignal(QmlObject*)),       n, SLOT(qmlobject_pressed(QmlObject*)));
    connect(this, SIGNAL(keypadSignal(QmlObject*)),             n, SLOT(qmlobject_pressed(QmlObject*)));
}

void SilicaItemTab::backGroundItemPressed()
{
    QmlObject *backGroundItem = new BackgroundItem;
    backGroundItem->setObjectName("bgItem_" + QString::number(backGroundItem_id));
    backGroundItem_id++;
    emit backGroundItemSignal(backGroundItem);
}

void SilicaItemTab::busyIndicatorPressed()
{
    QmlObject *busyIndicator = new BusyIndicator;
    busyIndicator->setObjectName("busyIndicator_" + QString::number(busyIndicator_id));
    busyIndicator_id++;
    emit busyIndicatorSignal(busyIndicator);
}

void SilicaItemTab::keypadPressed()
{
    QmlObject *keypad = new Keypad;
    keypad->setObjectName("keypad_" + QString::number(keypad_id));
    keypad_id++;
    emit keypadSignal(keypad);
}

void SilicaItemTab::listItemPressed()
{
    QmlObject *listItem = new ListItem;
    listItem->setObjectName("listItem_" + QString::number(listItem_id));
    listItem_id++;
    emit listItemSignal(listItem);
}

void SilicaItemTab::progressBarPressed()
{
    QmlObject *progressBar = new ProgressBar;
    progressBar->setObjectName("progressBar_" + QString::number(progressBar_id));
    progressBar_id++;
    emit progressBarSignal(progressBar);
}

void SilicaItemTab::remorseItemPressed()
{
    QmlObject *remorseItem = new RemorseItem;
    remorseItem->setObjectName("remorseItem_" + QString::number(remorseItem_id));
    remorseItem_id++;
    emit remorseItemSignal(remorseItem);
}

void SilicaItemTab::remorsePopupPressed()
{
    QmlObject *remorsePopup = new RemorsePopup;
    remorsePopup->setObjectName("remorsePopup_" + QString::number(remorsePopup_id));
    remorsePopup_id++;
    emit remorsePopupSignal(remorsePopup);
}

void SilicaItemTab::separatorPressed()
{
    QmlObject *separator = new Separator;
    separator->setObjectName("separator_" + QString::number(separator_id));
    separator_id++;
    emit separatorSignal(separator);
}

void SilicaItemTab::touchBlockerPressed()
{
    QmlObject *touchBlocker = new TouchBlocker;
    touchBlocker->setObjectName("touchBlocker_" + QString::number(touchBlocker_id));
    touchBlocker_id++;
    emit touchBlockerSignal(touchBlocker);
}
