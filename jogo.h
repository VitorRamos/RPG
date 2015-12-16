#ifndef JOGO_H
#define JOGO_H

#include <QPainter>
#include <QKeyEvent>
#include <QProgressBar>
#include <QMainWindow>
#include <QWidget>
#include <QTime>
#include <vector>
#include <fstream>

using namespace std;

#include "batalha.h"
#include "sprite.h"

#include "Herois/heroi.h"
#include "Inimigos/inimigo.h"

#include "Herois/mago.h"
#include "Herois/arqueiro.h"
#include "Herois/assassino.h"
#include "Herois/barbaro.h"
#include "Herois/guerreiro.h"
#include "Inimigos/chefao.h"

#include "Inimigos/basilisco.h"
#include "Inimigos/bomba.h"
#include "Inimigos/cobra.h"
#include "Inimigos/esqueleto.h"
#include "Inimigos/fenix.h"
#include "Inimigos/lobo.h"
#include "Inimigos/slime.h"


class Jogo : public QMainWindow
{
    vector<Heroi*> equipe;
    char** map;
    float qLen;
    int w, h;
    QTime tempo;
    vector<QPixmap> texturas;
    QProgressBar* bar_hp, *bar_mp;
    QWidget* widPrin;
    Batalha* battle;
    bool gameOver;
    bool ganhou;
public:
    Jogo(int classePer,string nome, QProgressBar* bar_hp, QProgressBar *bar_mp, QWidget* p);
    void UpdateWindows(int w_, int h_);
    void ProcessaKey(QKeyEvent* event);
    void Desenha(QPaintDevice* janela);
    bool getGanhou();
};

#endif // JOGO_H
