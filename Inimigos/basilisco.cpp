#include "basilisco.h"

Basilisco::Basilisco(int lvl, Sprite *textura):Inimigo(textura){
	this->lvl=lvl;
	this->nome="Basilisco";
	this->maxHp=300+20*lvl;
	this->hp=maxHp;
    this->maxMp=1+0*lvl;
	this->mp=maxMp;
	this->atk=20+5*lvl;
	this->atkatual=atk;
	this->def=15+4*lvl;
	this->defatual=def;
	this->spd=10+4*lvl;
	this->spdatual=spd;
	this->expFornecida=10+5*lvl;

	
	
}
	
	
			
		

