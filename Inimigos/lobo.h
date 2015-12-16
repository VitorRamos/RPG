#ifndef LOBO_H
#define LOBO_H

#include "inimigo.h"

class Lobo : public Inimigo {
	
	protected:
		int lvl;
	public:
        Lobo(int lvl, Sprite* textura);

};

#endif
