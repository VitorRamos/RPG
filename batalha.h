#ifndef BATALHA_H
#define BATALHA_H

#include <QDialog>
#include <QLabel>
#include <QLayout>
#include <QComboBox>
#include <QProgressBar>
#include <vector>

#include "sprite.h"

#include "Herois/heroi.h"
#include "Inimigos/inimigo.h"

#include "Herois/arqueiro.h"
#include "Herois/assassino.h"
#include "Herois/barbaro.h"
#include "Herois/guerreiro.h"
#include "Inimigos/chefao.h"

namespace Ui {
class Batalha;
}

class Batalha : public QDialog
{
    Q_OBJECT
public:
    explicit Batalha(QWidget *parent = 0);
    ~Batalha();
    void Inicia(vector<Heroi*> herois, vector<Inimigo> inimigos);
    bool getFimBatalha();
private slots:
    void on_Atacar_clicked();
    void on_TentarFugir_clicked();
private:
    bool fim;
    bool fimBatalha;
    vector<QProgressBar*> HP_progress_bar_ami;
    vector<QProgressBar*> MP_progress_bar_ami;
    vector<QProgressBar*> HP_progress_bar_ini;
    vector<QProgressBar*> MP_progress_bar_ini;
    vector<QComboBox*> selAtk;
    vector<QComboBox*> selAbd;
    vector<QLabel*> imgs;
    vector<QLabel*> levels;
    vector< vector<QLabel*> > textos_ami;
    vector< vector<QLabel*> > textos_ini;
    vector<Heroi*> herois;
    vector<Inimigo> inimigos;
    int expBat;
    Ui::Batalha *ui;
signals:
    bool batalhaAcabou(bool fim);
};

#endif // BATALHA_H
