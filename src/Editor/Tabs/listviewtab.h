#ifndef LISTVIEWTAB_H
#define LISTVIEWTAB_H

#include <QCheckBox>
#include <QComboBox>
#include <QSpinBox>
#include <QWidget>
#include "customtab.h"
#include "../../QmlObjects/qmlobjects.h"

class SilicaListViewTab : public CustomTab
{
    Q_OBJECT
public:
    explicit SilicaListViewTab(QWidget *parent = 0);
    void setCurrent(QmlObject *cur);

signals:

public slots:

private:
    SilicaListView *listView;
    QSpinBox *spacing;

    QComboBox *modelbox;
    QComboBox *delegatebox;
    QComboBox *highlightbox;
    QComboBox *headerbox;
    QComboBox *footerbox;

    QCheckBox *highlightcheck;
    QCheckBox *headercheck;
    QCheckBox *footercheck;

};

#endif // LISTVIEWTAB_H
