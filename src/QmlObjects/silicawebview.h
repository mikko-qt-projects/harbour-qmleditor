#ifndef SILICAWEBVIEW_H
#define SILICAWEBVIEW_H

#include <QWidget>
#include "qmlobject.h"

class SilicaWebView : public QmlObject
{
    Q_OBJECT
public:
    explicit SilicaWebView(QWidget *parent = 0);

signals:

public slots:
};

#endif // SILICAWEBVIEW_H
