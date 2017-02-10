#include "silicaviewtab.h"
#include "../navigatorwidget.h"

SilicaViewTab::SilicaViewTab(NavigatorWidget *nw, QWidget *parent) : QWidget(parent), n(nw)
{
    columnView_id = 0;
    dockedPanel_id = 0;
    drawer_id = 0;
    horizontalScrollDecorator_id = 0;
    scrollDecorator_id = 0;
    silicaFlickable_id = 0;
    silicaGridView_id = 0;
    silicaListView_id = 0;
    silicaWebView_id = 0;
    slideshowView_id = 0;
    verticalScrollDecorator_id = 0;
    viewPlaceholder_id = 0;

    QPalette p(palette());
    p.setColor(QPalette::Background, QColor("#3f3f3f"));
    setAutoFillBackground(true);
    setPalette(p);

    columnView_btn = new CustomButton("Column\nView");
    dockedPanel_btn = new CustomButton("Docked\nPanel");
    drawer_btn = new CustomButton("Drawer");
    horizontalScrollDecorator_btn = new CustomButton("Horizontal\nScroll\nDecorator");
    scrollDecorator_btn = new CustomButton("Scroll\nDecorator");
    silicaFlickable_btn = new CustomButton("Silica\nFlickable");
    silicaGridView_btn = new CustomButton("Silica\nGridView");
    silicaListView_btn = new CustomButton("Silica\nListView");
    silicaWebView_btn = new CustomButton("Silica\nWebView");
    slideshowView_btn = new CustomButton("Slide\nshowView");
    verticalScrollDecorator_btn = new CustomButton("Vertical\nScroll\nDecorator");
    viewPlaceholder_btn = new CustomButton("View\nPlaceholder");

    QGridLayout *grid = new QGridLayout;
    grid->addWidget(silicaFlickable_btn, 0, 0);
    grid->addWidget(silicaGridView_btn, 0, 1);
    grid->addWidget(silicaListView_btn, 0, 2);
    grid->addWidget(silicaWebView_btn, 0, 3);
    grid->addWidget(verticalScrollDecorator_btn, 1, 0);
    grid->addWidget(horizontalScrollDecorator_btn, 1, 1);
    grid->addWidget(scrollDecorator_btn, 1, 2);
    grid->addWidget(dockedPanel_btn, 1, 3);
    grid->addWidget(columnView_btn, 2, 0);
    grid->addWidget(slideshowView_btn, 2, 1);
    grid->addWidget(drawer_btn, 2, 2);
    grid->addWidget(viewPlaceholder_btn, 2, 3);
    setLayout(grid);

    connect(silicaListView_btn, SIGNAL(pressed()),              this, SLOT(silicaListViewPressed()));
    connect(columnView_btn, SIGNAL(pressed()),                  this, SLOT(columnViewPressed()));
    connect(silicaGridView_btn, SIGNAL(pressed()),              this, SLOT(silicaGridViewPressed()));
    connect(silicaWebView_btn, SIGNAL(pressed()),               this, SLOT(silicaWebViewPressed()));
    connect(silicaFlickable_btn, SIGNAL(pressed()),             this, SLOT(silicaFlickablePressed()));
    connect(verticalScrollDecorator_btn, SIGNAL(pressed()),     this, SLOT(verticalScrollDecoratorPressed()));
    connect(scrollDecorator_btn, SIGNAL(pressed()),             this, SLOT(scrollDecoratorPressed()));
    connect(dockedPanel_btn, SIGNAL(pressed()),                 this, SLOT(dockedPanelPressed()));
    connect(slideshowView_btn, SIGNAL(pressed()),               this, SLOT(slideshowViewPressed()));
    connect(drawer_btn, SIGNAL(pressed()),                      this, SLOT(drawerPressed()));
    connect(viewPlaceholder_btn, SIGNAL(pressed()),             this, SLOT(viewPlaceholderPressed()));
    connect(horizontalScrollDecorator_btn, SIGNAL(pressed()),   this, SLOT(horizontalScrollDecoratorPressed()));

    connect(this, SIGNAL(columnViewSignal(QmlObject*)),                 n, SLOT(qmlobject_pressed(QmlObject*)));
    connect(this, SIGNAL(silicaListViewSignal(QmlObject*)),             n, SLOT(qmlobject_pressed(QmlObject*)));
    connect(this, SIGNAL(silicaGridViewSignal(QmlObject*)),             n, SLOT(qmlobject_pressed(QmlObject*)));
    connect(this, SIGNAL(silicaWebViewSignal(QmlObject*)),              n, SLOT(qmlobject_pressed(QmlObject*)));
    connect(this, SIGNAL(silicaFlickableSignal(QmlObject*)),            n, SLOT(qmlobject_pressed(QmlObject*)));
    connect(this, SIGNAL(verticalScrollDecoratorSignal(QmlObject*)),    n, SLOT(qmlobject_pressed(QmlObject*)));
    connect(this, SIGNAL(dockedPanelSignal(QmlObject*)),                n, SLOT(qmlobject_pressed(QmlObject*)));
    connect(this, SIGNAL(slideshowViewSignal(QmlObject*)),              n, SLOT(qmlobject_pressed(QmlObject*)));
    connect(this, SIGNAL(drawerSignal(QmlObject*)),                     n, SLOT(qmlobject_pressed(QmlObject*)));
    connect(this, SIGNAL(viewPlaceholderSignal(QmlObject*)),            n, SLOT(qmlobject_pressed(QmlObject*)));
    connect(this, SIGNAL(horizontalScrollDecoratorSignal(QmlObject*)),  n, SLOT(qmlobject_pressed(QmlObject*)));
    connect(this, SIGNAL(scrollDecoratorSignal(QmlObject*)),            n, SLOT(qmlobject_pressed(QmlObject*)));

}

void SilicaViewTab::columnViewPressed()
{
    QmlObject *columnView = new ColumnView;
    columnView->setObjectName("columnView_" + QString::number(columnView_id));
    columnView_id++;
    emit columnViewSignal(columnView);
}

void SilicaViewTab::dockedPanelPressed()
{
    QmlObject *dockedPanel = new DockedPanel;
    dockedPanel->setObjectName("dockedPanel_" + QString::number(dockedPanel_id));
    dockedPanel_id++;
    emit dockedPanelSignal(dockedPanel);
}

void SilicaViewTab::drawerPressed()
{
    QmlObject *drawer = new Drawer;
    drawer->setObjectName("drawerw_" + QString::number(drawer_id));
    drawer_id++;
    emit drawerSignal(drawer);
}

void SilicaViewTab::horizontalScrollDecoratorPressed()
{
    QmlObject *horizontalScrollDecorator = new HorizontalScrollDecorator;
    horizontalScrollDecorator->setObjectName("horizontalScrollDecorator_" + QString::number(horizontalScrollDecorator_id));
    horizontalScrollDecorator_id++;
    emit horizontalScrollDecoratorSignal(horizontalScrollDecorator);
}

void SilicaViewTab::scrollDecoratorPressed()
{
    QmlObject *scrollDecorator = new ScrollDecorator;
    scrollDecorator->setObjectName("scrollDecorator_" + QString::number(scrollDecorator_id));
    scrollDecorator_id++;
    emit scrollDecoratorSignal(scrollDecorator);
}

void SilicaViewTab::silicaFlickablePressed()
{
    QmlObject *silicaFlickable = new SilicaFlickable;
    silicaFlickable->setObjectName("columnView_" + QString::number(silicaFlickable_id));
    silicaFlickable_id++;
    emit silicaFlickableSignal(silicaFlickable);
}

void SilicaViewTab::silicaGridViewPressed()
{
    QmlObject *silicaGridView = new SilicaGridView;
    silicaGridView->setObjectName("silicaGridView_" + QString::number(silicaGridView_id));
    silicaGridView_id++;
    emit silicaGridViewSignal(silicaGridView);
}

void SilicaViewTab::silicaListViewPressed()
{
    QmlObject *columnView = new ColumnView;
    columnView->setObjectName("columnView_" + QString::number(columnView_id));
    columnView_id++;
    emit columnViewSignal(columnView);
}

void SilicaViewTab::silicaWebViewPressed()
{
    QmlObject *silicaWebView = new SilicaWebView;
    silicaWebView->setObjectName("silicaWebView_" + QString::number(silicaWebView_id));
    silicaWebView_id++;
    emit silicaWebViewSignal(silicaWebView);
}

void SilicaViewTab::slideshowViewPressed()
{
    QmlObject *slideshowView = new SlideshowView;
    slideshowView->setObjectName("slideshowView_" + QString::number(slideshowView_id));
    slideshowView_id++;
    emit slideshowViewSignal(slideshowView);
}

void SilicaViewTab::verticalScrollDecoratorPressed()
{
    QmlObject *verticalScrollDecorator = new VerticalScrollDecorator;
    verticalScrollDecorator->setObjectName("verticalScrollDecorator_" + QString::number(verticalScrollDecorator_id));
    verticalScrollDecorator_id++;
    emit verticalScrollDecoratorSignal(verticalScrollDecorator);
}

void SilicaViewTab::viewPlaceholderPressed()
{
    QmlObject *viewPlaceholder = new ViewPlaceholder;
    viewPlaceholder->setObjectName("viewPlaceholder_" + QString::number(viewPlaceholder_id));
    viewPlaceholder_id++;
    emit viewPlaceholderSignal(viewPlaceholder);
}
