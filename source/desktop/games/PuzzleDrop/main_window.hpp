#ifndef __MAIN_WINDOW_H__
#define __MAIN_WINDOW_H__

#include<QMainWindow>
#include<QKeyEvent>
#include<QTimer>
#include<QImage>
#include<QMenu>
#include<QAction>
#include<QMenuBar>

#include"puzzle_drop.hpp"


enum { BLOCK_WIDTH=64, BLOCK_HEIGHT=32 };

class GameWindow : public QMainWindow {
  Q_OBJECT
public:
    GameWindow();
    void paintEvent(QPaintEvent *e);
    void keyPressEvent(QKeyEvent *ke);
    void gameOver();
    
public slots:
    void update();
    void proc();
    void setEasy();
    void setMedium();
    void setHard();
    void newGame();
    void showAbout();
  
private:
    puzzle::Grid grid;
    QTimer *timer, *background_proc;
    QImage blocks[9];
    QImage background[8];
    QMenu *file_menu, *options_menu, *help_menu, *diff_menu;
    QAction *file_menu_new;
    QAction *diff_easy, *diff_med, *diff_hard;
    QAction *help_about;
    QImage loadAndScale(QString filename);
    int difficulty_level;
    bool game_started;
};





#endif

