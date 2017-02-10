#ifndef DOCKEDPANEL_H
#define DOCKEDPANEL_H

#include <QWidget>
#include "qmlobject.h"

class DockedPanel : public QmlObject
{
    Q_OBJECT
public:
    explicit DockedPanel(QWidget *parent = 0);
    void paintEvent(QPaintEvent *e);
    void setDockIndex(int i)    {m_dockIndex = i;}
    void setWidthIndex(int i)   {m_widthIndex = i;}
    void setHeightIndex(int i)  {m_heightIndex = i;}
    int dockIndex()             {return m_dockIndex;}
    int widthIndex()            {return m_widthIndex;}
    int heightIndex()           {return m_heightIndex;}


signals:

public slots:

private:
    int m_dockIndex;
    int m_widthIndex;
    int m_heightIndex;
};

#endif // DOCKEDPANEL_H
