#include "guerreiro.h"

Guerreiro::Guerreiro(string nome, int px, int py, int maxHp, int maxMp, int atk, int def, int spd, Sprite* textura) : Heroi(nome,px,py, maxHp, maxMp, atk, def, spd, textura) {
    lista_abilidades.push_back("Bonus Ataque Defesa");
}

void Guerreiro::receberDano(int dano, int atkspd) {
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
    if(this->hp<0)
        this->hp=0;
}

void Guerreiro::bonusAtkDef(){
    if(mp >= 10){
        this->atkatual *= 1.1;
        this->defatual *= 2;
        mp -= 50;
    }
}
void Guerreiro::levelUp(int exp) {
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
