#ifndef ROWPROPERTY_H
#define ROWPROPERTY_H
#include <QSpinBox>
#include <QWidget>
#include "../../qmlobject.h"

class EditorWidget;

class RowProperty : public QWidget
{
    Q_OBJECT
public:
    explicit RowProperty(EditorWidget *ew, QWidget *parent = 0);
    void paintEvent(QPaintEvent *);
    void setCurrent(QmlObject *cur);

signals:

public slots:
    void setSpacing(int i);

private:
    EditorWidget *e;
    Row *row;
    QSpinBox *spacing;
};
#endif // ROWPROPERTY_H
