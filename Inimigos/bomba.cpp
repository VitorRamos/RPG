#include "bomba.h"

Bomba::Bomba(int lvl, Sprite *textura):Inimigo(textura){
	this->lvl=lvl;
	this->nome="Bomba";
	this->maxHp=250+30*lvl;
	this->hp=maxHp;
    this->maxMp=1+0*lvl;
	this->mp=maxMp;
	this->atk=20+4*lvl;
	this->atkatual=atk;
	this->def=20+3*lvl;
	this->defatual=def;
	this->spd=4+3*lvl;
	this->spdatual=spd;
	this->expFornecida=10+3*lvl;
	
	
}
	
	
			
		

