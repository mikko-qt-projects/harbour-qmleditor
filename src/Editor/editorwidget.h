#ifndef EDITORWIDGET_H
#define EDITORWIDGET_H

#include <QTabWidget>
#include <QWidget>
#include <QPushButton>
#include <QScrollArea>
#include <QVBoxLayout>
#include <QGroupBox>
#include <QLineEdit>
#include <QLabel>
#include <QCheckBox>
#include <QColorDialog>
#include <QStackedWidget>
#include <QPointer>
#include "Tabs/tabs.h"
#include "../QmlObjects/qmlobjects.h"
#include "geometryproperty.h"
#include "typeproperty.h"
#include "customtabwidget.h"

class EditorWidget : public QWidget
{
    Q_OBJECT
public:
    explicit EditorWidget(QWidget *parent = 0);

signals:
    void current_changed(QmlObject *cur);
    void remove_from_nav(QmlObject *obj);
    void name_changed(QString s);

public slots:
    void set_current(QmlObject *cur);
    void update_current();

private:
    QVBoxLayout *verticalLayout;
    QmlObject *current;

    TypeProperty *typeitems;
    GeometryProperty *geometry;
    QStackedWidget *stack;

    QPointer<CustomTabWidget> currentTabWidget;

    QPointer<CustomTab> mainTab;
    QPointer<CustomTab> layoutTab;


};

#endif // EDITORWIDGET_H
