#ifndef COLUMNVIEWTAB_H
#define COLUMNVIEWTAB_H

#include <QCheckBox>
#include <QSpinBox>
#include <QWidget>
#include "customtab.h"
#include "../../QmlObjects/qmlobjects.h"

class ColumnViewTab : public CustomTab
{
    Q_OBJECT
public:
    explicit ColumnViewTab(QWidget *parent = 0);

signals:

public slots:

private:
    QCheckBox *cache;
    QSpinBox *cacheBuffer;

    QCheckBox *itemHeight;

    QCheckBox *maxVisibleHeight;

    QCheckBox *model;

    QCheckBox *delegate;

};

#endif // COLUMNVIEWTAB_H
