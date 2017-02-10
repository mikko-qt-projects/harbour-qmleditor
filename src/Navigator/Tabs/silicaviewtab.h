#ifndef SILICAVIEWTAB_H
#define SILICAVIEWTAB_H

#include <QWidget>
#include <QGridLayout>
#include "custombutton.h"

class NavigatorWidget;

class SilicaViewTab : public QWidget
{
    Q_OBJECT
public:
    explicit SilicaViewTab(NavigatorWidget *nw, QWidget *parent = 0);

signals:
    void columnViewSignal(QmlObject *obj);
    void dockedPanelSignal(QmlObject *obj);
    void drawerSignal(QmlObject *obj);
    void horizontalScrollDecoratorSignal(QmlObject *obj);
    void scrollDecoratorSignal(QmlObject *obj);
    void silicaFlickableSignal(QmlObject *obj);
    void silicaGridViewSignal(QmlObject *obj);
    void silicaListViewSignal(QmlObject *obj);
    void silicaWebViewSignal(QmlObject *obj);
    void slideshowViewSignal(QmlObject *obj);
    void verticalScrollDecoratorSignal(QmlObject *obj);
    void viewPlaceholderSignal(QmlObject *obj);

public slots:
    void columnViewPressed();
    void dockedPanelPressed();
    void drawerPressed();
    void horizontalScrollDecoratorPressed();
    void scrollDecoratorPressed();
    void silicaFlickablePressed();
    void silicaGridViewPressed();
    void silicaListViewPressed();
    void silicaWebViewPressed();
    void slideshowViewPressed();
    void verticalScrollDecoratorPressed();
    void viewPlaceholderPressed();

private:
    NavigatorWidget *n;
    CustomButton *columnView_btn;
    CustomButton *dockedPanel_btn;
    CustomButton *drawer_btn;
    CustomButton *horizontalScrollDecorator_btn;
    CustomButton *scrollDecorator_btn;
    CustomButton *silicaFlickable_btn;
    CustomButton *silicaGridView_btn;
    CustomButton *silicaListView_btn;
    CustomButton *silicaWebView_btn;
    CustomButton *slideshowView_btn;
    CustomButton *verticalScrollDecorator_btn;
    CustomButton *viewPlaceholder_btn;

    int columnView_id;
    int dockedPanel_id;
    int drawer_id;
    int horizontalScrollDecorator_id;
    int scrollDecorator_id;
    int silicaFlickable_id;
    int silicaGridView_id;
    int silicaListView_id;
    int silicaWebView_id;
    int slideshowView_id;
    int verticalScrollDecorator_id;
    int viewPlaceholder_id;
};

#endif // SILICAVIEWTAB_H
