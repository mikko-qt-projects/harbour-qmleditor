#ifndef ICONTEXTSWITCH_H
#define ICONTEXTSWITCH_H

#include <QWidget>
#include "qmlobject.h"

class IconTextSwitch : public QmlObject
{
    Q_OBJECT
public:
    explicit IconTextSwitch(QWidget *parent = 0);
    QLabel *mainText() {return m_mainText;}
    QLabel *descriptionText() {return m_descriptionText;}

signals:

public slots:

private:
    QLabel *m_mainText;
    QLabel *m_descriptionText;
};

#endif // ICONTEXTSWITCH_H
