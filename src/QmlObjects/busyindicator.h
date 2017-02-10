#ifndef BUSYINDICATOR_H
#define BUSYINDICATOR_H

#include <QWidget>
#include "qmlobject.h"

class BusyIndicator : public QmlObject
{
    Q_OBJECT
public:
    explicit BusyIndicator(QWidget *parent = 0);
    void paintEvent(QPaintEvent *e);
    void setBusyIndicatorSizeIndex(int i) {m_busyIndicatorSizeIndex = i;}
    int busyIndicatorSizeIndex() {return m_busyIndicatorSizeIndex;}
    void setRunningText(QString t) {m_runningText = t;}
    QString runningText() {return m_runningText;}

signals:

public slots:

private:
    int m_busyIndicatorSizeIndex;
    QString m_runningText;
};

#endif // BUSYINDICATOR_H
