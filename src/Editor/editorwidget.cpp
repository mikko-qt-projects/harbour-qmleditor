#include "editorwidget.h"
#include <QTableWidget>
#include <QTabBar>
#include <QApplication>

EditorWidget::EditorWidget(QWidget *parent) : QWidget(parent)
{
    int pageheight = qApp->property("pageheight").toInt();

    QFont font;
    font.setPointSize(pageheight/53.3);
    setFont(font);

    current = NULL;

    typeitems = new TypeProperty(this);
    geometry = new GeometryProperty;

    mainTab = new EmptyTab;
    layoutTab = new LayoutTab;

    currentTabWidget = new CustomTabWidget;
    currentTabWidget->addTab(mainTab, tr(""));

    stack = new QStackedWidget;
    stack->addWidget(currentTabWidget);

    verticalLayout = new QVBoxLayout;
    verticalLayout->addWidget(typeitems);
    verticalLayout->addWidget(geometry);
    verticalLayout->addWidget(stack);
    setLayout(verticalLayout);

}

void EditorWidget::set_current(QmlObject *cur)
{
    if (current != cur || current != NULL) {
        current = cur;

        typeitems->setCurrent(current);
        geometry->setCurrent(current);
        stack->removeWidget(currentTabWidget);

        currentTabWidget = NULL;
        mainTab = NULL;

        currentTabWidget = new CustomTabWidget;

        if (current->getObjectType() == "Page") {
            mainTab = new EmptyTab;
        } else if (current->getObjectType() == "Rectangle") {
            mainTab = new RectangleTab;
        } else if (current->getObjectType() == "Text") {
            mainTab = new TextTab;
        } else if (current->getObjectType() == "Column") {
            mainTab = new ColumnTab;
        } else if (current->getObjectType() == "Row") {
            mainTab = new RowTab;
        } else if (current->getObjectType() == "SilicaListView") {
            mainTab = new SilicaListViewTab;
        } else if (current->getObjectType() == "BackgroundItem") {
            mainTab = new BackgroundItemTab;
        } else if (current->getObjectType() == "MouseArea") {
            mainTab = new MouseAreaTab;
        } else if (current->getObjectType() == "Button") {
            mainTab = new ButtonTab;
        } else if (current->getObjectType() == "BusyIndicator") {
            mainTab = new BusyIndicatorTab;
        } else if (current->getObjectType() == "ComboBox") {
            mainTab = new ComboBoxTab;
        } else if (current->getObjectType() == "DetailItem") {
            mainTab = new DetailItemTab;
        }
        else {
            mainTab = new EmptyTab;
        }

        mainTab->setCurrent(current);
        layoutTab->setCurrent(current);
        currentTabWidget->addTab(mainTab, current->getObjectType());
        currentTabWidget->addTab(layoutTab, tr("Layout"));
        stack->insertWidget(0, currentTabWidget);
    }
}


void EditorWidget::update_current()
{
    set_current(current);
}

