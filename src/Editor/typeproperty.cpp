#include "typeproperty.h"
#include "editorwidget.h"
#include <QApplication>

TypeProperty::TypeProperty(EditorWidget *ew, QWidget *parent) : QWidget(parent), e(ew)
{
    int pagewidth = qApp->property("pagewidth").toInt();
    int pageheight = qApp->property("pageheight").toInt();

    setFixedHeight(pageheight/9.15);

    type = new QLabel;
    id = new QLineEdit;
    id->setFixedWidth(pagewidth/2.4);

    deleteObject = new QPushButton("Delete");
    deleteObject->setFixedSize(pagewidth/6, pageheight/25.6);

    QGridLayout *typegrid = new QGridLayout(this);
    typegrid->addWidget(new QLabel(tr("Type ")), 0, 0, Qt::AlignTop);
    typegrid->addWidget(type, 0, 1, Qt::AlignTop);
    typegrid->addWidget(deleteObject, 0, 2, Qt::AlignRight);
    typegrid->addWidget(new QLabel(tr("Id ")), 1, 0, Qt::AlignTop);
    typegrid->addWidget(id, 1, 1, Qt::AlignTop);
    typegrid->addItem(new QSpacerItem(pagewidth/2.4, 50), 1, 2);

    connect(id, SIGNAL(textEdited(QString)),                    this, SLOT(objectName_changed(QString)));
    connect(id, SIGNAL(textEdited(QString)),                    e, SIGNAL(name_changed(QString)));
    connect(deleteObject, SIGNAL(pressed()),                    this, SLOT(deleteObject_pressed()));
    connect(this, SIGNAL(remove_from_navigation(QmlObject*)),   e, SIGNAL(remove_from_nav(QmlObject*)));
    connect(this, SIGNAL(changeCurrent(QmlObject*)),            e, SIGNAL(current_changed(QmlObject*)));
}

void TypeProperty::setCurrent(QmlObject *cur)
{
    current = cur;

    setType(current->getObjectType());
    setId(current->objectName());
    deleteObject->setEnabled(current->getObjectType() != "Page");
}

void TypeProperty::setId(QString s)
{
    id->setText(s);
}

void TypeProperty::setType(QString s)
{
    type->setText(s);
}

void TypeProperty::objectName_changed(QString s)
{
    current->setObjectName(s);
}

void TypeProperty::deleteObject_pressed()
{
    if (current != NULL) {
        QmlObject *parentObject = qobject_cast<QmlObject*>(current->parent());

        while ( QmlObject* obj = findChild<QmlObject*>() )
            emit remove_from_navigation(obj);

        emit remove_from_navigation(current);
        delete current;
        emit changeCurrent(parentObject);
    }
}
