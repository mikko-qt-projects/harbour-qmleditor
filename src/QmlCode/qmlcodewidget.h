#ifndef QMLCODEWIDGET_H
#define QMLCODEWIDGET_H

#include <QLineEdit>
#include <QPushButton>
#include <QTextEdit>
#include <QVBoxLayout>
#include <QWidget>
#include "xmlcreator.h"

class QmlCodeWidget : public QWidget
{
    Q_OBJECT
public:
    explicit QmlCodeWidget(QWidget *parent = 0);

signals:
    void insert_object(QString parentObject, QString object);
    void insert_property(QString object, QString property, QString value);
    void remove_object(QString parentObject, QString object);
    void remove_property(QString object, QString property);

public slots:
    void createCodeBtn_pressed();
    void cancelBtn_pressed();
    void saveBtn_pressed();
    void update_qmlcode();

private:
    XmlCreator *xml;    
    QVBoxLayout *verticalLayout;
    QPushButton *createCodeBtn;
    QLineEdit *fileName;
    QPushButton *cancelBtn;
    QTextEdit *qmlfield;
    QPushButton *saveBtn;
};

#endif // QMLCODEWIDGET_H
