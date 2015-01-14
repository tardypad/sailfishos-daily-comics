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
    rpm/$${TARGET}.yaml \
    rpm/$${TARGET}.spec \
    $${TARGET}.desktop

images.files = \
    images/comics \
    images/icons \
    $$files(images/*.jpg)

images.path = /usr/share/$${TARGET}/images

INSTALLS += images
