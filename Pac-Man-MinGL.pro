TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        src/main.cpp \
        src/Game.cpp \
        src/GameObject.cpp \
        src/Map.cpp \
        src/Collision.cpp \
        src/SpriteManager.cpp \
        src/ConfigManager.cpp \
        src/KeyboardController.cpp
        include(libs/MinGL2/mingl.pri)

HEADERS += \
        src/Game.h \
        src/GameObject.h \
        src/Map.h \
        src/Collision.h \
        src/SpriteManager.h \
        src/ConfigManager.h \
        src/KeyboardController.h

DISTFILES += \
    assets/invisibleHitBox.si2 \
    assets/pacman.si2 \
    assets/point.si2 \
    assets/wall.si2 \
    assets/lostMenu.si2 \
    assets/mainMenu.si2 \
    assets/pacmanSkin.si2 \
    assets/phantomCyan.si2 \
    assets/phantomGreen.si2 \
    assets/phantomRed.si2 \
    assets/phantomRose.si2 \
    assets/phantomYello2.si2 \
    assets/selector20x20.si2 \
    assets/wonMenu.si2
