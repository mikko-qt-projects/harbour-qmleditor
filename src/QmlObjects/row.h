#ifndef ROW_H
#define ROW_H

#include <QWidget>
#include "qmlobject.h"

class Row : public QmlObject
{
    Q_OBJECT

public:
    explicit Row(QWidget *parent = 0);
    void mousePressEvent(QMouseEvent*);
    void mouseMoveEvent(QMouseEvent*);

    QHBoxLayout *getLayout() {return horizontalLayout;}

private:
    QHBoxLayout *horizontalLayout;
};

#endif // ROW_H
