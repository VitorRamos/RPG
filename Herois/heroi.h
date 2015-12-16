#ifndef HEROI_H
#define HEROI_H

#include "personagem.h"

class Heroi : public Personagem
{
    protected:
        int level, limiteLevel, exp;
        int px, py;
	public:
        Heroi(string nome, int px, int py, int maxHp, int maxMp, int atk, int def, int spd, Sprite* textura);

        int getPx();
        int getPy();
        int getlPx();
        int getlPy();
        void setPx(int p);
        void setPy(int p);
		int getLevel();
		int getExp();
        void FimBatalha(int exp);
        virtual void levelUp(int exp);

        virtual void atacar(Personagem *alvo);
        virtual void flechaDupla(Personagem *alvo);
        virtual void criticoExtra();
        virtual void bonusAtaque(Personagem *alvo);
        virtual void bonusAtkDef();
        virtual void bolaDeFogo(Personagem *alvo);
        virtual void cura();
};

#endif
