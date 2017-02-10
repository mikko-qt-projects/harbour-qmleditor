#ifndef ROWTAB_H
#define ROWTAB_H
#include <QSpinBox>
#include <QWidget>
#include "customtab.h"
#include "../../QmlObjects/qmlobjects.h"

class RowTab : public CustomTab
{
    Q_OBJECT
public:
    explicit RowTab(QWidget *parent = 0);
    void setCurrent(QmlObject *cur);

signals:

public slots:
    void setSpacing(int i);

private:
    Row *row;
    QSpinBox *spacing;
};
#endif // ROWPROPERTY_H
