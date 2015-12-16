#include "sprite.h"

void Sprite::Estado::Proxima()
{
    xPos+=step;
    if(xPos>=xFinalPos)
    {
        xPos=xInitPos;
    }
}

Sprite::Sprite(float qLen, const char* path)
{
    img= new QPixmap(path);
    this->qLen= qLen;
}
void Sprite::MudaEstado(string nome)
{
    ultimoEstado= nome;
    for(int i=0; i<estados.size(); i++)
    {
        if(ultimoEstado == estados[i].nome)
            estados[i].Proxima();
    }
}
void Sprite::Desenha(QPainter* pen)
{
    for(int i=0; i<estados.size(); i++)
    {
        if(ultimoEstado == estados[i].nome)
        {
            pen->drawPixmap(0,0,qLen,qLen,*img,estados[i].xPos,estados[i].yPos,estados[i].step,estados[i].step);
        }
    }
}
void Sprite::AdicionaEstado(std::string nome, float xInitPos, float xFinalPos, float yPos, float step, float xPos)
{
    Estado este;
    este.nome= nome;
    este.step= step;
    este.xFinalPos= xFinalPos;
    este.xInitPos= xInitPos;
    este.xPos= xPos;
    este.yPos= yPos;
    ultimoEstado= nome;
    estados.push_back(este);
}
void Sprite::AlteraqLen(float novoLen)
{
    qLen= novoLen;
}
QPixmap* Sprite::getPixmap()
{
    return this->img;
}
