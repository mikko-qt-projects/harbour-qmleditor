#ifndef QMLLISTVIEW_H
#define QMLLISTVIEW_H

#include <QWidget>
#include "qmlobject.h"

class SilicaListView : public QmlObject
{
    Q_OBJECT
public:
    explicit SilicaListView(QWidget *parent = 0);

    void setSpacing(int i) {m_spacing = i;}
    void setDelegate(QmlObject *qml) {m_delegate = qml;}
    void setModel(QmlObject *qml) {m_model = qml;}
    void setHighlight(QmlObject *qml) {m_highlight = qml;}
    void setHeader(QmlObject *qml) {m_header = qml;}
    void setFooter(QmlObject *qml) {m_footer = qml;}

    int spacing() {return m_spacing;}
    QmlObject *delegate() {return m_delegate;}
    QmlObject *model() {return m_model;}
    QmlObject *highlight() {return m_highlight;}
    QmlObject *header() {return m_header;}
    QmlObject *footer() {return m_footer;}

signals:

public slots:

private:
    int m_spacing;
    QmlObject *m_delegate;
    QmlObject *m_model;
    QmlObject *m_highlight;
    QmlObject *m_header;
    QmlObject *m_footer;
};

#endif // QMLLISTVIEW_H
