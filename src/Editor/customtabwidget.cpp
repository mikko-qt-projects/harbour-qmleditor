#include "customtabwidget.h"
#include <QTableWidget>

CustomTabWidget::CustomTabWidget(QWidget *parent) : QTabWidget(parent)
{
    QPalette p = this->tabBar()->palette();
    p.setColor(QPalette::Button, QColor("#333333"));
    p.setColor(QPalette::ButtonText, QColor("white"));
    this->tabBar()->setAutoFillBackground(true);
    this->tabBar()->setPalette(p);
}
