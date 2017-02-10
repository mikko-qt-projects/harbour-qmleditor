#ifndef DETAILITEM_H
#define DETAILITEM_H

#include <QWidget>
#include "qmlobject.h"

class DetailItem : public QmlObject
{
    Q_OBJECT
public:
    explicit DetailItem(QWidget *parent = 0);
    QLabel *label() {return m_label;}
    QLabel *value() {return m_value;}

signals:

public slots:

private:
    QLabel *m_label;
    QLabel *m_value;
};

#endif // DETAILITEM_H
