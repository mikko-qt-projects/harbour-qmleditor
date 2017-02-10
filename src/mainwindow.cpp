#include "mainwindow.h"
#include <QApplication>
#include <QScreen>

MainWindow::MainWindow(QWidget *parent) : QWidget(parent)
{
    QScreen* screen = QGuiApplication::primaryScreen();
    int pagewidth = screen->size().width();
    int pageheight = screen->size().height();

    //QApplication's property method is used as global variable
    qApp->setProperty("pagewidth", pagewidth);
    qApp->setProperty("pageheight", pageheight);

    QPalette p(palette());
    p.setColor(QPalette::Background, QColor("#333333"));
    p.setColor(QPalette::Foreground, QColor("white"));
    setAutoFillBackground(true);
    setPalette(p);

    QFont font;
    font.setPointSize(pageheight/53.3);
    setFont(font);

    QWidget *widget = new QWidget(this);

    s = new ScreenWidget;
    n = new NavigatorWidget;
    e = new EditorWidget;
    q = new QmlCodeWidget;

    stack = new QStackedWidget;
    stack->addWidget(n);
    stack->addWidget(s);
    stack->addWidget(e);
    stack->addWidget(q);
    stack->setFixedSize(pagewidth, pageheight*0.953);
    stack->setCurrentIndex(0);

    navigatorbutton = new QPushButton(tr("Navigation"));
    navigatorbutton->setFixedSize(pagewidth/4.1, pageheight/25.6);
    navigatorbutton->setCheckable(true);

    screenbutton = new QPushButton(tr("Screen"));
    screenbutton->setFixedSize(pagewidth/4.1, pageheight/25.6);
    screenbutton->setCheckable(true);

    editorbutton = new QPushButton(tr("Editor"));
    editorbutton->setFixedSize(pagewidth/4.1, pageheight/25.6);
    editorbutton->setCheckable(true);

    qmlcodebutton = new QPushButton(tr("QML"));
    qmlcodebutton->setFixedSize(pagewidth/4.1, pageheight/25.6);
    qmlcodebutton->setCheckable(true);

    navigatorbutton->setChecked(true);
    navigatorbutton->setEnabled(false);

    maingrid = new QGridLayout(this);
    maingrid->addWidget(stack, 0, 0, 12, 4);
    maingrid->addWidget(navigatorbutton, 12, 0);
    maingrid->addWidget(screenbutton, 12, 1);
    maingrid->addWidget(editorbutton, 12, 2);
    maingrid->addWidget(qmlcodebutton, 12, 3);
    maingrid->setContentsMargins(0, 0, 0, 0);

    widget->setLayout(maingrid);

    connect(navigatorbutton, SIGNAL(clicked(bool)),         this, SLOT(on_navigator_button_clicked(bool)));
    connect(screenbutton, SIGNAL(clicked(bool)),            this, SLOT(on_screen_button_clicked(bool)));
    connect(editorbutton, SIGNAL(clicked(bool)),            this, SLOT(on_editor_button_clicked(bool)));
    connect(qmlcodebutton, SIGNAL(clicked(bool)),           this, SLOT(on_qmlcode_button_clicked(bool)));

    connect(n, SIGNAL(nav_clicked(QListWidgetItem*)),       s, SLOT(set_by_nav(QListWidgetItem*)));
    connect(n, SIGNAL(qmlobject_signal(QmlObject*)),        s, SLOT(set_qmlobject(QmlObject*)));
    connect(s, SIGNAL(qmlobject_to_nav(QmlObject*)),        n, SLOT(add_nav_item(QmlObject*)));
    connect(s, SIGNAL(nav_changed(QmlObject*)),             n, SLOT(nav_changed(QmlObject*)));
    connect(s, SIGNAL(current_changed(QmlObject*)),         e, SLOT(set_current(QmlObject*)));
    connect(e, SIGNAL(current_changed(QmlObject*)),         s, SLOT(change_current(QmlObject*)));
    connect(e, SIGNAL(name_changed(QString)),               n, SIGNAL(name_changed(QString)));
    connect(e, SIGNAL(remove_from_nav(QmlObject*)),         n, SIGNAL(remove_nav_item(QmlObject*)));
}

void MainWindow::paintEvent(QPaintEvent *)
{
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}

void MainWindow::on_navigator_button_clicked(bool b)
{
    navigatorbutton->setEnabled(!b);
    screenbutton->setEnabled(b);
    editorbutton->setEnabled(b);
    qmlcodebutton->setEnabled(b);

    stack->setCurrentIndex(0);
    navigatorbutton->setChecked(b);
    screenbutton->setChecked(!b);
    editorbutton->setChecked(!b);
    qmlcodebutton->setChecked(!b);
}

void MainWindow::on_screen_button_clicked(bool b)
{
    navigatorbutton->setEnabled(b);
    screenbutton->setEnabled(!b);
    editorbutton->setEnabled(b);
    qmlcodebutton->setEnabled(b);

    stack->setCurrentIndex(1);
    navigatorbutton->setChecked(!b);
    screenbutton->setChecked(b);
    editorbutton->setChecked(!b);
    qmlcodebutton->setChecked(!b);
}

void MainWindow::on_editor_button_clicked(bool b)
{
    navigatorbutton->setEnabled(b);
    screenbutton->setEnabled(b);
    editorbutton->setEnabled(!b);
    qmlcodebutton->setEnabled(b);

    stack->setCurrentIndex(2);
    navigatorbutton->setChecked(!b);
    screenbutton->setChecked(!b);
    editorbutton->setChecked(b);
    qmlcodebutton->setChecked(!b);
}

void MainWindow::on_qmlcode_button_clicked(bool b)
{
    navigatorbutton->setEnabled(b);
    screenbutton->setEnabled(b);
    editorbutton->setEnabled(b);
    qmlcodebutton->setEnabled(!b);

    stack->setCurrentIndex(3);
    navigatorbutton->setChecked(!b);
    screenbutton->setChecked(!b);
    editorbutton->setChecked(!b);
    qmlcodebutton->setChecked(b);
}




