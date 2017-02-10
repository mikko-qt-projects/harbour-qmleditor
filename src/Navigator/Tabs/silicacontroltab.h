#ifndef SILICACONTROLTAB_H
#define SILICACONTROLTAB_H

#include <QWidget>
#include "custombutton.h"

class NavigatorWidget;

class SilicaControlTab : public QWidget
{
    Q_OBJECT
public:
    explicit SilicaControlTab(NavigatorWidget *nw, QWidget *parent = 0);

signals:
    void buttonSignal(QmlObject *obj);
    void colorPickerSignal(QmlObject *obj);
    void comboBoxSignal(QmlObject *obj);
    void datePickerSignal(QmlObject *obj);
    void iconButtonSignal(QmlObject *obj);
    void iconTextSwitchSignal(QmlObject *obj);
    void sliderSignal(QmlObject *obj);
    void switchSignal(QmlObject *obj);
    void textSwitchSignal(QmlObject *obj);
    void timePickerSignal(QmlObject *obj);
    void valueButtonSignal(QmlObject *obj);

public slots:
    void buttonPressed();
    void colorPickerPressed();
    void comboBoxPressed();
    void datePickerPressed();
    void iconButtonPressed();
    void iconTextSwitchPressed();
    void sliderPressed();
    void switchPressed();
    void textSwitchPressed();
    void timePickerPressed();
    void valueButtonPressed()
;
private:
    NavigatorWidget *n;
    CustomButton *button_btn;
    CustomButton *colorPicker_btn;
    CustomButton *comboBox_btn;
    CustomButton *datePicker_btn;
    CustomButton *iconButton_btn;
    CustomButton *iconTextSwitch_btn;
    CustomButton *slider_btn;
    CustomButton *switch_btn;
    CustomButton *textSwitch_btn;
    CustomButton *timePicker_btn;
    CustomButton *valueButton_btn;

    int button_id;
    int colorPicker_id;
    int comboBox_id;
    int datePicker_id;
    int iconButton_id;
    int iconTextSwitch_id;
    int slider_id;
    int switch_id;
    int textSwitch_id;
    int timePicker_id;
    int valueButton_id;
};

#endif // SILICACONTROLTAB_H
