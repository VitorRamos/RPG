#include "lobo.h"

Lobo::Lobo(int lvl, Sprite *textura):Inimigo(textura){
	this->lvl=lvl;
	this->nome="Lobo";
	this->maxHp=100+20*lvl;
	this->hp=maxHp;
    this->maxMp=1+0*lvl;
	this->mp=maxMp;
	this->atk=10+2*lvl;
	this->atkatual=atk;
	this->def=5+2*lvl;
	this->defatual=def;
	this->spd=3+5*lvl;
	this->spdatual=spd;
	this->expFornecida=7+2*lvl;
	
	
}
	
	
			
		

