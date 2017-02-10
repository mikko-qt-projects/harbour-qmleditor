#ifndef TYPEITEMS_H
#define TYPEITEMS_H

#include <QGroupBox>
#include <QLabel>
#include <QLineEdit>
#include <QWidget>

class EditorWidget;

class TypeItems : public QGroupBox
{
    Q_OBJECT
public:
    explicit TypeItems(EditorWidget *plw, QWidget *parent = 0);
    void setId(QString s);
    void setType(QString s);

signals:

public slots:

private:
    EditorWidget *p;
    QLineEdit *id;
    QLabel *type;
};

#endif // TYPEITEMS_H
