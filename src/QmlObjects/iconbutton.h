#ifndef ICONBUTTON_H
#define ICONBUTTON_H

#include <QWidget>
#include "qmlobject.h"

class IconButton : public QmlObject
{
    Q_OBJECT
public:
    explicit IconButton(QWidget *parent = 0);
    void paintEvent(QPaintEvent *e);
    void setImageSource(QString t) {m_imageSource = t;}
    QString imageSource() {return m_imageSource;}

signals:

public slots:

private:
    QString m_imageSource;
};

#endif // ICONBUTTON_H
