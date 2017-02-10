#ifndef PROGRESSBAR_H
#define PROGRESSBAR_H

#include <QWidget>
#include "qmlobject.h"

class ProgressBar : public QmlObject
{
    Q_OBJECT
public:
    explicit ProgressBar(QWidget *parent = 0);

signals:

public slots:
};

#endif // PROGRESSBAR_H
