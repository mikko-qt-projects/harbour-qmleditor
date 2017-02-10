#ifndef HORIZONTALSCROLLDECORATORTAB_H
#define HORIZONTALSCROLLDECORATORTAB_H

#include <QWidget>
#include "customtab.h"
#include "../../QmlObjects/qmlobjects.h"

class HorizontalScrollDecoratorTab : public CustomTab
{
    Q_OBJECT
public:
    explicit HorizontalScrollDecoratorTab(QWidget *parent = 0);
    void setCurrent(QmlObject *cur);

signals:

public slots:

private:
    ComponentComboBox *component;
    HorizontalScrollDecorator *hScroll;
};

#endif // HORIZONTALSCROLLDECORATORTAB_H
