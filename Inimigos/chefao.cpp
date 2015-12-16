#include "chefao.h"

Chefao::Chefao(string nome, int maxHp, int maxMp, int atk, int def, int spd, int expFornecida, Sprite* textura) : Inimigo(nome, maxHp, maxMp, atk, def, spd, expFornecida, textura) {
}

void Chefao::atacar(Personagem *alvo) {
	int dano = this->getAtkAtual();
	if (((this->hp)/(this->maxHp)) < 0.3) {
		dano = dano*1.3;
	} else {
		dano = dano*1.2;
	}
	srand (time(NULL));
	int crit = rand() % 100 + 1;
	if (10 <= crit) {
		dano = dano*2;
	}
	int atkspd = this->spdatual;
	alvo->receberDano(dano,atkspd);
}

void Chefao::receberDano(int dano, int atkspd) {
	int danoTotal = dano - this->defatual;
	danoTotal = danoTotal*0.8;
	if (danoTotal < 0) {
		danoTotal = 0;
	}
    /*
	srand (time(NULL));
	int evade = rand() % 100 + 1;
    if ((10*(this->spdatual)/atkspd) < evade) {
		danoTotal = 0;
	}
    */
	this->hp -= danoTotal;
}
