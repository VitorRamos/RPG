#ifndef ARQUEIRO_H
#define ARQUEIRO_H

#include "heroi.h"

class Arqueiro : public Heroi {
	protected:
		bool dex;
	public:
        Arqueiro(string nome, int px, int py, int maxHp, int maxMp, int atk, int def, int spd, Sprite* textura);

        void atacar(Personagem *alvo);
        void flechaDupla(Personagem *alvo);
        void levelUp(int exp);
};

#endif

