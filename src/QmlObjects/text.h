#ifndef TEXT_H
#define TEXT_H

#include <QWidget>
#include "qmlobject.h"

class Text : public QmlObject
{
    Q_OBJECT

public:
    explicit Text(QWidget *parent = 0);
    void settext(QString s);
    QLabel *gettext() {return m_text;}

private:
    QLabel *m_text;
};

#endif // TEXT_H
