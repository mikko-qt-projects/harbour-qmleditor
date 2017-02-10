#ifndef VERTICALSCROLLDECORATORTAB_H
#define VERTICALSCROLLDECORATORTAB_H

#include <QWidget>
#include "customtab.h"
#include "../../QmlObjects/qmlobjects.h"

class VerticalScrollDecoratorTab : public CustomTab
{
    Q_OBJECT
public:
    explicit VerticalScrollDecoratorTab(QWidget *parent = 0);
    void setCurrent(QmlObject *cur);

signals:

public slots:

private:
    ComponentComboBox *component;
    VerticalScrollDecorator *vScroll;
};

#endif // VERTICALSCROLLDECORATORTAB_H
