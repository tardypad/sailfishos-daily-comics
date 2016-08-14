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

INSTALLS += images

DEFINES += APP_VERSION=\"\\\"$${VERSION}\\\"\"

# to disable building translations every time, comment out the
# following CONFIG line
CONFIG += sailfishapp_i18n

# German translation is enabled as an example. If you aren't
# planning to localize your app, remember to comment out the
# following TRANSLATIONS line. And also do not forget to
# modify the localized app name in the the .desktop file.
TRANSLATIONS += translations/$${TARGET}-de.ts
