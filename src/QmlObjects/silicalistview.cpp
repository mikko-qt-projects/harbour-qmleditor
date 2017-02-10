#include "silicalistview.h"

SilicaListView::SilicaListView(QWidget *parent) : QmlObject(parent)
{
    objectType = "SilicaListView";

    m_spacing = 0;
    m_delegate = NULL;
    m_model = NULL;
    m_highlight = NULL;
    m_header = NULL;
    m_footer = NULL;
}
