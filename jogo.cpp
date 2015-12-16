#include "jogo.h"

Jogo::Jogo(int classePer, string nome, QProgressBar *bar_hp, QProgressBar *bar_mp, QWidget *p)
{
    srand (time(NULL));
    ganhou= false;
    widPrin= p;
    this->bar_hp= bar_hp;
    this->bar_mp= bar_mp;

    Sprite* animacao;
    string path_;

    switch(classePer)
    {
        case 0: path_= ":/Personagens/img/Personagens/guerreiro_.png"; break;
        case 1: path_= ":/Personagens/img/Personagens/arqueiro_.png"; break;
        case 2: path_= ":/Personagens/img/Personagens/assassino_.png"; break;
        case 3: path_= ":/Personagens/img/Personagens/barbaro_.png"; break;
        case 4: path_= ":/Personagens/img/Personagens/mago_.png"; break;
    }
    animacao= new Sprite(50, path_.c_str());
    animacao->AdicionaEstado("Baixo",    0,400, 0, 100,0);
    animacao->AdicionaEstado("Esquerda", 0,400,100,100,0);
    animacao->AdicionaEstado("Direita",0,400,200,100,0);
    animacao->AdicionaEstado("Cima",   0,400,300,100,0);

    Heroi* principal;

    if(nome.empty()){
        nome = "Jose";
    }

    switch(classePer)
    {
            case 0: principal= new Guerreiro(nome, -45, -35, 500, 500, 100, 10, 2, animacao); break;
            case 1: principal= new Arqueiro(nome, -45, -35, 500, 500, 100, 10, 2, animacao); break;
            case 2: principal= new Assassino(nome, -45, -35, 500, 500, 100, 10, 2, animacao); break;
            case 3: principal= new Barbaro(nome, -45, -35, 500, 500, 100, 10, 2, animacao); break;
            case 4: principal= new Mago(nome, -45, -35, 500, 500, 100, 10, 2, animacao); break;
    }

    equipe.push_back(principal);

    bar_hp->setMaximum(principal->getMaxHp());
    bar_mp->setMaximum(principal->getMaxMp());
    bar_hp->setValue(principal->getHp());
    bar_mp->setValue(principal->getMp());


    texturas.push_back(QPixmap(":/Tiles/img/Tiles/tijolo.png"));
    texturas.push_back(QPixmap(":/Tiles/img/Tiles/Caverna.png"));

    qLen= 640/10;

    map= new char*[100];
    for(int i=0; i<100; i++)
        map[i]= new char[100];
    std::ifstream abre("c:/Users/carlo/Downloads/RPG agora e FINAL_COM MUSICA/mapa.txt" );
    if(abre)
    {
        for(int i=0; i<100; i++)
            for(int j=0; j<100; j++)
                abre >> map[i][j];
    }
    else{} // exception
    abre.close();
    tempo.start();

}

bool Jogo::getGanhou()
{
    return ganhou;
}

#include <iostream>
using namespace std;

void Jogo::UpdateWindows(int w_, int h_)
{
    this->w= w_;
    this->h= h_;
    qLen= h/10;
    equipe[0]->AlteraLenTextura(qLen);
}

void Jogo::ProcessaKey(QKeyEvent* event)
{
    if(equipe.size() >= 4)
    {
        ganhou= true;
    }
    if(tempo.elapsed()>50)
    {
        tempo.start();
        int lx= equipe[0]->getPx(), ly= equipe[0]->getPy();
        if(event->key() == Qt::Key_0)
        {
            ganhou= true;
        }
        if(event->key() == Qt::Key_Up)
        {
            equipe[0]->MudaEstadoTextura("Cima");
            ly++;
        }
        if(event->key() == Qt::Key_Down)
        {
            equipe[0]->MudaEstadoTextura("Baixo");
            ly--;
        }
        if(event->key() == Qt::Key_Left)
        {
            equipe[0]->MudaEstadoTextura("Esquerda");
            lx++;
        }
        if(event->key() == Qt::Key_Right)
        {
            equipe[0]->MudaEstadoTextura("Direita");
            lx--;
        }
        int rx= 5-lx, ry= 5-ly;
        if(map[ry][rx] != '-')
        {
            int hp_medio= 0, mp_medio= 0;
            for(unsigned int i=0; i<equipe.size(); i++)
            {
                hp_medio+=equipe[i]->getHp();
                mp_medio+=equipe[i]->getMp();
            }
            hp_medio/=equipe.size();
            mp_medio/=equipe.size();
            bar_hp->setValue(hp_medio);
            bar_mp->setValue(mp_medio);
            equipe[0]->setPx(lx);
            equipe[0]->setPy(ly);
        }
        if(map[ry][rx] == 'S') // Aleatorio dos inimigos e chance de luta
        {
            int chance = rand() % 100 + 1;
            if(chance > 60)
            {
                map[ry][rx] = '*';
                int quant_inimigos = rand() % (equipe.size()+2) + 1;
                vector<Inimigo> inimigos;
                int level_time= 0;
                for(unsigned int j=0; j<equipe.size(); j++)
                {
                    level_time+=equipe[j]->getLevel();
                }
                for (int i = 0; i < quant_inimigos; i++){
                    int inim = rand() % 7 + 1;
                    int lvl = rand() % (level_time) + (1);
                    Sprite* teste;
                    Inimigo* monstro;
                    switch(inim) {
                        case 1: teste = new Sprite(48, ":/Monstros/img/Monstros/Slime.png"); monstro = new Slime(lvl, teste); break;
                        case 2: teste = new Sprite(48, ":/Monstros/img/Monstros/cobra.png"); monstro = new Cobra(lvl, teste); break;
                        case 3: teste = new Sprite(48, ":/Monstros/img/Monstros/Lobo.png"); monstro = new Lobo(lvl, teste); break;
                        case 4: teste = new Sprite(48, ":/Monstros/img/Monstros/esqueleto_editado.png"); monstro = new Esqueleto(lvl, teste); break;
                        case 5: teste = new Sprite(48, ":/Monstros/img/Monstros/bomba.png"); monstro = new Bomba(lvl, teste); break;
                        case 6: teste = new Sprite(48, ":/Monstros/img/Monstros/fennix.png"); monstro = new Fenix(lvl, teste); break;
                        case 7: teste = new Sprite(48, ":/Monstros/img/Monstros/Monstro1.png"); monstro = new Basilisco(lvl, teste); break;
                    }
                    inimigos.push_back(*monstro);
                }

                battle= new Batalha(widPrin);
                battle->Inicia(equipe, inimigos);
                battle->setWindowFlags(Qt::Dialog | Qt::Desktop);
                battle->show();
                connect(battle, SIGNAL(batalhaAcabou(bool)), widPrin, SLOT(fimBatalha(bool)));
            }
        }
        if(map[ry][rx] == 'G')
        {
            Sprite* animacao;
            animacao= new Sprite(50, ":/Personagens/img/Personagens/guerreiro_.png");
            Heroi* amigo;
            amigo= new Guerreiro("Jose1", -45, -35, 500, 500, 100, 10, 2, animacao);
            equipe.push_back(amigo);
            map[ry][rx]= '*';
        }
        if(map[ry][rx] == 'M')
        {
            Sprite* animacao;
            animacao= new Sprite(50, ":/Personagens/img/Personagens/mago_.png");
            Heroi* amigo;
            amigo= new Mago("Jose2", -45, -35, 500, 500, 100, 10, 2, animacao);
            equipe.push_back(amigo);
            map[ry][rx]= '*';
        }
        if(map[ry][rx] == 'A')
        {
            Sprite* animacao;
            animacao= new Sprite(50, ":/Personagens/img/Personagens/assassino_.png");
            Heroi* amigo;
            amigo= new Assassino("Jose3", -45, -35, 500, 500, 100, 10, 2, animacao);
            equipe.push_back(amigo);
            map[ry][rx]= '*';
        }
        if(map[ry][rx] == 'B')
        {
            Sprite* animacao;
            animacao= new Sprite(50, ":/Personagens/img/Personagens/barbaro_.png");
            Heroi* amigo;
            amigo= new Barbaro("Jose4", -45, -35, 500, 500, 100, 10, 2, animacao);
            equipe.push_back(amigo);
            map[ry][rx]= '*';
        }
    }
}

void Jogo::Desenha(QPaintDevice* janela)
{
    QPainter pen(janela);
    pen.translate(equipe[0]->getPx()*qLen, equipe[0]->getPy()*qLen);
    float x=0, y=0;
    for(int i=0; i<100; i++)
    {
        for(int j=0; j<100; j++)
        {
            float rx= equipe[0]->getPx()*qLen+x, ry= equipe[0]->getPy()*qLen+y;
            if( (rx >=0 && rx <= w) && ( ry>=0 && ry<=h)  )
            {
                if(map[i][j] == '-')
                {
                    pen.drawPixmap(x,y,qLen,qLen,texturas[0]);
                }
                else if(map[i][j] == 'G')
                {
                    pen.drawPixmap(x,y,qLen,qLen,texturas[1]);
                    pen.drawPixmap(x,y,qLen,qLen,QPixmap(":/Personagens/img/Personagens/guerreiro_.png")
                                    ,0,0,100,100);
                }
                else if(map[i][j] == 'B')
                {
                    pen.drawPixmap(x,y,qLen,qLen,texturas[1]);
                    pen.drawPixmap(x,y,qLen,qLen,QPixmap(":/Personagens/img/Personagens/barbaro_.png")
                                    ,0,0,100,100);
                }
                else if(map[i][j] == 'A')
                {
                    pen.drawPixmap(x,y,qLen,qLen,texturas[1]);
                    pen.drawPixmap(x,y,qLen,qLen,QPixmap(":/Personagens/img/Personagens/assassino_.png")
                                    ,0,0,100,100);
                }
                else if(map[i][j] == 'M')
                {
                    pen.drawPixmap(x,y,qLen,qLen,texturas[1]);
                    pen.drawPixmap(x,y,qLen,qLen,QPixmap(":/Personagens/img/Personagens/mago_.png")
                                    ,0,0,100,100);
                }
                else
                    pen.drawPixmap(x,y,qLen,qLen,texturas[1]);
            }
            x+=qLen;
        }
        x=0;
        y+=qLen;
    }
    pen.translate((5-equipe[0]->getPx())*qLen, (5-equipe[0]->getPy())*qLen);
    equipe[0]->Desenha(&pen);
}
