#include "fenix.h"

Fenix::Fenix(int lvl, Sprite *textura):Inimigo(textura){
	this->lvl=lvl;
	this->nome="Fenix";
	this->maxHp=400+30*lvl;
	this->hp=maxHp;
    this->maxMp=1+0*lvl;
	this->mp=maxMp;
	this->atk=20+4*lvl;
	this->atkatual=atk;
	this->def=20+5*lvl;
	this->defatual=def;
	this->spd=20+5*lvl;
	this->spdatual=spd;
	this->expFornecida=20+5*lvl;
	
	
}
	
	
			
		

