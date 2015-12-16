#ifndef SPRITE_H
#define SPRITE_H

#pragma once

#include <QPixmap>
#include <QPainter>

#include <string>
#include <vector>

using std::string;
using std::vector;

class Sprite
{
    struct Estado
    {
        string nome;
        float xInitPos, xFinalPos, yPos;
        float step, xPos;
        void Proxima();
    };
    string ultimoEstado;
    vector<Estado> estados;
    float qLen;
    QPixmap* img;
public:
    Sprite(float qLen, const char * path);
    void AdicionaEstado(string nome,float xInitPos,float xFinalPos,float yPos, float step, float xPos);
    void AlteraqLen(float novoLen);
    void MudaEstado(string nome);
    void Desenha(QPainter* pen);
    QPixmap *getPixmap();
};
#endif // SPRITE_H
