#include "qmlcodewidget.h"
#include <QLabel>
#include <QApplication>

QmlCodeWidget::QmlCodeWidget(QWidget *parent) : QWidget(parent)
{
    int pagewidth = qApp->property("pagewidth").toInt();
    int pageheight = qApp->property("pageheight").toInt();

    xml = new XmlCreator;

    createCodeBtn = new QPushButton("Create QML");
    createCodeBtn->setFixedSize(pagewidth/3.273, pageheight/25.6);

    fileName = new QLineEdit;
    fileName->setPlaceholderText("QML filename");
    fileName->setEnabled(false);

    cancelBtn = new QPushButton("Cancel");
    cancelBtn->setFixedSize(pagewidth/3.273, pageheight/25.6);
    cancelBtn->setEnabled(false);

    QWidget *btnwidget = new QWidget;
    btnwidget->setMaximumHeight(pageheight/6.4);

    saveBtn = new QPushButton("Save");
    saveBtn->setFixedSize(pagewidth/3.273, pageheight/25.6);
    saveBtn->setEnabled(false);

    QGridLayout *grid = new QGridLayout;
    grid->addWidget(createCodeBtn, 0, 0, Qt::AlignTop);
    grid->addWidget(fileName, 1, 0, 1, 2, Qt::AlignTop);
    grid->addWidget(new QLabel(".qml"), 1, 2, Qt::AlignLeft);
    grid->addWidget(saveBtn, 2, 0);
    grid->addWidget(cancelBtn, 2, 1);

    btnwidget->setLayout(grid);

    qmlfield = new QTextEdit;
    qmlfield->setFixedSize(pagewidth/1.029, pageheight/1.422);
    qmlfield->setReadOnly(true);

    QPalette palette = qmlfield->palette();
    palette.setColor(QPalette::Base, QColor("#333333"));
    qmlfield->setPalette(palette);


    verticalLayout = new QVBoxLayout;
    verticalLayout->addWidget(btnwidget);
    verticalLayout->addWidget(qmlfield);

    setLayout(verticalLayout);

    connect(createCodeBtn, SIGNAL(pressed()),                           this, SLOT(createCodeBtn_pressed()));
    connect(cancelBtn, SIGNAL(pressed()),                               this, SLOT(cancelBtn_pressed()));
    connect(saveBtn, SIGNAL(pressed()),                                 this, SLOT(saveBtn_pressed()));

    connect(this, SIGNAL(insert_object(QString,QString)),               xml, SLOT(insertObject(QString,QString)));
    connect(this, SIGNAL(insert_property(QString,QString,QString)),     xml, SLOT(insertProperty(QString,QString,QString)));
    connect(this, SIGNAL(remove_object(QString,QString)),               xml, SLOT(removeObject(QString,QString)));
    connect(this, SIGNAL(remove_property(QString,QString)),             xml, SLOT(removeProperty(QString,QString)));
}

void QmlCodeWidget::createCodeBtn_pressed()
{
    fileName->setEnabled(true);
    cancelBtn->setEnabled(true);
    saveBtn->setEnabled(true);
}

void QmlCodeWidget::cancelBtn_pressed()
{
    fileName->setEnabled(false);
    cancelBtn->setEnabled(false);
    saveBtn->setEnabled(false);
    fileName->setText("");
}

void QmlCodeWidget::saveBtn_pressed()
{

}

void QmlCodeWidget::update_qmlcode()
{

}
