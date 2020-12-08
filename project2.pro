QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    window/Window.cpp \
    elements/button.cpp \
    renderer/canvas.cpp \
    main.cpp \
    renderer/rectangle.cpp \
    renderer/renderer.cpp \
    utility.cpp \
    elements/widget.cpp

HEADERS += \
    window/Window.h \
    elements/button.h \
    renderer/canvas.h \
    dijkstra.h \
    quicksort.h \
    renderer/rectangle.h \
    renderer/renderer.h \
    utility.h \
    elements/widget.h

FORMS +=

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
