#include "personagem.h"

Personagem::Personagem(string nome, int maxHp, int maxMp, int atk, int def, int spd, Sprite* textura) {
	this->nome = nome;
	this->maxHp = maxHp;
	this->hp = maxHp;
	this->maxMp = maxMp;
	this->mp = maxMp;
	this->atk = atk;
	this->def = def;
	this->spd = spd;
	this->atkatual = atk;
	this->defatual = def;
	this->spdatual = spd;
    this->textura= textura;
}

Personagem::Personagem(Sprite* textura){
    this->textura= textura;

}

string Personagem::getNome() {
	return this->nome;
}

int Personagem::getAtk() {
	return this->atk;
}

int Personagem::getDef() {
	return this->def;
}

int Personagem::getHp() {
	return this->hp;
}

int Personagem::getMaxHp() {
	return this->maxHp;
}

int Personagem::getMp() {
	return this->mp;
}

int Personagem::getMaxMp() {
	return this->maxMp;
}

int Personagem::getSpd() {
	return this->spd;
}

int Personagem::getAtkAtual() {
	return this->atkatual;
}

int Personagem::getDefAtual() {
	return this->defatual;
}

int Personagem::getSpdAtual() {
	return this->spdatual;
}

bool Personagem::isVivo() {
	return this->hp > 0;
}

vector<string> Personagem::getListaAbilidades()
{
    return this->lista_abilidades;
}

void Personagem::atacar(Personagem *alvo) {
	int dano = this->getAtkAtual();
	srand (time(NULL));
	int crit = rand() % 100 + 1;
	if (10 <= crit) {
		dano = dano*2;
	}
	int atkspd = this->spdatual;
	alvo->receberDano(dano,atkspd);
}

#include <iostream>
using namespace std;

void Personagem::receberDano(int dano, int atkspd) {
	int danoTotal = dano - this->defatual;
    if (danoTotal < 0) {
        danoTotal = 0;
    }
    /*
    srand (time(NULL));
    int evade = rand() % 100 + 1;
    if (evade<(10*(this->spdatual)/atkspd)) {
        danoTotal = 0;
    }
    */
    this->hp -= danoTotal;
    if(this->hp<0)
        this->hp=0;
}
void Personagem::Desenha(QPainter* p)
{
    textura->Desenha(p);
}
void Personagem::MudaEstadoTextura(string nome)
{
    textura->MudaEstado(nome);
}
void Personagem::AlteraLenTextura(float novoEstado)
{
    textura->AlteraqLen(novoEstado);
}
QPixmap* Personagem::getPixmap()
{
    return textura->getPixmap();
}
