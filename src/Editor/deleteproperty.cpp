#include "deleteproperty.h"
#include "editorwidget.h"
#include <QApplication>

DeleteProperty::DeleteProperty(EditorWidget *ew, QWidget *parent) : QWidget(parent), e(ew)
{
    int pagewidth = qApp->property("pagewidth").toInt();
    int pageheight = qApp->property("pageheight").toInt();

    setFixedHeight(pageheight/32);

    current = NULL;

    deleteObject = new QPushButton("Delete");
    deleteObject->setFixedSize(pagewidth/3.789, pageheight/32);

    QGridLayout *grid = new QGridLayout;
    grid->addItem(new QSpacerItem(pagewidth/1.385, pageheight/32), 0, 0);
    grid->addWidget(deleteObject, 0, 1, Qt::AlignBottom);
    setLayout(grid);

    connect(deleteObject, SIGNAL(pressed()), this, SLOT(deleteObject_pressed()));
}

void DeleteProperty::setCurrent(QmlObject *cur)
{
    current = cur;

    deleteObject->setEnabled(current->getObjectType() != "Page");
}

void DeleteProperty::deleteObject_pressed()
{
    if (current != NULL) {
        QmlObject *parentObject = qobject_cast<QmlObject*>(current->parent());
        delete current;
        e->set_current(parentObject);
    }
}
