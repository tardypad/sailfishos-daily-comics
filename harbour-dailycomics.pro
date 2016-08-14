TARGET = harbour-dailycomics

CONFIG += sailfishapp

SOURCES += \
    $$files(src/*.cpp) \
    $$files(src/Comics/*.cpp)

HEADERS += \
    $$files(src/*.h) \
    $$files(src/Comics/*.h)

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

RESOURCES += $${TARGET}.qrc

QT += \
    sql

images.files = \
    images/comics \
    images/icons \
    $$files(images/*.png)

images.path = /usr/share/$${TARGET}/images

SAILFISHAPP_ICONS = 86x86 108x108 128x128 256x256

INSTALLS += images

DEFINES += APP_VERSION=\"\\\"$${VERSION}\\\"\"
