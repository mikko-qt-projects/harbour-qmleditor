#ifndef XMLCREATOR_H
#define XMLCREATOR_H

#include <QObject>
#include <QDomDocument>

class XmlCreator : public QObject
{
    Q_OBJECT
public:
    explicit XmlCreator(QObject *parent = 0);
    QDomDocument doc() {return m_doc;}

signals:

public slots:
    void insertObject(QString parentObject, QString object);
    void insertProperty(QString object, QString property, QString value);
    void removeObject(QString parentObject, QString object);
    void removeProperty(QString object, QString property);

private:
    QDomDocument m_doc;
};

#endif // XMLCREATOR_H
