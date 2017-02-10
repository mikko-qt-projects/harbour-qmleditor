#include "detailitem.h"

DetailItem::DetailItem(QWidget *parent) : QmlObject(parent)
{
    objectType = "DetailItem";

    m_anchor_fill_enabled = false;
    m_width_enabled = false;
    m_height_enabled = false;
    m_x_combobox_enabled = false;
    m_width_combobox_enabled = false;
    m_height_combobox_enabled = false;

    m_label = new QLabel(this);
    m_value = new QLabel(this);

    QPalette pl(palette());
    pl.setColor(QPalette::Foreground, QColor("#3e697a"));
    m_label->setPalette(pl);
    QFont font;
    font.setPointSize(28);
    m_label->setFont(font);
    m_label->setText("label");

    QPalette pv(palette());
    pv.setColor(QPalette::Foreground, QColor("#5db9b9"));
    m_value->setPalette(pv);
    font.setPointSize(28);
    m_value->setFont(font);
    m_value->setText("value");

    QFontMetrics fm(font);
    m_label->setGeometry(0, 0, fm.width(m_label->text()), 28);
    m_value->setGeometry(m_label->width() + 20, 0, fm.width(m_value->text()), 28);

    setGeometry(x(), y(), m_label->width() + 20 + m_value->width(), 28);

}
