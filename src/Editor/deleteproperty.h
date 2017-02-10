#ifndef DELETEPROPERTY_H
#define DELETEPROPERTY_H

#include <QPushButton>
#include <QWidget>
#include "../QmlObjects/qmlobject.h"

class EditorWidget;

class DeleteProperty : public QWidget
{
    Q_OBJECT
public:
    explicit DeleteProperty(EditorWidget *ew, QWidget *parent = 0);
    void setCurrent(QmlObject *cur);

signals:

public slots:
    void deleteObject_pressed();

private:
    EditorWidget *e;
    QmlObject *current;
    QPushButton *deleteObject;
};

#endif // DELETEPROPERTY_H
