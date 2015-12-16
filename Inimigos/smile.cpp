#include "slime.h"

Slime::Slime(int lvl, Sprite* textura):Inimigo(textura){
	this->lvl=lvl;
	this->nome="Slime";
	this->maxHp=50+10*lvl;
	this->hp=maxHp;
    this->maxMp=1+0*lvl;
	this->mp=maxMp;
	this->atk=5+1*lvl;
	this->atkatual=atk;
	this->def=3+1*lvl;
	this->defatual=def;
	this->spd=1+1*lvl;
	this->spdatual=spd;
	this->expFornecida=5+1*lvl;
	
	
}
	
	
			
		

