#ifndef BARBARO_H
#define BARBARO_H

#include "heroi.h"

class Barbaro : public Heroi {
	public:
        Barbaro(string nome,int px, int py, int maxHp, int maxMp, int atk, int def, int spd, Sprite* textura);

        void atacar(Personagem *alvo);
        void bonusAtaque(Personagem *alvo);
        void levelUp(int exp);
};

#endif

