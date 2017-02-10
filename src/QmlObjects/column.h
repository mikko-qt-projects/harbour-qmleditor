#ifndef COLUMN_H
#define COLUMN_H

#include "qmlobject.h"

class Column : public QmlObject
{
    Q_OBJECT

public:
    explicit Column(QWidget *parent = 0);
    void paintEvent(QPaintEvent *e);
    void mousePressEvent(QMouseEvent*);
    void mouseMoveEvent(QMouseEvent*);

    QVBoxLayout *getLayout() {return verticalLayout;}

private:
    QVBoxLayout *verticalLayout;
};

#endif // COLUMN_H
