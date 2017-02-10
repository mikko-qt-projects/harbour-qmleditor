#ifndef CUSTOMTAB_H
#define CUSTOMTAB_H

#include <QComboBox>
#include <QGridLayout>
#include <QSpinBox>
#include <QWidget>
#include "../../QmlObjects/qmlobjects.h"

class ComponentComboBox : public QComboBox
{
    Q_OBJECT

public:
    explicit ComponentComboBox(QWidget *parent = 0);
};

class PaddingComboBox : public QComboBox
{
    Q_OBJECT

public:
    explicit PaddingComboBox(QWidget *parent = 0);
};

class ItemSizeComboBox : public QComboBox
{
    Q_OBJECT

public:
    explicit ItemSizeComboBox(QWidget *parent = 0);
};

class FontSizeComboBox : public QComboBox
{
    Q_OBJECT

public:
    explicit FontSizeComboBox(QWidget *parent = 0);
};

class ActionComboBox : public QComboBox
{
    Q_OBJECT

public:
    explicit ActionComboBox(QWidget *parent = 0);
};

class ColorComboBox : public QComboBox
{
    Q_OBJECT

public:
    explicit ColorComboBox(QWidget *parent = 0);
};

class ButtonWidthComboBox : public QComboBox
{
    Q_OBJECT

public:
    explicit ButtonWidthComboBox(QWidget *parent = 0);
    void showPopup();
};

class CustomSpinBox : public QSpinBox
{
    Q_OBJECT

public:
    explicit CustomSpinBox(QWidget *parent = 0);
};

class CustomTab : public QWidget
{
    Q_OBJECT
public:
    explicit CustomTab(QWidget *parent = 0);
    virtual void paintEvent(QPaintEvent *);
    virtual void setCurrent(QmlObject *cur);

signals:

public slots:

protected:
    QWidget *widget;
    QGridLayout *grid;
    QVBoxLayout *verticalLayout;
    int pagewidth;
    int pageheight;

    int extraSmallHeight;   //height for 1 line
    int smallHeight;        //height for 2 line
    int mediumHeight;       //height for 3 line
    int largeHeight;        //height for colorpicker (5 line)
    int extraLargeHeight;   //height for full size

};

#endif // CUSTOMTAB_H
