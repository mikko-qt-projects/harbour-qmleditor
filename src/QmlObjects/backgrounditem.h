#ifndef BACKGROUNDITEM_H
#define BACKGROUNDITEM_H

#include <QWidget>
#include "mousearea.h"

class BackgroundItem : public MouseArea
{
    Q_OBJECT
public:
    explicit BackgroundItem(QWidget *parent = 0);
    void setContentHeight(int i) {m_contentHeight = i;}
    void setContentWidth(int i) {m_contentWidth = i;}

    int contentWidth() {return m_contentWidth;}
    int contentHeight() {return m_contentHeight;}

signals:

public slots:

private:
    int m_contentHeight;
    int m_contentWidth;
};

#endif // BACKGROUNDITEM_H
