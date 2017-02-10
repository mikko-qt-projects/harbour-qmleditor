#ifndef POSITIONTAB_H
#define POSITIONTAB_H

#include <QPushButton>
#include <QWidget>

class NavigatorWidget;

class PositionTab : public QWidget
{
    Q_OBJECT
public:
    explicit PositionTab(NavigatorWidget *nw, QWidget *parent = 0);

signals:

public slots:

private:
    NavigatorWidget *n;
    QPushButton *column_btn;
    QPushButton *row_btn;
};

#endif // POSITIONTAB_H
