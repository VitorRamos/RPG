#ifndef CHEFAO_H
#define CHEFAO_H

#include "inimigo.h"

class Chefao : public Inimigo {
	public:
        Chefao(string nome, int maxHp, int maxMp, int atk, int def, int spd, int expFornecida, Sprite* textura);

		void atacar(Personagem *alvo);
        void receberDano(int dano, int atkspd);

};

#endif
