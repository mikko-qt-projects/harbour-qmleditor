#ifndef TEXTFIELD_H
#define TEXTFIELD_H

#include <QWidget>
#include "qmlobject.h"

class TextField : public QmlObject
{
    Q_OBJECT
public:
    explicit TextField(QWidget *parent = 0);

signals:

public slots:
};

#endif // TEXTFIELD_H
