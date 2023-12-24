QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

QT += multimedia
QT += multimediawidgets
QT += xml

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    share.cpp \
    video.cpp \
    videobutton.cpp \
    videobuttonslot.cpp \
    videoslot.cpp \
    widget.cpp \
    widgetslots.cpp

HEADERS += \
    share.h \
    video.h \
    videobutton.h \
    widget.h

FORMS += \
    share.ui \
    video.ui \
    widget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    icon/Resource.qrc \
    button.qrc

DISTFILES += \
    data.xml

