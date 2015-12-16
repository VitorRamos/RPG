#include "cobra.h"

Cobra::Cobra(int lvl, Sprite *textura):Inimigo(textura){
	this->lvl=lvl;
	this->nome="Cobra";
	this->maxHp=70+15*lvl;
	this->hp=maxHp;
    this->maxMp=1+0*lvl;
	this->mp=maxMp;
	this->atk=5+2*lvl;
	this->atkatual=atk;
	this->def=10+2*lvl;
	this->defatual=def;
	this->spd=3+3*lvl;
	this->spdatual=spd;
	this->expFornecida=9+2*lvl;
	
	
}
	
	
			
		

