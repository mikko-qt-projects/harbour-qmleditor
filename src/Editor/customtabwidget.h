#ifndef CUSTOMTABWIDGET_H
#define CUSTOMTABWIDGET_H

#include <QTabWidget>
#include <QWidget>

class CustomTabWidget : public QTabWidget
{
    Q_OBJECT
public:
    explicit CustomTabWidget(QWidget *parent = 0);

signals:

public slots:
};

#endif // CUSTOMTABWIDGET_H
