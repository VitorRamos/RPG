#include "inimigo.h"

Inimigo::Inimigo(string nome, int maxHp, int maxMp, int atk, int def, int spd, int expFornecida, Sprite* textura) : Personagem(nome, maxHp, maxMp, atk, def, spd, textura) {
	this->expFornecida = expFornecida;
}

Inimigo::Inimigo(Sprite* textura) : Personagem(textura){

}

int Inimigo::getExpFornecida() {
	return this->expFornecida;
}

void Inimigo::atacar(Personagem *alvo) {
	int dano = this->getAtkAtual();
	srand (time(NULL));
	int crit = rand() % 100 + 1;
	if (10 <= crit) {
		dano = dano*2;
	}
	int atkspd = this->spdatual;
	alvo->receberDano(dano,atkspd);
}
