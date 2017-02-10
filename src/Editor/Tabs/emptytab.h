#ifndef EMPTYTAB_H
#define EMPTYTAB_H

#include <QWidget>
#include "customtab.h"

class EmptyTab : public CustomTab
{
    Q_OBJECT
public:
    explicit EmptyTab(QWidget *parent = 0);

signals:

public slots:
};

#endif // EMPTYPROPERTY_H
