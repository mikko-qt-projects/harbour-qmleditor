#ifndef SILICAITEMTAB_H
#define SILICAITEMTAB_H

#include <QWidget>
#include "custombutton.h"

class NavigatorWidget;

class SilicaItemTab : public QWidget
{
    Q_OBJECT
public:
    explicit SilicaItemTab(NavigatorWidget *nw, QWidget *parent = 0);

signals:
    void backGroundItemSignal(QmlObject *obj);
    void busyIndicatorSignal(QmlObject *obj);
    void keypadSignal(QmlObject *obj);
    void listItemSignal(QmlObject *obj);
    void progressBarSignal(QmlObject *obj);
    void remorseItemSignal(QmlObject *obj);
    void remorsePopupSignal(QmlObject *obj);
    void separatorSignal(QmlObject *obj);
    void touchBlockerSignal(QmlObject *obj);

public slots:
    void backGroundItemPressed();
    void busyIndicatorPressed();
    void keypadPressed();
    void listItemPressed();
    void progressBarPressed();
    void remorseItemPressed();
    void remorsePopupPressed();
    void separatorPressed();
    void touchBlockerPressed();

private:
    NavigatorWidget *n;
    CustomButton *backgroundItem_btn;
    CustomButton *busyIndicator_btn;
    CustomButton *keypad_btn;
    CustomButton *listItem_btn;
    CustomButton *progressBar_btn;
    CustomButton *remorseItem_btn;
    CustomButton *remorsePopup_btn;
    CustomButton *separator_btn;
    CustomButton *touchBlocker_btn;

    int backGroundItem_id;
    int busyIndicator_id;
    int keypad_id;
    int listItem_id;
    int progressBar_id;
    int remorseItem_id;
    int remorsePopup_id;
    int separator_id;
    int touchBlocker_id;

};

#endif // SILICAITEMTAB_H
