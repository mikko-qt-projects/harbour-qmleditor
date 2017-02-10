#ifndef DRAWER_H
#define DRAWER_H

#include <QWidget>
#include "qmlobject.h"

class Drawer : public QmlObject
{
    Q_OBJECT
public:
    explicit Drawer(QWidget *parent = 0);

    void setOpen(bool b) {m_open = b;}
    void setBackground(int i) {m_background = i;}
    void setForeground(int i) {m_foreground = i;}
    void setDock(int i) {m_dock = i;}

    bool open() {return m_open;}
    int background() {return m_background;}
    int foreground() {return m_foreground;}
    int dock() {return m_dock;}

signals:

public slots:

private:
    bool m_open;
    int m_background;       //combobox
    int m_foreground;       //combobox
    int m_dock;             //combobox
};

#endif // DRAWER_H
