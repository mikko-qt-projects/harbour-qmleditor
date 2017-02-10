#ifndef PAGEHEADER_H
#define PAGEHEADER_H

#include <QWidget>
#include "qmlobject.h"

class PageHeader : public QmlObject
{
    Q_OBJECT
public:
    explicit PageHeader(QWidget *parent = 0);

signals:

public slots:
};

#endif // PAGEHEADER_H
