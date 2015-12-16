#include "mago.h"

Mago::Mago(string nome, int px, int py, int maxHp, int maxMp, int atk, int def, int spd, Sprite* textura) : Heroi(nome,px,py, maxHp, maxMp, atk, def, spd, textura) {
    lista_abilidades.push_back("Bola de Fogo");
    lista_abilidades.push_back("Cura");
}

void Mago::cura(){
    if(mp >= 10){
        hp += 0.3*maxHp;
        if(hp > maxHp){
            hp = maxHp;
        }
        mp-=10;
    }
}
void Mago::bolaDeFogo(Personagem *alvo){
    int dano = getAtkAtual();
    if(mp >= 10){
        alvo->receberDano(dano*3*mp/maxMp, 1);
        mp -= 10;
    }
}
void Mago::levelUp(int exp) {
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
