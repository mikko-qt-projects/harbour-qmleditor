#include "typeitems.h"
#include "editorwidget.h"

TypeItems::TypeItems(EditorWidget *plw, QWidget *parent) : QGroupBox(parent), p(plw)
{
    QGroupBox *typeID = new QGroupBox(tr("Type"), this);
    setMinimumHeight(200);
    setMinimumWidth(640);

    type = new QLabel;
    id = new QLineEdit;

    QGridLayout *typegrid = new QGridLayout(typeID);
    typegrid->addWidget(new QLabel(tr("Type ")), 0, 0, Qt::AlignTop);
    typegrid->addWidget(type, 0, 1, Qt::AlignTop);
    typegrid->addWidget(new QLabel(tr("Id ")), 1, 0, Qt::AlignTop);
    typegrid->addWidget(id, 1, 1, Qt::AlignTop);
    setLayout(typegrid);

    connect(id, SIGNAL(textEdited(QString)), p, SLOT(objectName_changed(QString)));
    connect(id, SIGNAL(textEdited(QString)), p, SIGNAL(nameChanged(QString)));
}

void TypeItems::setId(QString s)
{
    id->setText(s);
}

void TypeItems::setType(QString s)
{
    type->setText(s);
}
