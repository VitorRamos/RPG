#ifndef BASILISCO_H
#define BASILISCO_H

#include "inimigo.h"

class Basilisco : public Inimigo {
	
	protected:
		int lvl;
	public:
        Basilisco(int lvl, Sprite* textura);

};

#endif
