#ifndef COLUMNVIEW_H
#define COLUMNVIEW_H

#include <QWidget>
#include "qmlobject.h"

class ColumnView : public QmlObject
{
    Q_OBJECT
public:
    explicit ColumnView(QWidget *parent = 0);

signals:

public slots:
};

#endif // COLUMNVIEW_H
