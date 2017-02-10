#ifndef TEXTAREA_H
#define TEXTAREA_H

#include <QWidget>
#include "qmlobject.h"

class TextArea : public QmlObject
{
    Q_OBJECT
public:
    explicit TextArea(QWidget *parent = 0);

signals:

public slots:
};

#endif // TEXTAREA_H
