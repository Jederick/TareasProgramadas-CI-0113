QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    formtienda.cpp \
    formproducto.cpp \
    main.cpp \
    mainwindow.cpp \

HEADERS += \
    formtienda.h \
    formproducto.h \
    mainwindow.h \

FORMS += \
    formproducto.ui \
    formtienda.ui \
    mainwindow.ui \


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../lib/libreriaTienda/release/ -llibreriaTienda
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../lib/libreriaTienda/debug/ -llibreriaTienda
else:unix: LIBS += -L$$OUT_PWD/../lib/libreriaTienda/ -llibreriaTienda

INCLUDEPATH += $$PWD/../lib/libreriaTienda
DEPENDPATH += $$PWD/../lib/libreriaTienda

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../lib/libreriaTienda/release/liblibreriaTienda.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../lib/libreriaTienda/debug/liblibreriaTienda.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../lib/libreriaTienda/release/libreriaTienda.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../lib/libreriaTienda/debug/libreriaTienda.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../lib/libreriaTienda/liblibreriaTienda.a
