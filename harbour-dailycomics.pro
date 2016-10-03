TARGET = harbour-dailycomics

CONFIG += sailfishapp

SOURCES += \
    $$files(src/*.cpp) \

HEADERS += \
    $$files(src/*.h) \

OTHER_FILES = \
    $$files(qml/*.qml) \
    $$files(qml/cover/*.qml) \
    $$files(qml/pages/*.qml) \
    $$files(qml/delegates/*.qml) \
    $$files(qml/components/*.qml) \
    $$files(qml/utils/*.qml) \
    $$files(qml/scripts/*.js) \
    rpm/$${TARGET}.yaml \
    rpm/$${TARGET}.spec \
    $${TARGET}.desktop

include(plugins.pro)

RESOURCES += $${TARGET}.qrc

QT += \
    sql

images.files = \
    images/icons \
    $$files(images/*.png)

images.path = /usr/share/$${TARGET}/images

plugins.files = \
    plugins/*

plugins.path = /usr/share/$${TARGET}/plugins

INSTALLS += \
    images \
    plugins

DEFINES += \
    APP_VERSION=\"\\\"$${VERSION}\\\"\" \
    PLUGINS_FOLDER_PATH=\"\\\"$${plugins.path}\\\"\"
