#ifndef BOMBA_H
#define BOMBA_H

#include "inimigo.h"

class Bomba : public Inimigo {
	
	protected:
		int lvl;
	public:
        Bomba(int lvl, Sprite* textura);

};

#endif
