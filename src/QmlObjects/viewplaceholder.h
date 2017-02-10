#ifndef VIEWPLACEHOLDER_H
#define VIEWPLACEHOLDER_H

#include <QWidget>
#include "qmlobject.h"

class ViewPlaceholder : public QmlObject
{
    Q_OBJECT
public:
    explicit ViewPlaceholder(QWidget *parent = 0);

signals:

public slots:
};

#endif // VIEWPLACEHOLDER_H
