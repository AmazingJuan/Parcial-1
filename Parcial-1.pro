TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        Sources/Candado.cpp \
        Sources/Estructuras.cpp \
        Sources/Menus.cpp \
        Sources/Utilidades.cpp \
        Sources/Validacion.cpp \
        main.cpp

HEADERS += \
    Headers/Candado.h \
    Headers/Estructuras.h \
    Headers/Importaciones.h \
    Headers/Menus.h \
    Headers/Utilidades.h \
    Headers/Validacion.h
