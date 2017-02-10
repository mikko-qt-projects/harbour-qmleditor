#ifndef SILICAMENUTAB_H
#define SILICAMENUTAB_H

#include <QWidget>
#include "custombutton.h"

class NavigatorWidget;

class SilicaMenuTab : public QWidget
{
    Q_OBJECT
public:
    explicit SilicaMenuTab(NavigatorWidget *nw, QWidget *parent = 0);

signals:
    void contextMenuSignal(QmlObject *obj);
    void menuItemSignal(QmlObject *obj);
    void menuLabelSignal(QmlObject *obj);
    void pullDownMenuSignal(QmlObject *obj);
    void pushUpMenuSignal(QmlObject *obj);

public slots:
    void contextMenuPressed();
    void menuItemPressed();
    void menuLabelPressed();
    void pullDownMenuPressed();
    void pushUpMenuOressed();

private:
    NavigatorWidget *n;
    CustomButton *contextMenu_btn;
    CustomButton *menuItem_btn;
    CustomButton *menuLabel_btn;
    CustomButton *pullDownMenu_btn;
    CustomButton *pushUpMenu_btn;

    int contextMenu_id;
    int menuItem_id;
    int menuLabel_id;
    int pullDownMenu_id;
    int pushUpMenu_id;
};

#endif // SILICAMENUTAB_H
