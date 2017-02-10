#ifndef GEOMETRYITEMS_H
#define GEOMETRYITEMS_H

#include <QLineEdit>
#include <QWidget>
#include <QGroupBox>
#include <QGridLayout>

class EditorWidget;

class GeometryItems : public QGroupBox
{
    Q_OBJECT
public:
    explicit GeometryItems(EditorWidget *plw, QWidget *parent = 0);
    void setXpos(int x);
    void setYpos(int y);
    void setWidth(int w);
    void setHeight(int h);
    void setXposVisible(bool b);
    void setYposVisible(bool b);
    void setWidthVisible(bool b);
    void setHeightVisible(bool b);

signals:

public slots:

private:
    EditorWidget *p;
    QLineEdit *xpos;
    QLineEdit *ypos;
    QLineEdit *width;
    QLineEdit *height;
};

#endif // GEOMETRYITEMS_H
