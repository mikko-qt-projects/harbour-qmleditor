#include "silicatexttab.h"
#include "../navigatorwidget.h"

SilicaTextTab::SilicaTextTab(NavigatorWidget *nw, QWidget *parent) : QWidget(parent), n(nw)
{
    detailItem_id = 0;
    enterKey_id = 0;
    label_id = 0;
    searchField_id = 0;
    sectionHeader_id = 0;
    pageHeader_id = 0;
    textArea_id = 0;
    textField_id = 0;

    QPalette p(palette());
    p.setColor(QPalette::Background, QColor("#3f3f3f"));
    setAutoFillBackground(true);
    setPalette(p);

    detailItem_btn = new CustomButton("Detail\nItem");
    enterKey_btn = new CustomButton("EnterKey");
    label_btn = new CustomButton("Label");
    searchField_btn = new CustomButton("Search\nField");
    sectionHeader_btn = new CustomButton("Section\nHeader");
    pageHeader_btn = new CustomButton("Page\nHeader");
    textArea_btn = new CustomButton("Text\nArea");
    textField_btn = new CustomButton("Text\nField");

    QGridLayout *grid = new QGridLayout;
    grid->addWidget(label_btn, 0, 0);
    grid->addWidget(textField_btn, 0, 1);
    grid->addWidget(textArea_btn, 0, 2);
    grid->addWidget(pageHeader_btn, 0, 3);
    grid->addWidget(sectionHeader_btn, 1, 0);
    grid->addWidget(searchField_btn, 1, 1);
    grid->addWidget(detailItem_btn, 1, 2);
    grid->addWidget(enterKey_btn, 1, 3);
    grid->addItem(new QSpacerItem(160, 160), 2, 0);
    setLayout(grid);

    connect(detailItem_btn, SIGNAL(pressed()), this, SLOT(detailItemPressed()));
    connect(enterKey_btn, SIGNAL(pressed()), this, SLOT(enterKeyPressed()));
    connect(label_btn, SIGNAL(pressed()), this, SLOT(labelPressed()));
    connect(searchField_btn, SIGNAL(pressed()), this, SLOT(searchFieldPressed()));
    connect(sectionHeader_btn, SIGNAL(pressed()), this, SLOT(sectionHeaderPressed()));
    connect(pageHeader_btn, SIGNAL(pressed()), this, SLOT(pageHeaderPressed()));
    connect(textArea_btn, SIGNAL(pressed()), this, SLOT(textAreaPressed()));
    connect(textField_btn, SIGNAL(pressed()), this, SLOT(textFieldPressed()));

    connect(this, SIGNAL(detailItemSignal(QmlObject*)),     n, SLOT(qmlobject_pressed(QmlObject*)));
    connect(this, SIGNAL(enterKeySignal(QmlObject*)),       n, SLOT(qmlobject_pressed(QmlObject*)));
    connect(this, SIGNAL(labelSignal(QmlObject*)),          n, SLOT(qmlobject_pressed(QmlObject*)));
    connect(this, SIGNAL(searchFieldSignal(QmlObject*)),    n, SLOT(qmlobject_pressed(QmlObject*)));
    connect(this, SIGNAL(sectionHeaderSignal(QmlObject*)),  n, SLOT(qmlobject_pressed(QmlObject*)));
    connect(this, SIGNAL(pageHeaderSignal(QmlObject*)),     n, SLOT(qmlobject_pressed(QmlObject*)));
    connect(this, SIGNAL(textAreaSignal(QmlObject*)),       n, SLOT(qmlobject_pressed(QmlObject*)));
    connect(this, SIGNAL(textFieldSignal(QmlObject*)),      n, SLOT(qmlobject_pressed(QmlObject*)));
}

void SilicaTextTab::detailItemPressed()
{
    QmlObject *detailItem = new DetailItem;
    detailItem->setObjectName("detailItem_" + QString::number(detailItem_id));
    detailItem_id++;
    emit detailItemSignal(detailItem);
}

void SilicaTextTab::enterKeyPressed()
{
    QmlObject *enterKey = new EnterKey;
    enterKey->setObjectName("enterKey_" + QString::number(enterKey_id));
    enterKey_id++;
    emit enterKeySignal(enterKey);
}

void SilicaTextTab::labelPressed()
{
    QmlObject *label = new Label;
    label->setObjectName("label_" + QString::number(label_id));
    label_id++;
    emit labelSignal(label);
}

void SilicaTextTab::searchFieldPressed()
{
    QmlObject *searchField = new SearchField;
    searchField->setObjectName("searchField_" + QString::number(searchField_id));
    searchField_id++;
    emit searchFieldSignal(searchField);
}

void SilicaTextTab::sectionHeaderPressed()
{
    QmlObject *sectionHeader = new SectionHeader;
    sectionHeader->setObjectName("sectionHeader_" + QString::number(sectionHeader_id));
    sectionHeader_id++;
    emit sectionHeaderSignal(sectionHeader);
}

void SilicaTextTab::pageHeaderPressed()
{
    QmlObject *pageHeader = new PageHeader;
    pageHeader->setObjectName("pageHeader_" + QString::number(pageHeader_id));
    pageHeader_id++;
    emit pageHeaderSignal(pageHeader);
}

void SilicaTextTab::textAreaPressed()
{
    QmlObject *textArea = new TextArea;
    textArea->setObjectName("textArea_" + QString::number(textArea_id));
    textArea_id++;
    emit textAreaSignal(textArea);
}

void SilicaTextTab::textFieldPressed()
{
    QmlObject *textField = new TextField;
    textField->setObjectName("textField_" + QString::number(textField_id));
    textField_id++;
    emit textFieldSignal(textField);
}
