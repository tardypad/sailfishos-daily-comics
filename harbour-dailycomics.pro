TARGET = harbour-dailycomics

CONFIG += sailfishapp

SOURCES += \
    $$files(src/*.cpp)

HEADERS += \
    $$files(src/*.h)

OTHER_FILES = \
    $$files(qml/*.qml) \
    $$files(qml/cover/*.qml) \
    $$files(qml/pages/*.qml) \
    $$files(qml/delegates/*.qml) \
    rpm/$${TARGET}.yaml \
    rpm/$${TARGET}.spec \
    $${TARGET}.desktop

images.files = images/comics
images.path = /usr/share/$${TARGET}/images

INSTALLS += images
