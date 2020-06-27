TEMPLATE = lib
TARGET = qquickmosquittoplugin
QT += qml quick
CONFIG += qt plugin c++11 link_pkgconfig
QML_IMPORT_PATH += ./bin

DESTDIR = ./bin/QtQuick/Mosquitto

macx {
 # Enable pkg-config (pkg-config is disabled by default in the Qt package for mac)
 QT_CONFIG -= no-pkg-config
 # pkg-config location
 PKG_CONFIG = /opt/local/bin/pkg-config
}

PKGCONFIG += libmosquittopp

OBJECTS_DIR = tmp
MOC_DIR = tmp
RCC_DIR = tmp

# Input
SOURCES += \
    src/mosquitto_plugin.cpp \
    src/mosquittoprivate.cpp \
    src/qmlmosquitto.cpp
INCLUDEPATH += include
HEADERS += \
    include/mosquitto_plugin.h \
    include/mosquittoprivate.h \
    include/qmlmosquitto.h
LIBS += -v
DISTFILES += \
    $$DESTDIR/qmldir \
    qml/*.qml

OTHER_FILES += \
    .gitignore \
    README.md


#!equals(_PRO_FILE_PWD_, $$OUT_PWD) {
#    copy_qmldir.target = $$OUT_PWD/qmldir
#    copy_qmldir.depends = $$_PRO_FILE_PWD_/qmldir
#    copy_qmldir.commands = $(COPY_FILE) "$$replace(copy_qmldir.depends, /, $$QMAKE_DIR_SEP)" "$$replace(copy_qmldir.target, /, $$QMAKE_DIR_SEP)"
#    QMAKE_EXTRA_TARGETS += copy_qmldir
#    PRE_TARGETDEPS += $$copy_qmldir.target
#}

#qmldir.files = qmldir
#unix {
#    installPath = $$[QT_INSTALL_QML]/$$replace(uri, \., /)
#    qmldir.path = $$installPath
#    target.path = $$installPath
#    INSTALLS += target qmldir
#}
