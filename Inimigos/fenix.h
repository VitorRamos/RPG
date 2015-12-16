#ifndef FENIX_H
#define FENIX_H

#include "inimigo.h"

class Fenix : public Inimigo {
	
	protected:
		int lvl;
	public:
        Fenix(int lvl, Sprite* textura);

};

#endif
