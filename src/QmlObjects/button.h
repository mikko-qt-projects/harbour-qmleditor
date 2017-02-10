#ifndef BUTTON_H
#define BUTTON_H

#include <QWidget>
#include "mousearea.h"
#include "rectangle.h"

class Button : public MouseArea
{
    Q_OBJECT

public:
    explicit Button(QWidget *parent = 0);
    void paintEvent(QPaintEvent *e);

    void settext(QString s);
    void setPrefferedWidthIndex(int i) {m_preferredWidthIndex = i;}
    void setButtonColor(QColor c) {m_buttonColor = c;}
    void setButtonColorIndex(int i) {m_buttonColorIndex = i;}

    QLabel *gettext() {return m_text;}
    int preferredWidthIndex() {return m_preferredWidthIndex;}
    QColor buttonColor() {return m_buttonColor;}
    int buttonColorIndex() {return m_buttonColorIndex;}

signals:

public slots:

private:
    QLabel *m_text;
    int m_preferredWidthIndex;
    QColor m_buttonColor;
    int m_buttonColorIndex;

    int m_radius;
    int m_borderSize;
    QColor m_borderColor;
    QColor m_backgroundColor;
};

#endif // BUTTON_H
