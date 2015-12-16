#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QKeyEvent>
#include <QPainter>
#include "jogo.h"
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QtMultimediaWidgets>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
private:
    Jogo* rpg;
    Ui::MainWindow *ui;
    QMediaPlaylist *playlist;
    QMediaPlayer *player;
protected:
    void exit();
    void resizeEvent(QResizeEvent* e);
    void keyPressEvent(QKeyEvent *event);
    void paintEvent(QPaintEvent* p);
private slots:
    void on_novoJogo_clicked();
    void on_sairJogo_clicked();
    void on_jogar_clicked();
    void on_pushButton_clicked();
    void fimBatalha(bool fim);
    void on_encerraJogo_clicked();
    void on_encerraJogo_3_clicked();
    void on_somAtivado_clicked();
    void on_somDesativado_clicked();
};

#endif // MAINWINDOW_H
