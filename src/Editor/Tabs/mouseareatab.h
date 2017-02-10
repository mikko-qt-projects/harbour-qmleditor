#ifndef MOUSEAREATAB_H
#define MOUSEAREATAB_H

#include <QCheckBox>
#include <QLineEdit>
#include <QSpinBox>
#include <QWidget>
#include "customtab.h"
#include "../../QmlObjects/qmlobjects.h"

class MouseAreaTab : public CustomTab
{
    Q_OBJECT
public:
    explicit MouseAreaTab(QWidget *parent = 0);
    void setCurrent(QmlObject *cur);

signals:

public slots:

private:
    MouseArea *mouseArea;

    QCheckBox *mouseAreaEnabled;
    QCheckBox *mouseAreaHoverEnabled;

    ActionComboBox *actionCombo;
    QLineEdit *actionEdit;
};

#endif // MOUSEAREATAB_H
