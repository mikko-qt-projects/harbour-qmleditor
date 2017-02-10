#ifndef DETAILITEMTAB_H
#define DETAILITEMTAB_H

#include <QLineEdit>
#include <QWidget>
#include "../../QmlObjects/qmlobjects.h"
#include "customtab.h"

class DetailItemTab : public CustomTab
{
    Q_OBJECT
public:
    explicit DetailItemTab(QWidget *parent = 0);
    void setCurrent(QmlObject *cur);

signals:

public slots:
    void labelChanged(QString s);
    void valueChanged(QString s);

private:
    DetailItem *detailItem;
    QLineEdit *label;
    QLineEdit *value;
};

#endif // DETAILITEMTAB_H
