#include "textproperty.h"
#include "../editorwidget.h"

#include <QStyleOption>

TextProperty::TextProperty(EditorWidget *ew, QWidget *parent) : QWidget(parent), e(ew)
{
    setMinimumHeight(660);
    QPalette p(palette());
    p.setColor(QPalette::Background, QColor("#3f3f3f"));
    p.setColor(QPalette::Foreground, QColor("white"));
    setAutoFillBackground(true);
    setPalette(p);

    QWidget *colorwidget = new QWidget;
    colorwidget->setMinimumHeight(390);

    picker = new ColorPickerWidget;

    QGridLayout *colorgrid = new QGridLayout;
    colorgrid->addWidget(picker, 0, 0, 4, 4);
    colorgrid->addItem(new QSpacerItem(30, 50), 4,0);
    colorwidget->setLayout(colorgrid);

    QWidget *textwidget = new QWidget;
    textwidget->setMinimumHeight(120);

    textEdit = new QLineEdit;
    textEdit->setFixedWidth(500);

    sizeEdit = new QSpinBox;
    sizeEdit->setFixedWidth(100);
    sizeEdit->setRange(1, 176);
    sizeEdit->setSingleStep(1);

    boldbtn = new QPushButton(tr("B"));
    boldbtn->setFixedWidth(40);
    boldbtn->setCheckable(true);

    italbtn = new QPushButton(tr("I"));
    italbtn->setFixedWidth(40);
    italbtn->setCheckable(true);

    QGridLayout *textgrid = new QGridLayout;
    textgrid->addWidget(new QLabel(tr("Text ")), 0, 0, Qt::AlignTop);
    textgrid->addWidget(textEdit, 0, 1, 0, 4, Qt::AlignTop);
    textgrid->addWidget(new QLabel(tr("Size ")), 1, 0, Qt::AlignTop);
    textgrid->addWidget(sizeEdit, 1, 1, Qt::AlignTop);
    textgrid->addWidget(boldbtn, 1, 2, Qt::AlignTop);
    textgrid->addWidget(italbtn, 1, 3, Qt::AlignTop);
    textgrid->addItem(new QSpacerItem(240, 50), 1, 4);
    textwidget->setLayout(textgrid);

    QVBoxLayout *verticalLayout = new QVBoxLayout;
    verticalLayout->addWidget(colorwidget);
    verticalLayout->addWidget(textwidget);
    verticalLayout->setAlignment(Qt::AlignTop);
    setLayout(verticalLayout);

    connect(picker, SIGNAL(colortoparent(QColor)), this, SLOT(setColorToObject(QColor)));
    connect(textEdit, SIGNAL(textEdited(QString)), this, SLOT(text_edit_changed(QString)));
    connect(boldbtn, SIGNAL(clicked(bool)), this, SLOT(bold_btn_clicked(bool)));
    connect(italbtn, SIGNAL(clicked(bool)), this, SLOT(italic_btn_clicked(bool)));
    connect(sizeEdit, SIGNAL(valueChanged(int)), this, SLOT(size_edit_changed(int)));
}

void TextProperty::paintEvent(QPaintEvent *)
{
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}

void TextProperty::setCurrent(QmlObject *cur)
{
    text = qobject_cast<Text*>(cur);
    if (text) {
        setColorToEditor(text->gettext()->palette().color(QPalette::Foreground));
        textEdit->setText(text->gettext()->text());
        sizeEdit->setValue(text->gettext()->font().pointSize());
        boldbtn->setChecked(text->gettext()->font().bold());
        italbtn->setChecked(text->gettext()->font().italic());
    }
}

void TextProperty::setColorToEditor(QColor c)
{
    picker->setColor(c);
}

void TextProperty::setColorToObject(QColor c)
{
    QPalette p(palette());
    p.setColor(QPalette::Foreground, c);
    text->gettext()->setPalette(p);
    e->setCurrent(text);
}

void TextProperty::text_edit_changed(QString s)
{
    text->gettext()->setText(s);
    QFont font;
    font.setPointSize(text->gettext()->font().pointSize());
    QFontMetrics fm(font);
    text->setGeometry(text->x(), text->y(), fm.width(text->gettext()->text()), fm.height());
    text->gettext()->setGeometry(text->gettext()->x(), text->gettext()->y(), fm.width(text->gettext()->text()), fm.height());
    e->setCurrent(text);
}

void TextProperty::bold_btn_clicked(bool b)
{
    QFont font;
    font.setBold(b);
    font.setPointSize(text->gettext()->font().pointSize());
    text->gettext()->setFont(font);
    QFontMetrics fm(font);
    text->setGeometry(text->x(), text->y(), fm.width(text->gettext()->text()), fm.height());
    text->gettext()->setGeometry(text->gettext()->x(), text->gettext()->y(), fm.width(text->gettext()->text()), fm.height());
    e->setCurrent(text);
}

void TextProperty::italic_btn_clicked(bool b)
{
    QFont font;
    font.setItalic(b);
    font.setPointSize(text->gettext()->font().pointSize());
    text->gettext()->setFont(font);
    QFontMetrics fm(font);
    text->setGeometry(text->x(), text->y(), fm.width(text->gettext()->text()), fm.height());
    text->gettext()->setGeometry(text->gettext()->x(), text->gettext()->y(), fm.width(text->gettext()->text()), fm.height());
    e->setCurrent(text);
}

void TextProperty::size_edit_changed(int s)
{
    QFont font;
    font.setPointSize(s);
    text->gettext()->setFont(font);
    QFontMetrics fm(font);
    text->setGeometry(text->x(), text->y(), fm.width(text->gettext()->text()), fm.height());
    text->gettext()->setGeometry(text->gettext()->x(), text->gettext()->y(), fm.width(text->gettext()->text()), fm.height());
    e->setCurrent(text);
}
