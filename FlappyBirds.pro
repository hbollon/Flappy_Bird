TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
CONFIG += c++11

SOURCES += main.cpp \
    player.cpp \
    ground.cpp \
    pipeup.cpp \
    pipedown.cpp

win32:CONFIG(release, debug|release): LIBS += -LC:/SFML/lib/ -lsfml-audio-
else:win32:CONFIG(debug, debug|release): LIBS += -LC:/SFML/lib/ -lsfml-audio-d

INCLUDEPATH += C:/SFML/include
DEPENDPATH += C:/SFML/include

win32:CONFIG(release, debug|release): LIBS += -LC:/SFML/lib/ -lsfml-graphics-
else:win32:CONFIG(debug, debug|release): LIBS += -LC:/SFML/lib/ -lsfml-graphics-d

INCLUDEPATH += C:/SFML/include
DEPENDPATH += C:/SFML/include

win32:CONFIG(release, debug|release): LIBS += -LC:/SFML/lib/ -lsfml-system-
else:win32:CONFIG(debug, debug|release): LIBS += -LC:/SFML/lib/ -lsfml-system-d

INCLUDEPATH += C:/SFML/include
DEPENDPATH += C:/SFML/include

win32:CONFIG(release, debug|release): LIBS += -LC:/SFML/lib/ -lsfml-window-
else:win32:CONFIG(debug, debug|release): LIBS += -LC:/SFML/lib/ -lsfml-window-d

INCLUDEPATH += C:/SFML/include
DEPENDPATH += C:/SFML/include

HEADERS += \
    player.h \
    game.h \
    ground.h \
    pipeup.h \
    pipedown.h
