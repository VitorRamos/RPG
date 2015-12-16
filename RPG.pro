#-------------------------------------------------
#
# Project created by QtCreator 2015-11-17T09:28:28
#
#-------------------------------------------------

QT       += core gui multimedia
QT       += multimedia
QT       += multimediawidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = RPG
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    jogo.cpp \
    sprite.cpp \
    Herois/arqueiro.cpp \
    Herois/assassino.cpp \
    Herois/barbaro.cpp \
    Herois/guerreiro.cpp \
    Herois/heroi.cpp \
    Herois/mago.cpp \
    personagem.cpp \
    Inimigos/chefao.cpp \
    Inimigos/inimigo.cpp \
    batalha.cpp \
    Inimigos/basilisco.cpp \
    Inimigos/bomba.cpp \
    Inimigos/cobra.cpp \
    Inimigos/esqueleto.cpp \
    Inimigos/fenix.cpp \
    Inimigos/lobo.cpp \
    Inimigos/smile.cpp

HEADERS  += mainwindow.h \
    jogo.h \
    sprite.h \
    Herois/arqueiro.h \
    Herois/assassino.h \
    Herois/barbaro.h \
    Herois/guerreiro.h \
    Herois/heroi.h \
    Herois/mago.h \
    personagem.h \
    Inimigos/chefao.h \
    Inimigos/inimigo.h \
    batalha.h \
    Inimigos/basilisco.h \
    Inimigos/bomba.h \
    Inimigos/cobra.h \
    Inimigos/esqueleto.h \
    Inimigos/fenix.h \
    Inimigos/lobo.h \
    Inimigos/slime.h

FORMS    += mainwindow.ui \
    batalha.ui

RESOURCES += \
    recursos.qrc

DISTFILES +=
