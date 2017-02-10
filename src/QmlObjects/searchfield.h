#ifndef SEARCHFIELD_H
#define SEARCHFIELD_H

#include <QWidget>
#include "qmlobject.h"

class SearchField : public QmlObject
{
    Q_OBJECT
public:
    explicit SearchField(QWidget *parent = 0);

signals:

public slots:
};

#endif // SEARCHFIELD_H
