#ifndef LABEL_H
#define LABEL_H

#include <QWidget>
#include "qmlobject.h"

class Label : public QmlObject
{
    Q_OBJECT
public:
    explicit Label(QWidget *parent = 0);

signals:

public slots:
};

#endif // LABEL_H
