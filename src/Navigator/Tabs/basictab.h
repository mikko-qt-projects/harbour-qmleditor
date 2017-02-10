#ifndef BASICTAB_H
#define BASICTAB_H

#include <QWidget>
#include <QGridLayout>
#include "custombutton.h"

class NavigatorWidget;

class BasicTab : public QWidget
{
    Q_OBJECT
public:
    explicit BasicTab(NavigatorWidget *nw, QWidget *parent = 0);

signals:
    void componentSignal(QmlObject *obj);
    void imageSignal(QmlObject *obj);
    void itemSignal(QmlObject *obj);
    void mouseAreaSignal(QmlObject *obj);
    void rectangleSignal(QmlObject *obj);
    void textSignal(QmlObject *obj);
    void columnSignal(QmlObject *obj);
    void rowSignal(QmlObject *obj);

public slots:
    void componentPressed();
    void imagePressed();
    void itemPressed();
    void mouseAreaPressed();
    void rectanglePressed();
    void textPressed();
    void columnPressed();
    void rowPressed();

private:
    NavigatorWidget *n;
    CustomButton *component_btn;
    CustomButton *image_btn;
    CustomButton *item_btn;
    CustomButton *mouseArea_btn;
    CustomButton *rectangle_btn;
    CustomButton *text_btn;
    CustomButton *column_btn;
    CustomButton *row_btn;

    int component_id;
    int image_id;
    int item_id;
    int mouseArea_id;
    int rectangle_id;
    int text_id;
    int column_id;
    int row_id;
};

#endif // BASICTAB_H
