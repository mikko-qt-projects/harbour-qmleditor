#ifndef OBJECTS_H
#define OBJECTS_H

#include <QLabel>
#include <QPaintEvent>
#include <QTimer>
#include <QVBoxLayout>
#include <QWidget>

class QmlObject : public QWidget
{
    Q_OBJECT

public:
    explicit QmlObject(QWidget *parent = 0);

    virtual void paintEvent(QPaintEvent*);

    virtual void mousePressEvent(QMouseEvent *event);
    virtual void mouseMoveEvent(QMouseEvent *event);
    virtual void mouseReleaseEvent(QMouseEvent*);

    virtual QString getObjectType()                 {return objectType;}

    virtual bool x_enabled()                        {return m_x_enabled;}
    virtual bool y_enabled()                        {return m_y_enabled;}
    virtual bool width_enabled()                    {return m_width_enabled;}
    virtual bool height_enabled()                   {return m_height_enabled;}

    virtual void set_x_enabled(bool b)              {m_x_enabled = b;}
    virtual void set_y_enabled(bool b)              {m_y_enabled = b;}
    virtual void set_width_enabled(bool b)          {m_width_enabled = b;}
    virtual void set_height_enabled(bool b)         {m_height_enabled = b;}

    virtual bool dragging_enabled()                 {return m_dragging_enabled;}
    virtual void set_dragging_enabled(bool b)       {m_dragging_enabled = b;}

    virtual bool anchor_fill_checked()              {return m_anchor_fill_checked;}
    virtual bool anchor_horizontalCenter_checked()  {return m_anchor_horizontalCenter_checked;}
    virtual bool anchor_verticalCenter_checked()    {return m_anchor_verticalCenter_checked;}
    virtual bool anchor_top_checked()               {return m_anchor_top_checked;}
    virtual bool anchor_bottom_checked()            {return m_anchor_bottom_checked;}
    virtual bool anchor_left_checked()              {return m_anchor_left_checked;}
    virtual bool anchor_right_checked()             {return m_anchor_right_checked;}

    virtual bool anchor_fill_enabled()              {return m_anchor_fill_enabled;}
    virtual bool anchor_positions_enabled()         {return m_anchor_positions_enabled;}

    virtual bool x_combobox_enabled()               {return m_x_combobox_enabled;}
    virtual bool width_combobox_enabled()           {return m_width_combobox_enabled;}
    virtual bool height_combobox_enabled()          {return m_height_combobox_enabled;}

    virtual void setX_combobox_enabled(bool b)      {m_x_combobox_enabled = b;}
    virtual void setWidth_combobox_enabled(bool b)  {m_width_combobox_enabled = b;}
    virtual void setHeight_combobox_enabled(bool b) {m_height_combobox_enabled = b;}

    virtual int x_combobox_index()                 {return m_x_combobox_index;}
    virtual int width_combobox_index()             {return m_width_combobox_index;}
    virtual int height_combobox_index()            {return m_height_combobox_index;}

    virtual void setX_combobox_index(int i)          {m_x_combobox_index = i;}
    virtual void setWidth_combobox_index(int i)      {m_width_combobox_index = i;}
    virtual void setHeight_combobox_index(int i)     {m_height_combobox_index = i;}

    virtual void setAnchor_fill_checked(bool b)                 {m_anchor_fill_checked = b;}
    virtual void setAnchor_horizontalCenter_checked(bool b)     {m_anchor_horizontalCenter_checked = b;}
    virtual void setAnchor_verticalCenter_checked(bool b)       {m_anchor_verticalCenter_checked = b;}
    virtual void setAnchor_top_checked(bool b)      {m_anchor_top_checked = b;}
    virtual void setAnchor_bottom_checked(bool b)   {m_anchor_bottom_checked = b;}
    virtual void setAnchor_left_checked(bool b)     {m_anchor_left_checked = b;}
    virtual void setAnchor_right_checked(bool b)    {m_anchor_right_checked = b;}

    virtual int anchor_top_margin()                 {return m_anchor_top_margin;}
    virtual int anchor_bottom_margin()              {return m_anchor_bottom_margin;}
    virtual int anchor_left_margin()                {return m_anchor_left_margin;}
    virtual int anchor_right_margin()               {return m_anchor_right_margin;}
    virtual int anchor_horizontalCenter_margin()    {return m_anchor_horizontalCenter_margin;}
    virtual int anchor_verticalCenter_margin()      {return m_anchor_verticalCenter_margin;}

    virtual void setAnchor_top_margin(int i)        {m_anchor_top_margin = i;}
    virtual void setAnchor_bottom_margin(int i)     {m_anchor_bottom_margin = i;}
    virtual void setAnchor_left_margin(int i)       {m_anchor_left_margin = i;}
    virtual void setAnchor_right_margin(int i)      {m_anchor_right_margin = i;}
    virtual void setAnchor_horizontalCenter_margin(int i)   {m_anchor_horizontalCenter_margin = i;}
    virtual void setAnchor_verticalCenter_margin(int i)     {m_anchor_verticalCenter_margin = i;}

    virtual void setAnchor_fill_enabled(bool b)             {m_anchor_fill_enabled = b;}
    virtual void setAnchor_positions_enabled(bool b)        {m_anchor_positions_enabled = b;}


signals:
    void clicked();
    void holdandpressed(QmlObject *t);

protected:
    QString objectType;
    QPoint offset;

    bool m_x_enabled;
    bool m_y_enabled;
    bool m_width_enabled;
    bool m_height_enabled;

    bool m_dragging_enabled;

    bool m_anchor_fill_checked;
    bool m_anchor_horizontalCenter_checked;
    bool m_anchor_verticalCenter_checked;
    bool m_anchor_top_checked;
    bool m_anchor_bottom_checked;
    bool m_anchor_left_checked;
    bool m_anchor_right_checked;

    bool m_anchor_fill_enabled;
    bool m_anchor_positions_enabled;

    bool m_x_combobox_enabled;
    bool m_width_combobox_enabled;
    bool m_height_combobox_enabled;

    int m_x_combobox_index;
    int m_width_combobox_index;
    int m_height_combobox_index;

    int m_anchor_top_margin;
    int m_anchor_bottom_margin;
    int m_anchor_left_margin;
    int m_anchor_right_margin;
    int m_anchor_horizontalCenter_margin;
    int m_anchor_verticalCenter_margin;
};


#endif // OBJECTS_H
