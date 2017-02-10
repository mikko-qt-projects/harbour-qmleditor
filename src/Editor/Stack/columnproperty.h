#ifndef COLUMNPROPERTY_H
#define COLUMNPROPERTY_H

#include <QSpinBox>
#include <QWidget>
#include "../../qmlobject.h"

class EditorWidget;

class ColumnProperty : public QWidget
{
    Q_OBJECT
public:
    explicit ColumnProperty(EditorWidget *ew, QWidget *parent = 0);
    void paintEvent(QPaintEvent *);
    void setCurrent(QmlObject *cur);

signals:

public slots:
    void setSpacing(int i);

private:
    EditorWidget *e;
    Column *col;
    QSpinBox *spacing;
};

#endif // COLUMNPROPERTY_H
