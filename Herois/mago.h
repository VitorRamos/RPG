#ifndef MAGO_H
#define MAGO_H

#include "heroi.h"

class Mago : public Heroi {
    public:
        Mago(string nome,int px, int py, int maxHp, int maxMp, int atk, int def, int spd, Sprite* textura);

        void levelUp(int exp);
        void cura();
        void bolaDeFogo(Personagem *alvo);
};
#endif
