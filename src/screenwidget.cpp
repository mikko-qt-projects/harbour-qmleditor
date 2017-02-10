#include "screenwidget.h"
#include <QPainter>
#include <QApplication>

ScreenWidget::ScreenWidget(QWidget *parent) : QWidget(parent)
{
    int pagewidth = qApp->property("pagewidth").toInt();

    i = 0;

    setMinimumWidth(pagewidth);
    setObjectName("background");

    QPalette p(palette());
    p.setColor(QPalette::Background, QColor("black"));
    setAutoFillBackground(true);
    setPalette(p);

    page = new Page(this);
    page->connect(page, SIGNAL(clicked()), this, SLOT(set_by_click()));
    current = page;
    emit current_changed(current);
}

/*void ScreenWidget::paintEvent(QPaintEvent *)
{
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}*/

void ScreenWidget::change_current(QmlObject *newcurrent)
{
    current = newcurrent;
    emit current_changed(current);
    emit nav_changed(current);
}

void ScreenWidget::set_qmlobject(QmlObject *obj)
{
    obj->setParent(current);
    obj->show();

    obj->connect(obj, SIGNAL(clicked()), this, SLOT(set_by_click()));
    obj->connect(obj, SIGNAL(holdandpressed(QmlObject*)), this, SLOT(change_current(QmlObject*)));

    emit qmlobject_to_nav(obj);
    change_current(obj);
}

void ScreenWidget::set_by_nav(QListWidgetItem *item)
{
    QmlObject *obj = this->findChild<QmlObject*>(item->text());
    change_current(obj);
}

void ScreenWidget::set_by_click()
{
    QmlObject* obj = qobject_cast<QmlObject*>(sender());
    if( obj != NULL ) {
        if (current != obj || current == page) {
            change_current(obj);
        }
    }
}

