#ifndef COBRA_H
#define COBRA_H

#include "inimigo.h"

class Cobra : public Inimigo {
	
	protected:
		int lvl;
	public:
        Cobra(int lvl, Sprite* textura);

};

#endif
