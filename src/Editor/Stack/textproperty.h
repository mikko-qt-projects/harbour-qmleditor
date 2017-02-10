#ifndef LABELPROPERTY_H
#define LABELPROPERTY_H

#include <QLineEdit>
#include <QSpinBox>
#include <QWidget>
#include "colorpicker/colorpickerwidget.h"
#include "../../qmlobject.h"

class EditorWidget;

class TextProperty : public QWidget
{
    Q_OBJECT
    
public:
    explicit TextProperty(EditorWidget *ew, QWidget *parent = 0);
    void paintEvent(QPaintEvent *);
    void setCurrent(QmlObject *cur);
    void setColorToEditor(QColor c);

public slots:
    void setColorToObject(QColor c);
    void text_edit_changed(QString s);
    void bold_btn_clicked(bool b);
    void italic_btn_clicked(bool b);
    void size_edit_changed(int s);
    
private:
    EditorWidget *e;
    Text *text;
    ColorPickerWidget *picker;
    QLineEdit *textEdit;
    QSpinBox *sizeEdit;
    QPushButton *boldbtn;
    QPushButton *italbtn;
  
};

#endif // LABELPROPERTY_H
