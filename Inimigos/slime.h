#ifndef SLIME_H
#define SLIME_H

#include "inimigo.h"

class Slime : public Inimigo {
	
	protected:
		int lvl;
    public:
        Slime(int lvl, Sprite* textura);

};

#endif
