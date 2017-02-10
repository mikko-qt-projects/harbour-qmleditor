#include "texttab.h"

TextTab::TextTab(QWidget *parent) : CustomTab(parent)
{
    widget->setFixedHeight(largeHeight);

    picker = new ColorPickerWidget;

    grid->addWidget(picker, 0, 0, 4, 4);
    grid->addItem(new QSpacerItem(30, 50), 4,0);

    QWidget *textwidget = new QWidget;
    textwidget->setFixedHeight(smallHeight);

    textEdit = new QLineEdit;
    textEdit->setFixedWidth(pagewidth/1.44);

    sizeEdit = new QSpinBox;
    sizeEdit->setFixedWidth(pagewidth/7.2);
    sizeEdit->setRange(1, 176);
    sizeEdit->setSingleStep(1);

    boldbtn = new QPushButton(tr("B"));
    boldbtn->setFixedWidth(pagewidth/18);
    boldbtn->setCheckable(true);

    italbtn = new QPushButton(tr("I"));
    italbtn->setFixedWidth(pagewidth/18);
    italbtn->setCheckable(true);

    QGridLayout *textgrid = new QGridLayout;
    textgrid->addWidget(new QLabel(tr("Text ")), 0, 0, Qt::AlignTop);
    textgrid->addWidget(textEdit, 0, 1, 0, 4, Qt::AlignTop);
    textgrid->addWidget(new QLabel(tr("Size ")), 1, 0, Qt::AlignTop);
    textgrid->addWidget(sizeEdit, 1, 1, Qt::AlignTop);
    textgrid->addWidget(boldbtn, 1, 2, Qt::AlignTop);
    textgrid->addWidget(italbtn, 1, 3, Qt::AlignTop);
    textgrid->addItem(new QSpacerItem(pagewidth/3, 50), 1, 4);
    textwidget->setLayout(textgrid);

    verticalLayout->addWidget(textwidget);

    connect(picker, SIGNAL(colortoparent(QColor)), this, SLOT(setColorToObject(QColor)));
    connect(textEdit, SIGNAL(textEdited(QString)), this, SLOT(text_edit_changed(QString)));
    connect(boldbtn, SIGNAL(clicked(bool)), this, SLOT(bold_btn_clicked(bool)));
    connect(italbtn, SIGNAL(clicked(bool)), this, SLOT(italic_btn_clicked(bool)));
    connect(sizeEdit, SIGNAL(valueChanged(int)), this, SLOT(size_edit_changed(int)));
}

void TextTab::setCurrent(QmlObject *cur)
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

void TextTab::setColorToEditor(QColor c)
{
    picker->setColor(c);
}

void TextTab::setColorToObject(QColor c)
{
    QPalette p(palette());
    p.setColor(QPalette::Foreground, c);
    text->gettext()->setPalette(p);
    setCurrent(text);
}

void TextTab::text_edit_changed(QString s)
{
    text->gettext()->setText(s);
    QFont font;
    font.setPointSize(text->gettext()->font().pointSize());
    QFontMetrics fm(font);
    text->setGeometry(text->x(), text->y(), fm.width(text->gettext()->text()), fm.height());
    text->gettext()->setGeometry(text->gettext()->x(), text->gettext()->y(), fm.width(text->gettext()->text()), fm.height());
    setCurrent(text);
}

void TextTab::bold_btn_clicked(bool b)
{
    QFont font;
    font.setBold(b);
    font.setPointSize(text->gettext()->font().pointSize());
    text->gettext()->setFont(font);
    QFontMetrics fm(font);
    text->setGeometry(text->x(), text->y(), fm.width(text->gettext()->text()), fm.height());
    text->gettext()->setGeometry(text->gettext()->x(), text->gettext()->y(), fm.width(text->gettext()->text()), fm.height());
    setCurrent(text);
}

void TextTab::italic_btn_clicked(bool b)
{
    QFont font;
    font.setItalic(b);
    font.setPointSize(text->gettext()->font().pointSize());
    text->gettext()->setFont(font);
    QFontMetrics fm(font);
    text->setGeometry(text->x(), text->y(), fm.width(text->gettext()->text()), fm.height());
    text->gettext()->setGeometry(text->gettext()->x(), text->gettext()->y(), fm.width(text->gettext()->text()), fm.height());
    setCurrent(text);
}

void TextTab::size_edit_changed(int s)
{
    QFont font;
    font.setPointSize(s);
    text->gettext()->setFont(font);
    QFontMetrics fm(font);
    text->setGeometry(text->x(), text->y(), fm.width(text->gettext()->text()), fm.height());
    text->gettext()->setGeometry(text->gettext()->x(), text->gettext()->y(), fm.width(text->gettext()->text()), fm.height());
    setCurrent(text);
}
