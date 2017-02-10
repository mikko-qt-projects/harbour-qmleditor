#include "combobox.h"

ComboBox::ComboBox(QWidget *parent) : QmlObject(parent)
{
    objectType = "ComboBox";

    m_anchor_fill_enabled = false;
    m_width_enabled = false;
    m_height_enabled = false;
    m_x_combobox_enabled = false;
    m_width_combobox_enabled = false;
    m_height_combobox_enabled = false;

    m_header = new QLabel(this);
    m_value_1 = new QLabel(this);
    m_description = new QLabel(this);

    QPalette ph(palette());
    ph.setColor(QPalette::Foreground, QColor("#aeaeae"));
    m_header->setPalette(ph);
    QFont font_h;
    font_h.setPointSize(28);
    m_header->setFont(font_h);
    m_header->setText("label");

    QPalette pv(palette());
    pv.setColor(QPalette::Foreground, QColor("#67cbcb"));
    m_value_1->setPalette(pv);
    QFont font_v;
    font_v.setPointSize(28);
    m_value_1->setFont(font_v);
    m_value_1->setText("value");

    QPalette pd(palette());
    pd.setColor(QPalette::Foreground, QColor("#717171"));
    m_description->setPalette(pd);
    QFont font_d;
    font_d.setPointSize(24);
    m_description->setFont(font_d);
    m_description->setText(" ");

    m_value_2 = "";
    m_value_3 = "";
    m_value_4 = "";
    m_value_5 = "";

    m_value_2_enabled = false;
    m_value_3_enabled = false;
    m_value_4_enabled = false;
    m_value_5_enabled = false;

    QFontMetrics fm(font_h);
    m_header->setGeometry(0, 0, fm.width(m_header->text()), 28);
    m_value_1->setGeometry(m_header->width() + 20, 0, fm.width(m_value_1->text()), 28);

    QFontMetrics fm_d(font_d);
    m_description->setGeometry(0, 46, fm_d.width(m_description->text()), 24);

    setGeometry(x(), y(), m_header->width() + 20 + m_value_1->width(), 70);
}

