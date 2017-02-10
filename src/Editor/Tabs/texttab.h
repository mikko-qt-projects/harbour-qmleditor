#ifndef TEXTTAB_H
#define TEXTTAB_H

#include <QLineEdit>
#include <QSpinBox>
#include <QWidget>
#include "colorpicker/colorpickerwidget.h"
#include "../../QmlObjects/qmlobjects.h"
#include "customtab.h"

class TextTab : public CustomTab
{
    Q_OBJECT
    
public:
    explicit TextTab(QWidget *parent = 0);
    void setCurrent(QmlObject *cur);
    void setColorToEditor(QColor c);

public slots:
    void setColorToObject(QColor c);
    void text_edit_changed(QString s);
    void bold_btn_clicked(bool b);
    void italic_btn_clicked(bool b);
    void size_edit_changed(int s);
    
private:
    Text *text;
    ColorPickerWidget *picker;
    QLineEdit *textEdit;
    QSpinBox *sizeEdit;
    QPushButton *boldbtn;
    QPushButton *italbtn;
  
};

#endif // LABELPROPERTY_H
