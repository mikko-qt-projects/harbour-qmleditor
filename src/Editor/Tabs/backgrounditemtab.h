#ifndef BACKGROUNDITEMTAB_H
#define BACKGROUNDITEMTAB_H

#include <QCheckBox>
#include <QLineEdit>
#include <QSpinBox>
#include <QWidget>
#include "customtab.h"
#include "../../QmlObjects/qmlobjects.h"

class BackgroundItemTab : public CustomTab
{
    Q_OBJECT
public:
    explicit BackgroundItemTab(QWidget *parent = 0);
    void setCurrent(QmlObject *cur);

signals:

public slots:

private:
    BackgroundItem *bgItem;

    ItemSizeComboBox *contHeight;
    ComponentComboBox *contWidth;

    QCheckBox *mouseAreaEnabled;
    QCheckBox *mouseAreaHoverEnabled;
    ActionComboBox *actionCombo;
    QLineEdit *actionEdit;
};

#endif // BACKGROUNDITEMTAB_H
