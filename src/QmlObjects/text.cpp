#include "text.h"

Text::Text(QWidget *parent) : QmlObject(parent)
{
    objectType = "Text";
    m_anchor_fill_enabled = false;
    m_width_enabled = false;
    m_height_enabled = false;
    m_width_combobox_enabled = false;
    m_height_combobox_enabled = false;

    m_text = new QLabel(this);
    QPalette p(palette());
    p.setColor(QPalette::Foreground, QColor("white"));
    m_text->setPalette(p);
    m_text->setText("Text");

    QFont font;
    font.setPointSize(32);
    m_text->setFont(font);

    setGeometry(m_text->geometry());
}

void Text::settext(QString s)
{
    m_text->setText(s);
}
