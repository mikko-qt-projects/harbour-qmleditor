#ifndef ICONTEXTSWITCHTAB_H
#define ICONTEXTSWITCHTAB_H

#include <QWidget>
#include "../../QmlObjects/qmlobjects.h"
#include "customtab.h"

class IconTextSwitchTab : public CustomTab
{
    Q_OBJECT
public:
    explicit IconTextSwitchTab(QWidget *parent = 0);
    void setCurrent(QmlObject *cur);

signals:

public slots:

private:
    IconTextSwitch *iconText;
};

#endif // ICONTEXTSWITCHTAB_H
