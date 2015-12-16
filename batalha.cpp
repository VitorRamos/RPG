#include "batalha.h"
#include "ui_batalha.h"


Batalha::Batalha(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Batalha)
{
    ui->setupUi(this);
}

Batalha::~Batalha()
{
    delete ui;
}

void Batalha::Inicia(vector<Heroi*> herois, vector<Inimigo> inimigos)
{
    expBat= 0;
    this->inimigos= inimigos;
    this->herois= herois;
    float x=400, y= 0;

    for(int i=0; i<inimigos.size(); i++)
    {
        expBat+=inimigos[i].getExpFornecida();
        QLabel* nome= new QLabel(this);
        nome->move(x+30, y+100);
        nome->setText(QString(inimigos[i].getNome().c_str()));
        nome->show();

        QLabel* hp_atual= new QLabel(this);
        hp_atual->move(x+250,y+10);
        hp_atual->setFixedWidth(100);
        hp_atual->setText(QString::number(inimigos[i].getHp()));
        hp_atual->show();

        QLabel* mp_atual= new QLabel(this);
        mp_atual->move(x+250, y+35);
        mp_atual->setFixedWidth(100);
        mp_atual->setText(QString::number(inimigos[i].getMp()));
        mp_atual->show();

        QLabel* ataque_atual= new QLabel(this);
        ataque_atual->move(x+150, y+100);
        ataque_atual->setFixedWidth(100);
        QString txt= QString("Ataque: ")+QString::number(inimigos[i].getAtkAtual());
        ataque_atual->setText(txt);
        ataque_atual->show();

        QLabel* defesa_atual= new QLabel(this);
        defesa_atual->setFixedWidth(100);
        defesa_atual->move(x+250, y+100);
        txt= QString("Defesa: ")+QString::number(inimigos[i].getDefAtual());
        defesa_atual->setText(txt);
        defesa_atual->show();

        vector<QLabel*> textos_;
        textos_.push_back(nome);
        textos_.push_back(hp_atual);
        textos_.push_back(mp_atual);
        textos_.push_back(ataque_atual);
        textos_.push_back(defesa_atual);
        textos_ini.push_back(textos_);

        QProgressBar* hp= new QProgressBar(this), *mp= new QProgressBar(this);
        hp->setMaximum(inimigos[i].getMaxHp());
        mp->setMaximum(inimigos[i].getMaxMp());
        hp->setValue(inimigos[i].getHp());
        mp->setValue(inimigos[i].getMp());
        hp->move(x+100,y+10);
        mp->move(x+100,y+35);
        hp->setStyleSheet("::chunk {background-color: green}");
        mp->setStyleSheet("::chunk {background-color: blue}");

        HP_progress_bar_ini.push_back(hp);
        MP_progress_bar_ini.push_back(mp);

        QLabel* img= new QLabel(this);
        QPixmap mapix= *(inimigos[i].getPixmap());
        mapix= mapix.copy(0,0,100,100);
        img->setPixmap(mapix);
        img->move(x,y);
        imgs.push_back(img);
        y+=120;
    }
    x=0;y=0;
    for(int i=0; i<herois.size(); i++)
    {
        QLabel* nivel= new QLabel(this);
        nivel->move(x+250, y+22);
        nivel->setText(QString("Nivel")+QString::number(herois[i]->getLevel()));
        nivel->show();
        levels.push_back(nivel);

        QLabel* nome= new QLabel(this);
        nome->move(x, y+110);
        nome->setText(QString(herois[i]->getNome().c_str()));
        nome->show();

        QLabel* hp_atual= new QLabel(this);
        hp_atual->move(x+250,y+10);
        hp_atual->setFixedWidth(100);
        hp_atual->setText(QString::number(herois[i]->getHp()));
        hp_atual->show();

        QLabel* mp_atual= new QLabel(this);
        mp_atual->move(x+250, y+35);
        mp_atual->setFixedWidth(100);
        mp_atual->setText(QString::number(herois[i]->getMp()));
        mp_atual->show();

        QLabel* ataque_atual= new QLabel(this);
        ataque_atual->move(x+50, y+110);
        ataque_atual->setFixedWidth(100);
        QString txt= QString("Ataque: ")+QString::number(herois[i]->getAtkAtual());
        ataque_atual->setText(txt);
        ataque_atual->show();

        QLabel* defesa_atual= new QLabel(this);
        defesa_atual->setFixedWidth(100);
        defesa_atual->move(x+150, y+110);
        txt= QString("Defesa: ")+QString::number(herois[i]->getDefAtual());
        defesa_atual->setText(txt);
        defesa_atual->show();

        vector<QLabel*> textos_;
        textos_.push_back(nome);
        textos_.push_back(hp_atual);
        textos_.push_back(mp_atual);
        textos_.push_back(ataque_atual);
        textos_.push_back(defesa_atual);
        textos_ami.push_back(textos_);

        QComboBox* hability= new QComboBox(this);
        hability->move(x+100,y+65);
        for(unsigned int j=0; j<herois[i]->getListaAbilidades().size(); j++)
        {
            hability->addItem(QString(herois[i]->getListaAbilidades()[j].c_str()));
        }
        selAbd.push_back(hability);

        QComboBox* target= new QComboBox(this);
        target->move(x+250,y+65);
        for(unsigned int j=0; j<inimigos.size(); j++)
        {
            target->addItem(QString(inimigos[j].getNome().c_str()));
        }
        selAtk.push_back(target);

        QProgressBar* hp= new QProgressBar(this), *mp= new QProgressBar(this);
        hp->setMaximum(herois[i]->getMaxHp());
        mp->setMaximum(herois[i]->getMaxMp());
        hp->setValue(herois[i]->getHp());
        mp->setValue(herois[i]->getMp());
        hp->move(x+100,y+10);
        mp->move(x+100,y+35);
        hp->setStyleSheet("::chunk {background-color: green}");
        mp->setStyleSheet("::chunk {background-color: blue}");

        HP_progress_bar_ami.push_back(hp);
        MP_progress_bar_ami.push_back(mp);

        QLabel* img= new QLabel(this);
        QPixmap mapix= *(herois[i]->getPixmap());
        mapix= mapix.copy(0,0,100,100);
        img->setPixmap(mapix);
        img->move(x,y);
        imgs.push_back(img);
        y+=140;
    }
}

void Batalha::on_Atacar_clicked()
{
    bool heroi_vivo= false;
    for(unsigned int i=0; i<herois.size() && !inimigos.empty(); i++)
    {
        if(herois[i]->isVivo())
        {
            heroi_vivo= true;
            // Se não tiver mana Messagem
            if(selAbd[i]->currentText() == "Atacar")
            {
                herois[i]->atacar(&inimigos[selAtk[i]->currentIndex()]);
            }
            if(selAbd[i]->currentText() == "Flecha Dupla")
            {
                herois[i]->flechaDupla(&inimigos[selAtk[i]->currentIndex()]);
            }
            if(selAbd[i]->currentText() == "Critico Extra")
            {
                herois[i]->criticoExtra();
            }
            if(selAbd[i]->currentText() == "Bonus Ataque")
            {
                herois[i]->bonusAtaque(&inimigos[selAtk[i]->currentIndex()]);
            }
            if(selAbd[i]->currentText() == "Bonus Ataque Defesa")
            {
                herois[i]->bonusAtkDef();
            }
            if(selAbd[i]->currentText() == "Bola de Fogo")
            {
                herois[i]->bolaDeFogo(&inimigos[selAtk[i]->currentIndex()]);
            }
            if(selAbd[i]->currentText() == "Cura")
            {
                herois[i]->cura();
            }
        }
    }
    for(unsigned int i=0; i<inimigos.size(); i++)
    {
        textos_ini[i][1]->setText(QString::number(inimigos[i].getHp()));
        textos_ini[i][2]->setText(QString::number(inimigos[i].getMp()));
        textos_ini[i][3]->setText(QString("Ataque: ")+QString::number(inimigos[i].getAtkAtual()));
        textos_ini[i][4]->setText(QString("Defesa: ")+QString::number(inimigos[i].getDefAtual()));

        HP_progress_bar_ini[i]->setValue(inimigos[i].getHp());
        MP_progress_bar_ini[i]->setValue(inimigos[i].getMp());
    }
    for(unsigned int i=0; i<inimigos.size() && heroi_vivo; i++)
    {
        if(inimigos[i].isVivo())
        {
           unsigned int x= 0;
            while(!herois[x]->isVivo())
            {
                x++;
                if(x>=herois.size()){
                    heroi_vivo= false;
                    goto out;
                }
            }
            inimigos[i].atacar(herois[x]);
        }
        else
        {
            for(unsigned int j=0; j<selAtk.size(); j++)
                selAtk[j]->removeItem(i);
            inimigos.erase(inimigos.begin()+i);
            textos_ini.erase(textos_ini.begin()+i);
            HP_progress_bar_ini.erase(HP_progress_bar_ini.begin()+i);
            MP_progress_bar_ini.erase(MP_progress_bar_ini.begin()+i);
        }
    }
    out:
    for(unsigned int i=0; i<herois.size(); i++)
    {
        textos_ami[i][1]->setText(QString::number(herois[i]->getHp()));
        textos_ami[i][2]->setText(QString::number(herois[i]->getMp()));
        textos_ami[i][3]->setText(QString("Ataque: ")+QString::number(herois[i]->getAtkAtual()));
        textos_ami[i][4]->setText(QString("Defesa: ")+QString::number(herois[i]->getDefAtual()));

        HP_progress_bar_ami[i]->setValue(herois[i]->getHp());
        MP_progress_bar_ami[i]->setValue(herois[i]->getMp());
        levels[i]->setText(QString("Nivel")+QString::number(herois[i]->getLevel()));
    }
    fim= !heroi_vivo || inimigos.empty();
    fimBatalha = false;
    if(!heroi_vivo)
    {
        emit batalhaAcabou(true);
    }
    if(fim) // LevelUp e log batalha
    {
        int expTotal = 0;
        for(unsigned int i=0; i<inimigos.size(); i++){
            expTotal += inimigos[i].getExpFornecida();
        }
        for(unsigned int i=0; i<herois.size(); i++){
            //herois[i]->levelUp(expTotal);
            herois[i]->FimBatalha(expBat);
        }
        fimBatalha = true;
        close();
    } 
}


void Batalha::on_TentarFugir_clicked()
{
    srand (time(NULL));
    int fugir = rand() %100 + 1;
    fugir *= (float)herois[0]->getSpdAtual()/inimigos[0].getSpdAtual();
    if(fugir > 50){
        for(unsigned int i=0; i<herois.size(); i++){
            //herois[i]->levelUp(expTotal);
            herois[i]->FimBatalha(expBat);
        }
        close();
    }

}

bool Batalha::getFimBatalha(){
    return fimBatalha;
}
