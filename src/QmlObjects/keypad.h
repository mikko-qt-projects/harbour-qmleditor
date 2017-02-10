#ifndef KEYPAD_H
#define KEYPAD_H

#include <QWidget>
#include "qmlobject.h"

class Keypad : public QmlObject
{
    Q_OBJECT
public:
    explicit Keypad(QWidget *parent = 0);

signals:

public slots:
};

#endif // KEYPAD_H
