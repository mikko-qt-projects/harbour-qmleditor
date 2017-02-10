#ifndef BUTTONTAB_H
#define BUTTONTAB_H

#include <QCheckBox>
#include <QLineEdit>
#include <QWidget>
#include "customtab.h"
#include "../../QmlObjects/qmlobjects.h"

class ButtonTab : public CustomTab
{
    Q_OBJECT
public:
    explicit ButtonTab(QWidget *parent = 0);
    void setCurrent(QmlObject *cur);

signals:

public slots:
    void buttonWidthChanged(int i);
    void buttonColorChanged(int i);

private:
    Button *button;
    ButtonWidthComboBox *buttonWidthCombo;
    ColorComboBox *colorCombo;

    QCheckBox *mouseAreaEnabled;
    QCheckBox *mouseAreaHoverEnabled;
    ActionComboBox *actionCombo;
    QLineEdit *actionEdit;

    QList<QSize> buttonWidth;
    QList<QColor> color;
};

#endif // BUTTONTAB_H
