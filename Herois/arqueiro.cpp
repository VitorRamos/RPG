#include "arqueiro.h"

Arqueiro::Arqueiro(string nome, int px, int py, int maxHp, int maxMp, int atk, int def, int spd, Sprite* textura) : Heroi(nome,px,py, maxHp, maxMp, atk, def, spd, textura) {
	this->dex = false;
    lista_abilidades.push_back("Flecha Dupla");
}
void Arqueiro::atacar(Personagem *alvo) {
	int dano = this->getAtkAtual();
	if (this->dex) {
		dano = dano*1.5;
	}
	this->dex = !dex;
	srand (time(NULL));
	int crit = rand() % 100 + 1;
	if (10 <= crit) {
		dano = dano*2;
	}
	int atkspd = this->spdatual;
	alvo->receberDano(dano,atkspd);
}
void Arqueiro::flechaDupla(Personagem *alvo){
    int dano = this->getAtkAtual();
    if(mp >= 10){
        alvo->receberDano(dano*2, spd);
         mp -= 10;
    }
    this->dex = !dex;

}
void Arqueiro::levelUp(int exp) {
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
