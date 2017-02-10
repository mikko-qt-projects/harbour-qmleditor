#include "xmlcreator.h"

XmlCreator::XmlCreator(QObject *parent) : QObject(parent)
{
    m_doc = QDomDocument("QML");

    QDomElement root = m_doc.createElement("QML");
    m_doc.appendChild(root);

    QDomElement imports = m_doc.createElement("Imports");
    root.appendChild(imports);

    imports.setAttribute("import", "import QtQuick 2.0");
    imports.setAttribute("import", "import Sailfish.Silica 1.0");

    QDomElement page = m_doc.createElement("Page");
    page.setAttribute("property", "id");
    page.setAttribute("value", "page");
    root.appendChild(page);
}

void XmlCreator::insertObject(QString parentObject, QString object)
{
    QDomElement parent_obj = m_doc.elementById(parentObject);

    QDomElement obj = m_doc.createElement(object);
    parent_obj.appendChild(obj);
}

void XmlCreator::insertProperty(QString object, QString property, QString value)
{
    QDomElement obj = m_doc.elementById(object);

    obj.setAttribute("property", property);
    obj.setAttribute("value", value);
}

void XmlCreator::removeObject(QString parentObject, QString object)
{
    QDomElement parent_obj = m_doc.elementById(parentObject);
    QDomElement removedObject = m_doc.elementById(object);
    parent_obj.removeChild(removedObject);
}

void XmlCreator::removeProperty(QString object, QString property)
{
    QDomElement obj = m_doc.elementById(object);
    obj.removeAttribute(property);
}
