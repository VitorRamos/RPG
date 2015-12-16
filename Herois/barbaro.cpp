#include "barbaro.h"

Barbaro::Barbaro(string nome,int px, int py, int maxHp, int maxMp, int atk, int def, int spd, Sprite* textura) : Heroi(nome,px,py, maxHp, maxMp, atk, def, spd, textura) {
    lista_abilidades.push_back("Bonus Ataque");
}

void Barbaro::atacar(Personagem *alvo) {
	int dano = this->getAtkAtual();
	srand (time(NULL));
	int rng = rand() % 120 + 80;
	dano = dano*(rng/100);
	srand (time(NULL));
	int crit = rand() % 100 + 1;
	if (10 <= crit) {
		dano = dano*2;
	}
	int atkspd = this->spdatual;
	alvo->receberDano(dano,atkspd);
}

void Barbaro::bonusAtaque(Personagem *alvo){
    if(mp == this->maxMp){
        this->atkatual = 3*atkatual;
        mp = 0;
    }
}

void Barbaro::levelUp(int exp) {
    exp += this->exp;
    this->exp = exp;
    while(exp>=this->limiteLevel){
        if(this->level<=10){
            if((this->exp)>=(this->limiteLevel)){
                this->level+=1;
                exp -= this->limiteLevel;
                this->limiteLevel=10*this->level*this->level + 10*this->level; //Aqui vai a função do teto dos level
                this->atk += 3;
                this->def += 2;
                this->spd += 2;
                this->maxHp += 30;
                this->maxMp += 20;
                this->mp = this->maxMp;
                this->hp = this->maxHp;
            }
        }
    }
}
