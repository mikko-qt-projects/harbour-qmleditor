# NOTICE:
#
# Application name defined in TARGET has a corresponding QML filename.
# If name defined in TARGET is changed, the following needs to be done
# to match new name:
#   - corresponding QML filename must be changed
#   - desktop icon filename must be changed
#   - desktop filename must be changed
#   - icon definition filename in desktop file must be changed
#   - translation filenames have to be changed

# The name of your application
TARGET = harbour-qmleditor

QT += widgets xml

CONFIG += sailfishapp

SOURCES += src/harbour-qmleditor.cpp \
    src/mainwindow.cpp \
    src/screenwidget.cpp \
    src/Editor/Tabs/colorpicker/colorpickerwidget.cpp \
    src/Editor/Tabs/colorpicker/qtcolortriangle.cpp \
    src/Editor/Tabs/colorpicker/colorviewer.cpp \
    src/Editor/editorwidget.cpp \
    src/Editor/geometryproperty.cpp \
    src/Editor/typeproperty.cpp \
    src/Navigator/navigatorwidget.cpp \
    src/Navigator/navigatoritems.cpp \
    src/Editor/Tabs/rectangletab.cpp \
    src/Editor/Tabs/emptytab.cpp \
    src/Editor/Tabs/texttab.cpp \
    src/Editor/Tabs/columntab.cpp \
    src/Editor/Tabs/layouttab.cpp \
    src/Editor/Tabs/rowtab.cpp \
    src/Navigator/Tabs/basictab.cpp \
    src/Editor/customtabwidget.cpp \
    src/Navigator/Tabs/custombutton.cpp \
    src/Navigator/Tabs/silicaviewtab.cpp \
    src/Navigator/Tabs/silicacontroltab.cpp \
    src/Navigator/Tabs/silicaitemtab.cpp \
    src/Navigator/Tabs/silicatexttab.cpp \
    src/Navigator/Tabs/silicamenutab.cpp \
    src/Editor/Tabs/columnviewtab.cpp \
    src/Editor/Tabs/customtab.cpp \
    src/Editor/Tabs/listviewtab.cpp \
    src/QmlObjects/qmlobject.cpp \
    src/QmlObjects/page.cpp \
    src/QmlObjects/rectangle.cpp \
    src/QmlObjects/text.cpp \
    src/QmlObjects/column.cpp \
    src/QmlObjects/row.cpp \
    src/QmlObjects/dockedpanel.cpp \
    src/QmlObjects/drawer.cpp \
    src/QmlObjects/horizontalscrolldecorator.cpp \
    src/QmlObjects/scrolldecorator.cpp \
    src/QmlObjects/silicaflickable.cpp \
    src/QmlObjects/silicagridview.cpp \
    src/QmlObjects/silicalistview.cpp \
    src/QmlObjects/silicawebview.cpp \
    src/QmlObjects/slideshowview.cpp \
    src/QmlObjects/verticalscrolldecorator.cpp \
    src/QmlObjects/viewplaceholder.cpp \
    src/QmlObjects/backgrounditem.cpp \
    src/QmlObjects/busyindicator.cpp \
    src/QmlObjects/button.cpp \
    src/QmlObjects/colorpicker.cpp \
    src/QmlObjects/combobox.cpp \
    src/QmlObjects/datepicker.cpp \
    src/QmlObjects/iconbutton.cpp \
    src/QmlObjects/icontextswitch.cpp \
    src/QmlObjects/keypad.cpp \
    src/QmlObjects/listitem.cpp \
    src/QmlObjects/progressbar.cpp \
    src/QmlObjects/remorseitem.cpp \
    src/QmlObjects/remorsepopup.cpp \
    src/QmlObjects/separator.cpp \
    src/QmlObjects/slider.cpp \
    src/QmlObjects/switch.cpp \
    src/QmlObjects/textswitch.cpp \
    src/QmlObjects/timepicker.cpp \
    src/QmlObjects/touchblocker.cpp \
    src/QmlObjects/valuebutton.cpp \
    src/QmlObjects/detailitem.cpp \
    src/QmlObjects/enterkey.cpp \
    src/QmlObjects/label.cpp \
    src/QmlObjects/searchfield.cpp \
    src/QmlObjects/sectionheader.cpp \
    src/QmlObjects/textarea.cpp \
    src/QmlObjects/textfield.cpp \
    src/QmlObjects/contextmenu.cpp \
    src/QmlObjects/menuitem.cpp \
    src/QmlObjects/menulabel.cpp \
    src/QmlObjects/pulldownmenu.cpp \
    src/QmlObjects/pushupmenu.cpp \
    src/QmlObjects/pageheader.cpp \
    src/Editor/Tabs/backgrounditemtab.cpp \
    src/QmlObjects/component.cpp \
    src/QmlObjects/item.cpp \
    src/QmlObjects/image.cpp \
    src/QmlObjects/mousearea.cpp \
    src/Editor/Tabs/mouseareatab.cpp \
    src/Editor/Tabs/verticalscrolldecoratortab.cpp \
    src/Editor/Tabs/horizontalscrolldecoratortab.cpp \
    src/Editor/Tabs/buttontab.cpp \
    src/Editor/Tabs/busyindicatortab.cpp \
    src/Editor/Tabs/comboboxtab.cpp \
    src/Editor/Tabs/detailitemtab.cpp \
    src/Editor/Tabs/dockedpaneltab.cpp \
    src/Editor/Tabs/icontextswitchtab.cpp \
    src/QmlObjects/columnview.cpp \
    src/Editor/deleteproperty.cpp \
    src/QmlCode/qmlcodewidget.cpp \
    src/QmlCode/xmlcreator.cpp

OTHER_FILES += qml/harbour-qmleditor.qml \
    qml/cover/CoverPage.qml \
    qml/pages/FirstPage.qml \
    qml/pages/SecondPage.qml \
    rpm/harbour-qmleditor.changes.in \
    rpm/harbour-qmleditor.spec \
    rpm/harbour-qmleditor.yaml \
    translations/*.ts \
    harbour-qmleditor.desktop

SAILFISHAPP_ICONS = 86x86 108x108 128x128 256x256

# to disable building translations every time, comment out the
# following CONFIG line
CONFIG += sailfishapp_i18n

# German translation is enabled as an example. If you aren't
# planning to localize your app, remember to comment out the
# following TRANSLATIONS line. And also do not forget to
# modify the localized app name in the the .desktop file.
TRANSLATIONS += translations/harbour-qmleditor-de.ts

HEADERS += \
    src/mainwindow.h \
    src/screenwidget.h \
    src/Editor/Tabs/colorpicker/colorpickerwidget.h \
    src/Editor/Tabs/colorpicker/qtcolortriangle.h \
    src/Editor/Tabs/colorpicker/colorviewer.h \
    src/Editor/editorwidget.h \
    src/Editor/geometryproperty.h \
    src/Editor/typeproperty.h \
    src/Navigator/navigatorwidget.h \
    src/Navigator/navigatoritems.h \
    src/Editor/Tabs/tabs.h \
    src/Editor/Tabs/rectangletab.h \
    src/Editor/Tabs/emptytab.h \
    src/Editor/Tabs/texttab.h \
    src/Editor/Tabs/columntab.h \
    src/Editor/Tabs/layouttab.h \
    src/Editor/Tabs/rowtab.h \
    src/Navigator/Tabs/basictab.h \
    src/Editor/customtabwidget.h \
    src/Navigator/Tabs/custombutton.h \
    src/Navigator/Tabs/silicaviewtab.h \
    src/Navigator/Tabs/silicacontroltab.h \
    src/Navigator/Tabs/silicaitemtab.h \
    src/Navigator/Tabs/silicatexttab.h \
    src/Navigator/Tabs/silicamenutab.h \
    src/Editor/Tabs/columnviewtab.h \
    src/Editor/Tabs/customtab.h \
    src/Editor/Tabs/listviewtab.h \
    src/QmlObjects/qmlobject.h \
    src/QmlObjects/page.h \
    src/QmlObjects/rectangle.h \
    src/QmlObjects/text.h \
    src/QmlObjects/column.h \
    src/QmlObjects/row.h \
    src/QmlObjects/qmlobjects.h \
    src/QmlObjects/dockedpanel.h \
    src/QmlObjects/drawer.h \
    src/QmlObjects/horizontalscrolldecorator.h \
    src/QmlObjects/scrolldecorator.h \
    src/QmlObjects/silicaflickable.h \
    src/QmlObjects/silicagridview.h \
    src/QmlObjects/silicalistview.h \
    src/QmlObjects/silicawebview.h \
    src/QmlObjects/slideshowview.h \
    src/QmlObjects/verticalscrolldecorator.h \
    src/QmlObjects/viewplaceholder.h \
    src/QmlObjects/backgrounditem.h \
    src/QmlObjects/busyindicator.h \
    src/QmlObjects/button.h \
    src/QmlObjects/colorpicker.h \
    src/QmlObjects/combobox.h \
    src/QmlObjects/datepicker.h \
    src/QmlObjects/iconbutton.h \
    src/QmlObjects/icontextswitch.h \
    src/QmlObjects/keypad.h \
    src/QmlObjects/listitem.h \
    src/QmlObjects/progressbar.h \
    src/QmlObjects/remorseitem.h \
    src/QmlObjects/remorsepopup.h \
    src/QmlObjects/separator.h \
    src/QmlObjects/slider.h \
    src/QmlObjects/switch.h \
    src/QmlObjects/textswitch.h \
    src/QmlObjects/timepicker.h \
    src/QmlObjects/touchblocker.h \
    src/QmlObjects/valuebutton.h \
    src/QmlObjects/detailitem.h \
    src/QmlObjects/enterkey.h \
    src/QmlObjects/label.h \
    src/QmlObjects/searchfield.h \
    src/QmlObjects/sectionheader.h \
    src/QmlObjects/textarea.h \
    src/QmlObjects/textfield.h \
    src/QmlObjects/contextmenu.h \
    src/QmlObjects/menuitem.h \
    src/QmlObjects/menulabel.h \
    src/QmlObjects/pulldownmenu.h \
    src/QmlObjects/pushupmenu.h \
    src/QmlObjects/pageheader.h \
    src/Editor/Tabs/backgrounditemtab.h \
    src/QmlObjects/component.h \
    src/QmlObjects/item.h \
    src/QmlObjects/image.h \
    src/QmlObjects/mousearea.h \
    src/Editor/Tabs/mouseareatab.h \
    src/Editor/Tabs/verticalscrolldecoratortab.h \
    src/Editor/Tabs/horizontalscrolldecoratortab.h \
    src/Editor/Tabs/buttontab.h \
    src/Editor/Tabs/busyindicatortab.h \
    src/Editor/Tabs/comboboxtab.h \
    src/Editor/Tabs/detailitemtab.h \
    src/Editor/Tabs/dockedpaneltab.h \
    src/Editor/Tabs/icontextswitchtab.h \
    src/QmlObjects/columnview.h \
    src/Editor/deleteproperty.h \
    src/QmlCode/qmlcodewidget.h \
    src/QmlCode/xmlcreator.h

RESOURCES += \
    src/resource.qrc

DISTFILES +=

