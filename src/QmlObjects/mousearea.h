#ifndef MOUSEAREA_H
#define MOUSEAREA_H

#include <QWidget>
#include "qmlobject.h"

class MouseArea : public QmlObject
{
    Q_OBJECT
public:
    explicit MouseArea(QWidget *parent = 0);

    void setMouseAreaEnabled(bool b) {m_mouseAreaEnabled = b;}
    void setMouseAreaHoverEnabled(bool b) {m_mouseAreaHoverEnabled = b;}
    void setAction(int i) {m_action = i;}
    void setActionText(QString s) {m_actionText = s;}

    bool mouseAreaEnabled() {return m_mouseAreaEnabled;}
    bool mouseAreaHoverEnabled() {return m_mouseAreaHoverEnabled;}
    int action() {return m_action;}
    QString actionText() {return m_actionText;}

signals:

public slots:

private:
    bool m_mouseAreaEnabled;
    bool m_mouseAreaHoverEnabled;

    int m_action;
    QString m_actionText;
};

#endif // MOUSEAREA_H
