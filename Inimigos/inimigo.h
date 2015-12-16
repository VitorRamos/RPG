#ifndef INIMIGO_H
#define INIMIGO_H

#include "personagem.h"

class Inimigo : public Personagem {
	protected:
		int expFornecida;
	public:
        Inimigo(string nome, int maxHp, int maxMp, int atk, int def, int spd, int expFornecida, Sprite* textura);
        Inimigo(Sprite* textura);
		int getExpFornecida();

        virtual void atacar(Personagem *alvo);
};

#endif
