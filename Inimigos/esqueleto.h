#ifndef ESQUELETO_H
#define ESQUELETO_H

#include "inimigo.h"

class Esqueleto : public Inimigo {
	
	protected:
		int lvl;
	public:
        Esqueleto(int lvl, Sprite* textura);

};

#endif
