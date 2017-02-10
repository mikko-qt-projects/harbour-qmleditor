#ifndef COMBOBOX_H
#define COMBOBOX_H

#include <QWidget>
#include "qmlobject.h"

class ComboBox : public QmlObject
{
    Q_OBJECT
public:
    explicit ComboBox(QWidget *parent = 0);

    void setValue_2(QString t)      {m_value_2 = t;}
    void setValue_3(QString t)      {m_value_3 = t;}
    void setValue_4(QString t)      {m_value_4 = t;}
    void setValue_5(QString t)      {m_value_5 = t;}
    void setValue_2_enabled(bool b) {m_value_2_enabled = b;}
    void setValue_3_enabled(bool b) {m_value_3_enabled = b;}
    void setValue_4_enabled(bool b) {m_value_4_enabled = b;}
    void setValue_5_enabled(bool b) {m_value_5_enabled = b;}
    QLabel *header()                 {return m_header;}
    QLabel *description()            {return m_description;}
    QLabel *value_1()                {return m_value_1;}
    QString value_2()               {return m_value_2;}
    QString value_3()               {return m_value_3;}
    QString value_4()               {return m_value_4;}
    QString value_5()               {return m_value_5;}
    bool value_2_enabled()          {return m_value_2_enabled;}
    bool value_3_enabled()          {return m_value_3_enabled;}
    bool value_4_enabled()          {return m_value_4_enabled;}
    bool value_5_enabled()          {return m_value_5_enabled;}


signals:

public slots:

private:
    QLabel *m_header;
    QLabel *m_description;
    QLabel *m_value_1;
    QString m_value_2;
    QString m_value_3;
    QString m_value_4;
    QString m_value_5;

    bool m_value_2_enabled;
    bool m_value_3_enabled;
    bool m_value_4_enabled;
    bool m_value_5_enabled;

};

#endif // COMBOBOX_H
