#ifndef DOCKEDPANELTAB_H
#define DOCKEDPANELTAB_H

#include <QWidget>
#include "customtab.h"
#include "../../QmlObjects/qmlobjects.h"

class DockedPanelTab : public CustomTab
{
    Q_OBJECT
public:
    explicit DockedPanelTab(QWidget *parent = 0);

signals:

public slots:
};

#endif // DOCKEDPANELTAB_H
