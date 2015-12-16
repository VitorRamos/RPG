#include "heroi.h"

Heroi::Heroi(string nome, int px, int py, int maxHp, int maxMp, int atk, int def, int spd, Sprite* textura) : Personagem(nome, maxHp, maxMp, atk, def, spd, textura) {
    this->exp = 0;
    this->level = 1;
    this->limiteLevel = 20;
    this->px= px;
    this->py= py;
    this->lista_abilidades.push_back("Atacar");
}
int Heroi::getLevel() {
	return this->level;
}
int Heroi::getExp() {
	return this->exp;
}
void Heroi::levelUp(int exp) {
}
void Heroi::atacar(Personagem *alvo) {
	int dano = this->getAtkAtual();
	srand (time(NULL));
    int crit = rand() % 100 + 1;
    if (crit< 10) {
        dano = dano*2;
    }
    int atkspd = this->spdatual;
    alvo->receberDano(dano,atkspd);
}
int Heroi::getPx()
{
    return px;
}
int Heroi::getPy()
{
    return py;
}
void Heroi::setPx(int p)
{
    this->px= p;
}
void Heroi::setPy(int p)
{
    this->py= p;
}

void Heroi::flechaDupla(Personagem *alvo)
{

}
void Heroi::criticoExtra()
{

}
void Heroi::bonusAtaque(Personagem *alvo)
{
}
void Heroi::bonusAtkDef()
{

}
void Heroi::bolaDeFogo(Personagem *alvo)
{

}
void Heroi::cura()
{

}
void Heroi::FimBatalha(int exp)
{
    this->levelUp(exp);
    this->atkatual= this->atk;
    this->defatual= this->def;
    this->spdatual= this->spd;
}
