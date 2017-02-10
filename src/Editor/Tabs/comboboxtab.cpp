#include "comboboxtab.h"

NewLineButton::NewLineButton(QWidget *parent) : QPushButton(parent)
{
    setFixedSize(42, 42);
    setText("+");
}

ComboBoxTab::ComboBoxTab(QWidget *parent) : CustomTab(parent)
{
    widget->setFixedHeight(mediumHeight);

    label = new QLineEdit;
    description = new QLineEdit;

    grid->addWidget(new QLabel(tr("label")), 0, 0, Qt::AlignTop);
    grid->addWidget(label, 0, 1, Qt::AlignTop);
    grid->addWidget(new QLabel(tr("description")), 1, 0, Qt::AlignTop);
    grid->addWidget(description, 1, 1, Qt::AlignTop);
    grid->addWidget(new QLabel(tr("menu: contextMenu {")), 2, 0, 2, 2, Qt::AlignTop);


    QWidget *widget_2 = new QWidget;
    widget_2->setFixedHeight(largeHeight);
    
    menuText_1 = new QLabel("MenuItem text:");
    menuText_2 = new QLabel("MenuItem text:");
    menuText_3 = new QLabel("MenuItem text:");
    menuText_4 = new QLabel("MenuItem text:");
    menuText_5 = new QLabel("MenuItem text:");

    value_1 = new QLineEdit;
    value_1->setFixedWidth(pagewidth/2.4);
    value_2 = new QLineEdit;
    value_2->setFixedWidth(pagewidth/2.4);
    value_3 = new QLineEdit;
    value_3->setFixedWidth(pagewidth/2.4);
    value_4 = new QLineEdit;
    value_4->setFixedWidth(pagewidth/2.4);
    value_5 = new QLineEdit;
    value_5->setFixedWidth(pagewidth/2.4);
    
    add_line_1 = new NewLineButton;
    add_line_2 = new NewLineButton;
    add_line_3 = new NewLineButton;
    add_line_4 = new NewLineButton;
    

    QGridLayout *grid_2 = new QGridLayout;
    grid_2->addWidget(menuText_1,   0, 0, Qt::AlignTop);
    grid_2->addWidget(value_1,      0, 1, Qt::AlignTop);
    grid_2->addWidget(add_line_1,   0, 2, Qt::AlignTop);
    grid_2->addItem(new QSpacerItem(20, 50), 0, 3);
    grid_2->addWidget(menuText_2,   1, 0, Qt::AlignTop);
    grid_2->addWidget(value_2,      1, 1, Qt::AlignTop);
    grid_2->addWidget(add_line_2,   1, 2, Qt::AlignTop);
    grid_2->addItem(new QSpacerItem(20, 50), 1, 3);
    grid_2->addWidget(menuText_3,   2, 0, Qt::AlignTop);
    grid_2->addWidget(value_3,      2, 1, Qt::AlignTop);
    grid_2->addWidget(add_line_3,   2, 2, Qt::AlignTop);
    grid_2->addItem(new QSpacerItem(20, 50), 2, 3);
    grid_2->addWidget(menuText_4,   3, 0, Qt::AlignTop);
    grid_2->addWidget(value_4,      3, 1, Qt::AlignTop);
    grid_2->addWidget(add_line_4,   3, 2, Qt::AlignTop);
    grid_2->addItem(new QSpacerItem(20, 50), 3, 3);
    grid_2->addWidget(menuText_5,   4, 0, Qt::AlignTop);
    grid_2->addWidget(value_5,      4, 1, Qt::AlignTop);
    grid_2->addItem(new QSpacerItem(20, 50), 4, 3);

    widget_2->setLayout(grid_2);
    verticalLayout->addWidget(widget_2);

    connect(label, SIGNAL(textChanged(QString)), this, SLOT(header_changed(QString)));
    connect(description, SIGNAL(textChanged(QString)), this, SLOT(description_changed(QString)));
    connect(value_1, SIGNAL(textChanged(QString)), this, SLOT(value_1_changed(QString)));
    connect(value_2, SIGNAL(textChanged(QString)), this, SLOT(value_2_changed(QString)));
    connect(value_3, SIGNAL(textChanged(QString)), this, SLOT(value_3_changed(QString)));
    connect(value_4, SIGNAL(textChanged(QString)), this, SLOT(value_4_changed(QString)));
    connect(value_5, SIGNAL(textChanged(QString)), this, SLOT(value_5_changed(QString)));
    connect(add_line_1, SIGNAL(pressed()), this, SLOT(add_line_1_clicked()));
    connect(add_line_2, SIGNAL(pressed()), this, SLOT(add_line_2_clicked()));
    connect(add_line_3, SIGNAL(pressed()), this, SLOT(add_line_3_clicked()));
    connect(add_line_4, SIGNAL(pressed()), this, SLOT(add_line_4_clicked()));

}

void ComboBoxTab::setCurrent(QmlObject *cur)
{
    comboBox = qobject_cast<ComboBox*>(cur);
    if (comboBox) {
        label->setText(comboBox->header()->text());
        description->setText(comboBox->description()->text());

        value_1->setText(comboBox->value_1()->text());
        value_2->setText(comboBox->value_2());
        value_3->setText(comboBox->value_3());
        value_4->setText(comboBox->value_4());
        value_5->setText(comboBox->value_5());

        menuText_2->setVisible(comboBox->value_2_enabled());
        value_2->setVisible(comboBox->value_2_enabled());
        add_line_2->setVisible(comboBox->value_2_enabled());

        menuText_3->setVisible(comboBox->value_3_enabled());
        value_3->setVisible(comboBox->value_3_enabled());
        add_line_3->setVisible(comboBox->value_3_enabled());

        menuText_4->setVisible(comboBox->value_4_enabled());
        value_4->setVisible(comboBox->value_4_enabled());
        add_line_4->setVisible(comboBox->value_4_enabled());

        menuText_5->setVisible(comboBox->value_5_enabled());
        value_5->setVisible(comboBox->value_5_enabled());
    }
}

void ComboBoxTab::header_changed(QString t)
{
    comboBox->header()->setText(t);
    QFont font;
    font.setPointSize(28);
    QFontMetrics fm(font);
    comboBox->header()->setGeometry(0, 0, fm.width(comboBox->header()->text()), 28);
    comboBox->value_1()->setGeometry(comboBox->header()->width() + 20, 0, fm.width(comboBox->value_1()->text()), 28);

    QFont font_d;
    font_d.setPointSize(24);
    QFontMetrics fm_d(font_d);
    comboBox->description()->setGeometry(0, 46, fm_d.width(comboBox->description()->text()), 24);

    comboBox->setGeometry(comboBox->x(), comboBox->y(), comboBox->header()->width() + 20 + comboBox->value_1()->width(), 70);

    setCurrent(comboBox);
}

void ComboBoxTab::description_changed(QString t)
{
    comboBox->description()->setText(t);
    QFont font;
    font.setPointSize(28);
    QFontMetrics fm(font);
    comboBox->header()->setGeometry(0, 0, fm.width(comboBox->header()->text()), 28);
    comboBox->value_1()->setGeometry(comboBox->header()->width() + 20, 0, fm.width(comboBox->value_1()->text()), 28);

    QFont font_d;
    font_d.setPointSize(24);
    QFontMetrics fm_d(font_d);
    comboBox->description()->setGeometry(0, 46, fm_d.width(comboBox->description()->text()), 24);

    comboBox->setGeometry(comboBox->x(), comboBox->y(), comboBox->header()->width() + 20 + comboBox->value_1()->width(), 70);

    setCurrent(comboBox);
}

void ComboBoxTab::value_1_changed(QString t)
{
    comboBox->value_1()->setText(t);
    QFont font;
    font.setPointSize(28);
    QFontMetrics fm(font);
    comboBox->header()->setGeometry(0, 0, fm.width(comboBox->header()->text()), 28);
    comboBox->value_1()->setGeometry(comboBox->header()->width() + 20, 0, fm.width(comboBox->value_1()->text()), 28);

    QFont font_d;
    font_d.setPointSize(24);
    QFontMetrics fm_d(font_d);
    comboBox->description()->setGeometry(0, 46, fm_d.width(comboBox->description()->text()), 24);

    comboBox->setGeometry(comboBox->x(), comboBox->y(), comboBox->header()->width() + 20 + comboBox->value_1()->width(), 70);

    setCurrent(comboBox);
}

void ComboBoxTab::value_2_changed(QString t)
{
    comboBox->setValue_2(t);
    setCurrent(comboBox);
}

void ComboBoxTab::value_3_changed(QString t)
{
    comboBox->setValue_3(t);
    setCurrent(comboBox);
}

void ComboBoxTab::value_4_changed(QString t)
{
    comboBox->setValue_4(t);
    setCurrent(comboBox);
}

void ComboBoxTab::value_5_changed(QString t)
{
    comboBox->setValue_5(t);
    setCurrent(comboBox);
}

void ComboBoxTab::add_line_1_clicked()
{
    comboBox->setValue_2_enabled(true);
    setCurrent(comboBox);
}

void ComboBoxTab::add_line_2_clicked()
{
    comboBox->setValue_3_enabled(true);
    setCurrent(comboBox);
}

void ComboBoxTab::add_line_3_clicked()
{
    comboBox->setValue_4_enabled(true);
    setCurrent(comboBox);
}

void ComboBoxTab::add_line_4_clicked()
{
    comboBox->setValue_5_enabled(true);
    setCurrent(comboBox);
}

