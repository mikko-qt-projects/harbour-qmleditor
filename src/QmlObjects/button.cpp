#include "button.h"

#include <QPainter>
#include <QPen>

Button::Button(QWidget *parent) : MouseArea(parent)
{
    objectType = "Button";
    m_anchor_fill_enabled = false;
    m_preferredWidthIndex = 0;

    m_borderSize = 0;
    m_radius = 11;

    QColor bg("white");
    bg.setAlpha(37);
    m_backgroundColor = bg;
    QPalette pf(palette());
    pf.setColor(QPalette::Foreground, bg);
    setPalette(pf);

    setGeometry(QRect(0, 0, 294, 88));

    m_buttonColorIndex = 0;
    m_buttonColor = "#d6d7d9";

    m_text = new QLabel(this);
    QPalette p(palette());
    p.setColor(QPalette::Foreground, m_buttonColor);
    m_text->setPalette(p);
    m_text->setText("Button");
    m_text->setAlignment(Qt::AlignCenter);

    QFont font;
    font.setPointSize(32);
    m_text->setFont(font);

    QHBoxLayout* layout = new QHBoxLayout;
    layout->addWidget(m_text);
    setLayout(layout);
}

void Button::paintEvent(QPaintEvent *e)
{

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    QRectF rect(this->rect().x(),
                this->rect().y(),
                this->rect().width(),
                this->rect().height());

    QBrush brush(m_backgroundColor);
    painter.setBrush(brush);

    painter.drawRoundedRect(rect,
                            m_radius,
                            m_radius);

    QWidget::paintEvent(e);
}

void Button::settext(QString s)
{
    m_text->setText(s);
}
