#ifndef GUERREIRO_H
#define GUERREIRO_H

#include "heroi.h"

class Guerreiro : public Heroi {
	public:
        Guerreiro(string nome,int px, int py, int maxHp, int maxMp, int atk, int def, int spd, Sprite* textura);

        void receberDano(int dano, int atkspd);
        void bonusAtkDef();
        void levelUp(int exp);
};

#endif
