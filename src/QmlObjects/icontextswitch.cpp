#include "icontextswitch.h"

IconTextSwitch::IconTextSwitch(QWidget *parent) : QmlObject(parent)
{
    objectType = "IconTextSwitch";

    m_anchor_fill_enabled = false;
    m_width_enabled = false;
    m_height_enabled = false;
    m_x_combobox_enabled = false;
    m_width_combobox_enabled = false;
    m_height_combobox_enabled = false;

    setGeometry(0, 0, 142, 720);

    m_mainText = new QLabel(this);
    m_descriptionText = new QLabel(this);

    QPalette pm(palette());
    pm.setColor(QPalette::Foreground, QColor("#d8d8d8"));
    m_mainText->setPalette(pm);
    QFont font_m;
    font_m.setPointSize(28);
    m_mainText->setFont(font_m);
    m_mainText->setText("IconTextSwitch");

    QPalette pd(palette());
    pd.setColor(QPalette::Foreground, QColor("#757575"));
    m_descriptionText->setPalette(pd);
    QFont font_d;
    font_d.setPointSize(24);
    m_descriptionText->setFont(font_d);
    m_descriptionText->setText("description text");

    QFontMetrics fm_m(font_m);
    QFontMetrics fm_d(font_d);

    m_mainText->setGeometry(90, 36, fm_m.width(m_mainText->text()), 28);
    m_descriptionText->setGeometry(88, 84, fm_d.width(m_descriptionText->text()), 24);

    QLabel *imageLabel = new QLabel(this);
    imageLabel->setGeometry(28, 36, 15, 15);
    imageLabel->setPixmap(QPixmap("qrc:/res/images/switch.png"));

    QWidget *iconWidget = new QWidget(this);
    iconWidget->setGeometry(628, 24, 25, 25);
}
