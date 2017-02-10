#ifndef COMBOBOXTAB_H
#define COMBOBOXTAB_H

#include <QLineEdit>
#include <QPushButton>
#include <QWidget>
#include "../../QmlObjects/qmlobjects.h"
#include "customtab.h"

class NewLineButton : public QPushButton
{
    Q_OBJECT

public:
    explicit NewLineButton(QWidget *parent = 0);
};


class ComboBoxTab : public CustomTab
{
    Q_OBJECT
public:
    explicit ComboBoxTab(QWidget *parent = 0);
    void setCurrent(QmlObject *cur);

signals:

public slots:
    void header_changed(QString t);
    void description_changed(QString t);
    void value_1_changed(QString t);
    void value_2_changed(QString t);
    void value_3_changed(QString t);
    void value_4_changed(QString t);
    void value_5_changed(QString t);
    void add_line_1_clicked();
    void add_line_2_clicked();
    void add_line_3_clicked();
    void add_line_4_clicked();

private:
    ComboBox *comboBox;

    QLineEdit *label;
    QLineEdit *description;

    QLineEdit *value_1;
    QLineEdit *value_2;
    QLineEdit *value_3;
    QLineEdit *value_4;
    QLineEdit *value_5;

    NewLineButton *add_line_1;
    NewLineButton *add_line_2;
    NewLineButton *add_line_3;
    NewLineButton *add_line_4;
    
    QLabel *menuText_1;
    QLabel *menuText_2;
    QLabel *menuText_3;
    QLabel *menuText_4;
    QLabel *menuText_5;
    

};

#endif // COMBOBOXTAB_H
