#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->HP_progbar->setStyleSheet("::chunk {background-color: green}");
    ui->MP_progbar->setStyleSheet("::chunk {background-color: blue}");

    ui->statsPer->hide();
    ui->frame_escolha_pers->hide();
    ui->frame_game_over->hide();
    ui->frame_vitoria->hide();
    ui->somDesativado->show();
    ui->somAtivado->hide();

    playlist = new QMediaPlaylist(this);
    playlist->addMedia(QUrl::fromLocalFile("c:/Users/carlo/Downloads/RPG agora e FINAL_COM MUSICA/img/Audio/audioJogo.mp3"));
    playlist->addMedia(QUrl::fromLocalFile("c:/Users/carlo/Downloads/RPG agora e FINAL_COM MUSICA/img/Audio/audioJogo.mp3"));
    playlist->addMedia(QUrl::fromLocalFile("c:/Users/carlo/Downloads/RPG agora e FINAL_COM MUSICA/img/Audio/audioJogo.mp3"));
    playlist->addMedia(QUrl::fromLocalFile("c:/Users/carlo/Downloads/RPG agora e FINAL_COM MUSICA/img/Audio/audioJogo.mp3"));
    playlist->addMedia(QUrl::fromLocalFile("c:/Users/carlo/Downloads/RPG agora e FINAL_COM MUSICA/img/Audio/audioJogo.mp3"));
    playlist->addMedia(QUrl::fromLocalFile("c:/Users/carlo/Downloads/RPG agora e FINAL_COM MUSICA/img/Audio/audioJogo.mp3"));
    playlist->addMedia(QUrl::fromLocalFile("c:/Users/carlo/Downloads/RPG agora e FINAL_COM MUSICA/img/Audio/audioJogo.mp3"));
    playlist->addMedia(QUrl::fromLocalFile("c:/Users/carlo/Downloads/RPG agora e FINAL_COM MUSICA/img/Audio/audioJogo.mp3"));
    playlist->addMedia(QUrl::fromLocalFile("c:/Users/carlo/Downloads/RPG agora e FINAL_COM MUSICA/img/Audio/audioJogo.mp3"));
    playlist->addMedia(QUrl::fromLocalFile("c:/Users/carlo/Downloads/RPG agora e FINAL_COM MUSICA/img/Audio/audioJogo.mp3"));
    playlist->addMedia(QUrl::fromLocalFile("c:/Users/carlo/Downloads/RPG agora e FINAL_COM MUSICA/img/Audio/audioJogo.mp3"));
    playlist->addMedia(QUrl::fromLocalFile("c:/Users/carlo/Downloads/RPG agora e FINAL_COM MUSICA/img/Audio/audioJogo.mp3"));
    playlist->addMedia(QUrl::fromLocalFile("c:/Users/carlo/Downloads/RPG agora e FINAL_COM MUSICA/img/Audio/audioJogo.mp3"));
    playlist->addMedia(QUrl::fromLocalFile("c:/Users/carlo/Downloads/RPG agora e FINAL_COM MUSICA/img/Audio/audioJogo.mp3"));
    playlist->addMedia(QUrl::fromLocalFile("c:/Users/carlo/Downloads/RPG agora e FINAL_COM MUSICA/img/Audio/audioJogo.mp3"));
    playlist->addMedia(QUrl::fromLocalFile("c:/Users/carlo/Downloads/RPG agora e FINAL_COM MUSICA/img/Audio/audioJogo.mp3"));
    playlist->addMedia(QUrl::fromLocalFile("c:/Users/carlo/Downloads/RPG agora e FINAL_COM MUSICA/img/Audio/audioJogo.mp3"));
    playlist->addMedia(QUrl::fromLocalFile("c:/Users/carlo/Downloads/RPG agora e FINAL_COM MUSICA/img/Audio/audioJogo.mp3"));
    playlist->addMedia(QUrl::fromLocalFile("c:/Users/carlo/Downloads/RPG agora e FINAL_COM MUSICA/img/Audio/audioJogo.mp3"));
    playlist->addMedia(QUrl::fromLocalFile("c:/Users/carlo/Downloads/RPG agora e FINAL_COM MUSICA/img/Audio/audioJogo.mp3"));
    playlist->addMedia(QUrl::fromLocalFile("c:/Users/carlo/Downloads/RPG agora e FINAL_COM MUSICA/img/Audio/audioJogo.mp3"));
    playlist->addMedia(QUrl::fromLocalFile("c:/Users/carlo/Downloads/RPG agora e FINAL_COM MUSICA/img/Audio/audioJogo.mp3"));
    playlist->addMedia(QUrl::fromLocalFile("c:/Users/carlo/Downloads/RPG agora e FINAL_COM MUSICA/img/Audio/audioJogo.mp3"));
    playlist->addMedia(QUrl::fromLocalFile("c:/Users/carlo/Downloads/RPG agora e FINAL_COM MUSICA/img/Audio/audioJogo.mp3"));
    playlist->addMedia(QUrl::fromLocalFile("c:/Users/carlo/Downloads/RPG agora e FINAL_COM MUSICA/img/Audio/audioJogo.mp3"));
    playlist->addMedia(QUrl::fromLocalFile("c:/Users/carlo/Downloads/RPG agora e FINAL_COM MUSICA/img/Audio/audioJogo.mp3"));
    playlist->addMedia(QUrl::fromLocalFile("c:/Users/carlo/Downloads/RPG agora e FINAL_COM MUSICA/img/Audio/audioJogo.mp3"));
    playlist->addMedia(QUrl::fromLocalFile("c:/Users/carlo/Downloads/RPG agora e FINAL_COM MUSICA/img/Audio/audioJogo.mp3"));
    playlist->addMedia(QUrl::fromLocalFile("c:/Users/carlo/Downloads/RPG agora e FINAL_COM MUSICA/img/Audio/audioJogo.mp3"));
    playlist->addMedia(QUrl::fromLocalFile("c:/Users/carlo/Downloads/RPG agora e FINAL_COM MUSICA/img/Audio/audioJogo.mp3"));
    playlist->addMedia(QUrl::fromLocalFile("c:/Users/carlo/Downloads/RPG agora e FINAL_COM MUSICA/img/Audio/audioJogo.mp3"));
    playlist->addMedia(QUrl::fromLocalFile("c:/Users/carlo/Downloads/RPG agora e FINAL_COM MUSICA/img/Audio/audioJogo.mp3"));
    playlist->addMedia(QUrl::fromLocalFile("c:/Users/carlo/Downloads/RPG agora e FINAL_COM MUSICA/img/Audio/audioJogo.mp3"));
    playlist->addMedia(QUrl::fromLocalFile("c:/Users/carlo/Downloads/RPG agora e FINAL_COM MUSICA/img/Audio/audioJogo.mp3"));
    playlist->addMedia(QUrl::fromLocalFile("c:/Users/carlo/Downloads/RPG agora e FINAL_COM MUSICA/img/Audio/audioJogo.mp3"));
    playlist->addMedia(QUrl::fromLocalFile("c:/Users/carlo/Downloads/RPG agora e FINAL_COM MUSICA/img/Audio/audioJogo.mp3"));
    playlist->setCurrentIndex(1);

    player = new QMediaPlayer(this);
    player->setPlaylist(playlist);

    rpg = NULL;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::resizeEvent(QResizeEvent *e)
{
    if(rpg)
        rpg->UpdateWindows(ui->centralWidget->width(), ui->centralWidget->height());
}

void MainWindow::paintEvent(QPaintEvent* p)
{
     if(rpg){
        rpg->Desenha(this);
    }
}

void MainWindow::keyPressEvent(QKeyEvent* event)
{
    if(rpg){
        if(rpg->getGanhou())
            ui->frame_vitoria->show();
        else
            rpg->ProcessaKey(event);
    }
    repaint();
}

void MainWindow::on_novoJogo_clicked()
{
    ui->frame_escolha_pers->show();
    ui->frame_novo_jogo->hide();
}

void MainWindow::on_sairJogo_clicked()
{
    close();
}

void MainWindow::on_jogar_clicked()
{
    ui->statsPer->show();

    delete rpg;
    if(ui->lineEdit_NomePers->text() == ""){
        ui->label_nomePer->setText("José");
    }else{
        ui->label_nomePer->setText(ui->lineEdit_NomePers->text());
    }
    ui->lineEdit_NomePers->text().toStdString();
    rpg = new Jogo(ui->comboBox->currentIndex(), ui->lineEdit_NomePers->text().toStdString(), ui->HP_progbar, ui->MP_progbar, this);

    ui->frame_escolha_pers->deleteLater();
    ui->frame_novo_jogo->deleteLater();
    rpg->UpdateWindows(ui->centralWidget->width(), ui->centralWidget->height());
    repaint();

    ui->somAtivado->hide();
    ui->somDesativado->hide();
}

void MainWindow::on_pushButton_clicked()
{
    close();
}

void MainWindow::fimBatalha(bool fim)
{
    ui->statsPer->hide();
    ui->frame_game_over->show();
}

void MainWindow::on_encerraJogo_clicked()
{
    close();
}

void MainWindow::on_encerraJogo_3_clicked()
{
    close();
}

void MainWindow::on_somAtivado_clicked()
{
    ui->somAtivado->hide();
    ui->somDesativado->show();
    player->pause();
}

void MainWindow::on_somDesativado_clicked()
{
    ui->somDesativado->hide();
    ui->somAtivado->show();
    player->play();
}
