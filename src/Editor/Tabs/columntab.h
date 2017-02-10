#ifndef COLUMNTAB_H
#define COLUMNTAB_H

#include <QSpinBox>
#include <QWidget>
#include "customtab.h"
#include "../../QmlObjects/qmlobjects.h"

class ColumnTab : public CustomTab
{
    Q_OBJECT
public:
    explicit ColumnTab(QWidget *parent = 0);
    void setCurrent(QmlObject *cur);

signals:

public slots:
    void setSpacing(int i);

private:
    Column *col;
    QSpinBox *spacing;
};

#endif // COLUMNPROPERTY_H
