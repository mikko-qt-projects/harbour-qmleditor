#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>

#include <QHBoxLayout>
#include "screenwidget.h"
#include "Navigator/navigatorwidget.h"
#include "Editor/editorwidget.h"
#include "QmlCode/qmlcodewidget.h"

class MainWindow : public QWidget
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);
    void paintEvent(QPaintEvent *);

public slots:
    void on_navigator_button_clicked(bool b);
    void on_screen_button_clicked(bool b);
    void on_editor_button_clicked(bool b);
    void on_qmlcode_button_clicked(bool b);

private:
    QGridLayout *maingrid;
    QPushButton *navigatorbutton;
    QPushButton *screenbutton;
    QPushButton *editorbutton;
    QPushButton *qmlcodebutton;
    QStackedWidget *stack;
    ScreenWidget *s;
    NavigatorWidget *n;
    EditorWidget *e;
    QmlCodeWidget *q;
};

#endif // MAINWINDOW_H
