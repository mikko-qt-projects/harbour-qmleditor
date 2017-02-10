#ifndef TYPEITEMS_H
#define TYPEITEMS_H

#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QWidget>
#include "../QmlObjects/qmlobject.h"

class EditorWidget;

class TypeProperty : public QWidget
{
    Q_OBJECT
public:
    explicit TypeProperty(EditorWidget *ew, QWidget *parent = 0);
    void setCurrent(QmlObject *cur);
    void setId(QString s);
    void setType(QString s);

signals:
    void remove_from_navigation(QmlObject *obj);
    void changeCurrent(QmlObject *obj);

public slots:
    void objectName_changed(QString s);
    void deleteObject_pressed();

private:
    EditorWidget *e;

    QmlObject *current;

    QLineEdit *id;
    QLabel *type;
    QPushButton *deleteObject;
};

#endif // TYPEITEMS_H
