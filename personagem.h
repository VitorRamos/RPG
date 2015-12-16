#ifndef PERSONAGEM_H
#define PERSONAGEM_H

#include "sprite.h"

#include <vector>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using std::string;

class Personagem {
	protected:
        vector<string> lista_abilidades;
        Sprite* textura;
		string nome;
		int maxHp, hp, maxMp, mp, atk, def, spd, atkatual, defatual, spdatual;
	public:
        Personagem(string nome, int maxHp, int maxMp, int atk, int def, int spd, Sprite* textura);
        Personagem(Sprite *textura);

		string getNome();
		int getMaxHp();
		int getHp();
		int getMaxMp();
		int getMp();
		int getAtk();
		int getDef();
		int getSpd();
		int getAtkAtual();
		int getDefAtual();
		int getSpdAtual();

        vector<string> getListaAbilidades();
        QPixmap *getPixmap();

		bool isVivo();

		virtual void atacar(Personagem *alvo);
        virtual void receberDano(int dano, int atkspd);

        void Desenha(QPainter* p);
        void MudaEstadoTextura(string nome);
        void AlteraLenTextura(float novoEstado);
};

#endif
