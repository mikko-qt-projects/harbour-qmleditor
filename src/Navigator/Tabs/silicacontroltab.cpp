#include "silicacontroltab.h"
#include "../navigatorwidget.h"

SilicaControlTab::SilicaControlTab(NavigatorWidget *nw, QWidget *parent) : QWidget(parent), n(nw)
{
    button_id = 0;
    colorPicker_id = 0;
    comboBox_id = 0;
    datePicker_id = 0;
    iconButton_id = 0;
    iconTextSwitch_id = 0;
    slider_id = 0;
    switch_id = 0;
    textSwitch_id = 0;
    timePicker_id = 0;
    valueButton_id = 0;

    QPalette p(palette());
    p.setColor(QPalette::Background, QColor("#3f3f3f"));
    setAutoFillBackground(true);
    setPalette(p);

    button_btn = new CustomButton("Button");
    colorPicker_btn = new CustomButton("Color\nPicker");
    comboBox_btn = new CustomButton("ComboBox");
    datePicker_btn = new CustomButton("Date\nPicker");
    iconButton_btn = new CustomButton("Icon\nButton");
    iconTextSwitch_btn = new CustomButton("IconText\nSwitch");
    slider_btn = new CustomButton("Slider");
    switch_btn = new CustomButton("Switch");
    textSwitch_btn = new CustomButton("Text\nSwitch");
    timePicker_btn = new CustomButton("Time\nPicker");
    valueButton_btn = new CustomButton("Value\nButton");

    QGridLayout *grid = new QGridLayout;
    grid->addWidget(button_btn, 0, 0);
    grid->addWidget(iconButton_btn, 0, 1);
    grid->addWidget(valueButton_btn, 0, 2);
    grid->addWidget(switch_btn, 0, 3);
    grid->addWidget(textSwitch_btn, 1, 0);
    grid->addWidget(iconTextSwitch_btn, 1, 1);
    grid->addWidget(slider_btn, 1, 2);
    grid->addWidget(comboBox_btn, 1, 3);
    grid->addWidget(colorPicker_btn, 2, 0);
    grid->addWidget(timePicker_btn, 2, 1);
    grid->addWidget(datePicker_btn, 2, 2);
    setLayout(grid);

    connect(button_btn,             SIGNAL(pressed()), this, SLOT(buttonPressed()));
    connect(comboBox_btn,           SIGNAL(pressed()), this, SLOT(comboBoxPressed()));
    connect(iconButton_btn,         SIGNAL(pressed()), this, SLOT(iconButtonPressed()));
    connect(switch_btn,             SIGNAL(pressed()), this, SLOT(switchPressed()));
    connect(valueButton_btn,        SIGNAL(pressed()), this, SLOT(valueButtonPressed()));
    connect(iconTextSwitch_btn,     SIGNAL(pressed()), this, SLOT(iconTextSwitchPressed()));
    connect(slider_btn,             SIGNAL(pressed()), this, SLOT(sliderPressed()));
    connect(colorPicker_btn,        SIGNAL(pressed()), this, SLOT(colorPickerPressed()));
    connect(timePicker_btn,         SIGNAL(pressed()), this, SLOT(timePickerPressed()));
    connect(datePicker_btn,         SIGNAL(pressed()), this, SLOT(datePickerPressed()));
    connect(textSwitch_btn,         SIGNAL(pressed()), this, SLOT(textSwitchPressed()));

    connect(this, SIGNAL(buttonSignal(QmlObject*)),             n, SIGNAL(qmlobject_signal(QmlObject*)));
    connect(this, SIGNAL(comboBoxSignal(QmlObject*)),           n, SIGNAL(qmlobject_signal(QmlObject*)));
    connect(this, SIGNAL(iconButtonSignal(QmlObject*)),         n, SIGNAL(qmlobject_signal(QmlObject*)));
    connect(this, SIGNAL(switchSignal(QmlObject*)),             n, SIGNAL(qmlobject_signal(QmlObject*)));
    connect(this, SIGNAL(valueButtonSignal(QmlObject*)),        n, SIGNAL(qmlobject_signal(QmlObject*)));
    connect(this, SIGNAL(iconTextSwitchSignal(QmlObject*)),     n, SIGNAL(qmlobject_signal(QmlObject*)));
    connect(this, SIGNAL(sliderSignal(QmlObject*)),             n, SIGNAL(qmlobject_signal(QmlObject*)));
    connect(this, SIGNAL(colorPickerSignal(QmlObject*)),        n, SIGNAL(qmlobject_signal(QmlObject*)));
    connect(this, SIGNAL(timePickerSignal(QmlObject*)),         n, SIGNAL(qmlobject_signal(QmlObject*)));
    connect(this, SIGNAL(datePickerSignal(QmlObject*)),         n, SIGNAL(qmlobject_signal(QmlObject*)));
    connect(this, SIGNAL(textSwitchSignal(QmlObject*)),         n, SIGNAL(qmlobject_signal(QmlObject*)));

}

void SilicaControlTab::buttonPressed()
{
    QmlObject *button = new Button;
    button->setObjectName("button_" + QString::number(button_id));
    button_id++;
    emit buttonSignal(button);
}

void SilicaControlTab::colorPickerPressed()
{
    QmlObject *colorPicker = new ColorPicker;
    colorPicker->setObjectName("colorPicker_" + QString::number(colorPicker_id));
    colorPicker_id++;
    emit colorPickerSignal(colorPicker);
}

void SilicaControlTab::comboBoxPressed()
{
    QmlObject *comboBox = new ComboBox;
    comboBox->setObjectName("comboBox_" + QString::number(comboBox_id));
    comboBox_id++;
    emit comboBoxSignal(comboBox);
}

void SilicaControlTab::datePickerPressed()
{
    QmlObject *datePicker = new DatePicker;
    datePicker->setObjectName("datePicker_" + QString::number(datePicker_id));
    datePicker_id++;
    emit datePickerSignal(datePicker);
}

void SilicaControlTab::iconButtonPressed()
{
    QmlObject *iconButton = new IconButton;
    iconButton->setObjectName("iconButton_" + QString::number(iconButton_id));
    iconButton_id++;
    emit iconButtonSignal(iconButton);
}

void SilicaControlTab::iconTextSwitchPressed()
{
    QmlObject *iconTextSwitch = new IconTextSwitch;
    iconTextSwitch->setObjectName("iconTextSwitch_" + QString::number(iconTextSwitch_id));
    iconTextSwitch_id++;
    emit iconTextSwitchSignal(iconTextSwitch);
}

void SilicaControlTab::sliderPressed()
{
    QmlObject *slider = new Slider;
    slider->setObjectName("slider_" + QString::number(slider_id));
    slider_id++;
    emit sliderSignal(slider);
}

void SilicaControlTab::switchPressed()
{
    QmlObject *switch_o = new Switch;
    switch_o->setObjectName("switch_" + QString::number(switch_id));
    switch_id++;
    emit switchSignal(switch_o);
}

void SilicaControlTab::textSwitchPressed()
{
    QmlObject *textSwitch = new TextSwitch;
    textSwitch->setObjectName("textSwitch_" + QString::number(textSwitch_id));
    textSwitch_id++;
    emit textSwitchSignal(textSwitch);
}

void SilicaControlTab::timePickerPressed()
{
    QmlObject *timePicker = new TimePicker;
    timePicker->setObjectName("timePicker_" + QString::number(timePicker_id));
    timePicker_id++;
    emit timePickerSignal(timePicker);
}

void SilicaControlTab::valueButtonPressed()
{
    QmlObject *valueButton = new ValueButton;
    valueButton->setObjectName("valueButton_" + QString::number(valueButton_id));
    valueButton_id++;
    emit valueButtonSignal(valueButton);
}
