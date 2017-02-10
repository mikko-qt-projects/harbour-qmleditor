#ifndef BUSYINDICATORTAB_H
#define BUSYINDICATORTAB_H

#include <QLineEdit>
#include <QWidget>
#include "customtab.h"
#include "../../QmlObjects/qmlobjects.h"

class BusyIndicatorComboBox : public QComboBox
{
    Q_OBJECT

public:
    explicit BusyIndicatorComboBox(QWidget *parent = 0);

};

class BusyIndicatorTab : public CustomTab
{
    Q_OBJECT

public:
    explicit BusyIndicatorTab(QWidget *parent = 0);
    void setCurrent(QmlObject *cur);

signals:

public slots:
    void sizeChanged(int i);
    void textChanged(QString t);

private:
    BusyIndicatorComboBox *sizeCombo;
    QLineEdit *runningLine;
    BusyIndicator *busyIndicator;

    QList<QSize> size;
};

#endif // BUSYINDICATORTAB_H

