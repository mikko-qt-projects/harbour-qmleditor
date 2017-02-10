#ifndef EMPTYPROPERTY_H
#define EMPTYPROPERTY_H

#include <QWidget>

class EmptyProperty : public QWidget
{
    Q_OBJECT
public:
    explicit EmptyProperty(QWidget *parent = 0);
    void paintEvent(QPaintEvent *);

signals:

public slots:
};

#endif // EMPTYPROPERTY_H
