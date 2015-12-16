#include "esqueleto.h"

Esqueleto::Esqueleto(int lvl, Sprite* textura):Inimigo(textura){
	this->lvl=lvl;
	this->nome="Esqueleto";
	this->maxHp=200+15*lvl;
	this->hp=maxHp;
    this->maxMp=1+0*lvl;
	this->mp=maxMp;
	this->atk=20+2*lvl;
	this->atkatual=atk;
	this->def=13+3*lvl;
	this->defatual=def;
	this->spd=3+5*lvl;
	this->spdatual=spd;
	this->expFornecida=8+3*lvl;
	
	
}
	
	
			
		

