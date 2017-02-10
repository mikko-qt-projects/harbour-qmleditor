#ifndef CUSTOMBUTTON_H
#define CUSTOMBUTTON_H

#include <QPushButton>
#include <QWidget>
#include "../../QmlObjects/qmlobject.h"
#include "../../QmlObjects/qmlobjects.h"

class CustomButton : public QPushButton
{
    Q_OBJECT
public:
    explicit CustomButton(QString text, QWidget *parent = 0);

signals:

public slots:

private:

};

#endif // CUSTOMBUTTON_H
