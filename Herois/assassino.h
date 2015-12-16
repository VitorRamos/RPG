#ifndef ASSASSINO_H
#define ASSASSINO_H

#include "heroi.h"

class Assassino : public Heroi {
	protected:
        bool critico;
	public:
        Assassino(string nome,int px, int py, int maxHp, int maxMp, int atk, int def, int spd,Sprite* textura);

        void atacar(Personagem *alvo);
		void criticoExtra();
        void levelUp(int exp);
};

#endif
