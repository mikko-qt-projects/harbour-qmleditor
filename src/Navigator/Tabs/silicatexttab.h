#ifndef SILICATEXTTAB_H
#define SILICATEXTTAB_H

#include <QWidget>
#include "custombutton.h"

class NavigatorWidget;

class SilicaTextTab : public QWidget
{
    Q_OBJECT
public:
    explicit SilicaTextTab(NavigatorWidget *nw, QWidget *parent = 0);

signals:
    void detailItemSignal(QmlObject *obj);
    void enterKeySignal(QmlObject *obj);
    void labelSignal(QmlObject *obj);
    void searchFieldSignal(QmlObject *obj);
    void sectionHeaderSignal(QmlObject *obj);
    void pageHeaderSignal(QmlObject *obj);
    void textAreaSignal(QmlObject *obj);
    void textFieldSignal(QmlObject *obj);

public slots:
    void detailItemPressed();
    void enterKeyPressed();
    void labelPressed();
    void searchFieldPressed();
    void sectionHeaderPressed();
    void pageHeaderPressed();
    void textAreaPressed();
    void textFieldPressed();

private:
    NavigatorWidget *n;
    CustomButton *detailItem_btn;
    CustomButton *enterKey_btn;
    CustomButton *label_btn;
    CustomButton *searchField_btn;
    CustomButton *sectionHeader_btn;
    CustomButton *pageHeader_btn;
    CustomButton *textArea_btn;
    CustomButton *textField_btn;

    int detailItem_id;
    int enterKey_id;
    int label_id;
    int searchField_id;
    int sectionHeader_id;
    int pageHeader_id;
    int textArea_id;
    int textField_id;
};

#endif // SILICATEXTTAB_H
