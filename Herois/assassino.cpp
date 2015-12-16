#include "assassino.h"

Assassino::Assassino(string nome, int px, int py, int maxHp, int maxMp, int atk, int def, int spd, Sprite* textura) : Heroi(nome,px,py, maxHp, maxMp, atk, def, spd, textura) {
    lista_abilidades.push_back("Critico Extra");
}

void Assassino::atacar(Personagem *alvo) {
	int dano = this->getAtkAtual();
	srand (time(NULL));
	int crit = rand() % 100 + 1;
	if(this->critico == true){
        if (40 <= crit) {
            dano = dano*2;
        }
	}else{
        if (20 <= crit) {
            dano = dano*2;
        }
	}
	int atkspd = this->spdatual;
	alvo->receberDano(dano,atkspd);
}
void Assassino::criticoExtra(){
    if(mp >= 10){
        if(this->critico == false)
            this->critico = true;
        }
        mp -= 10;
}

void Assassino::levelUp(int exp) {
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
