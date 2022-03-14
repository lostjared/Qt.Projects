#include "main_window.hpp"
#include<QPainter>
#include<QMessageBox>

using puzzle::BlockType;

GameWindow::GameWindow() : grid(1280/BLOCK_WIDTH, 720/BLOCK_HEIGHT) {
    setWindowTitle("PuzzleDrop");
    setFixedSize(1280, 720);
    
    blocks[0] = QImage(":/img/red1.png");
    blocks[1] = QImage(":/img/red2.png");
    blocks[2] = QImage(":/img/red3.png");
    blocks[3] = QImage(":/img/green1.png");
    blocks[4] = QImage(":/img/green2.png");
    blocks[5] = QImage(":/img/green3.png");
    blocks[6] = QImage(":/img/blue1.png");
    blocks[7] = QImage(":/img/blue2.png");
    blocks[8] = QImage(":/img/blue3.png");

    background[0] = loadAndScale(":/img/level1.png");
    background[1] = loadAndScale(":/img/level2.png");
    background[2] = loadAndScale(":/img/level3.png");
    background[3] = loadAndScale(":/img/level4.png");
    background[4] = loadAndScale(":/img/level5.png");
    background[5] = loadAndScale(":/img/level6.png");
    background[6] = loadAndScale(":/img/level7.png");
    background[7] = loadAndScale(":/img/level8.png");
    
    file_menu = menuBar()->addMenu(tr("&File"));
    options_menu = menuBar()->addMenu(tr("&Options"));
    help_menu = menuBar()->addMenu(tr("&Help"));
    
    file_menu_new = new QAction(tr("&New Game"), this);
    file_menu->addAction(file_menu_new);
    
    diff_menu = options_menu->addMenu(tr("Difficulty"));
    
    diff_easy = new QAction(tr("Easy"), this);
    diff_med = new QAction(tr("Medium"), this);
    diff_hard = new QAction(tr("Hard"), this);
    
    diff_easy->setCheckable(true);
    diff_easy->setChecked(true);
    diff_med->setCheckable(true);
    diff_med->setChecked(false);
    diff_hard->setCheckable(true);
    diff_hard->setChecked(false);
    
    diff_menu->addAction(diff_easy);
    diff_menu->addAction(diff_med);
    diff_menu->addAction(diff_hard);
    

    connect(diff_easy, SIGNAL(triggered()), this, SLOT(setEasy()));
    connect(diff_med, SIGNAL(triggered()), this, SLOT(setMedium()));
    connect(diff_hard, SIGNAL(triggered()), this, SLOT(setHard()));
    difficulty_level = 0;
    game_started = false;
    
    help_about = new QAction(tr("&About"), this);
    connect(help_about, SIGNAL(triggered()), this, SLOT(showAbout()));

    help_menu->addAction(help_about);

    connect(file_menu_new, SIGNAL(triggered()), this, SLOT(newGame()));

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(update()));

    background_proc = new QTimer(this);
    connect(background_proc, SIGNAL(timeout()), this, SLOT(proc()));
}

QImage GameWindow::loadAndScale(QString filename) {
    QImage img = QImage(filename);
    return img.scaled(1280, 720);
}


void GameWindow::paintEvent(QPaintEvent *e) {
    Q_UNUSED(e);
    QPainter paint(this);

    paint.drawImage(0, 0, background[grid.level()-1]);
    
    for(int x = 0; x < grid.getWidth(); ++x) {
        for(int y = 0; y < grid.getHeight(); ++y) {
            puzzle::Block *b = grid.grid(x,y);
            if(b != 0 && b->getType() == puzzle::BlockType::BLOCK_NULL) {
                paint.fillRect(QRect(x*BLOCK_WIDTH+1, y*BLOCK_HEIGHT+1, BLOCK_WIDTH-1, BLOCK_HEIGHT-1), QBrush("#000000"));
            }
             else {
                //paint.fillRect(QRect(x*BLOCK_WIDTH, y*BLOCK_HEIGHT, BLOCK_WIDTH, BLOCK_HEIGHT), blockToBrush(b->getType()));
                int image = static_cast<int>(b->getType())-2;
                if(b->getType() == BlockType::BLOCK_CLEAR)
                    image = (rand()%9);
                paint.drawImage(x*BLOCK_WIDTH, y*BLOCK_HEIGHT, blocks[image]);
            }
        }
    }
    
    puzzle::Piece &p = grid.getPiece();
    paint.drawImage(p.blocks[0].getX()*BLOCK_WIDTH, p.blocks[0].getY()*BLOCK_HEIGHT, blocks[static_cast<int>(p.blocks[0].getType())-2]);
    paint.drawImage(p.blocks[1].getX()*BLOCK_WIDTH, p.blocks[1].getY()*BLOCK_HEIGHT, blocks[static_cast<int>(p.blocks[1].getType())-2]);
    paint.drawImage(p.blocks[2].getX()*BLOCK_WIDTH, p.blocks[2].getY()*BLOCK_HEIGHT, blocks[static_cast<int>(p.blocks[2].getType())-2]);

    if(game_started == false) {
        QFont font = paint.font();
        font.setPixelSize(70);
        font.setBold(true);
        paint.setFont(font);
        QPen pen = paint.pen();
        pen.setColor(QColor(QRgb(0xFFFFFF)));
        paint.setPen(pen);
        paint.drawText(425, 150, "Puzzle Drop");
        paint.drawText(235, 250, "Click New Game in Menu");
    }

}

void GameWindow::keyPressEvent(QKeyEvent *ke) {
    
    if(ke->key() == Qt::Key_Escape)
        exit(0);

    if(game_started == false)
        return;

    
    switch(ke->key()) {
        case Qt::Key_Left:
            grid.keyLeft();
            repaint();
            break;
        case Qt::Key_Right:
            grid.keyRight();
            repaint();
            break;
        case Qt::Key_Down:
            grid.keyDown();
            repaint();
            break;
        case Qt::Key_A:
            grid.keyShiftUp();
            repaint();
            break;
        case Qt::Key_S:
            grid.keyShiftDown();
            repaint();
            break;
        case Qt::Key_Z:
            grid.keyRotateLeft();
            repaint();
            break;
        case Qt::Key_X:
            grid.keyRotateRight();
            repaint();
            break;
    }
}

void GameWindow::gameOver() {
    background_proc->stop();
    timer->stop();
    game_started = false;
}
  

void GameWindow::update() {
    grid.keyDown();
    repaint();
}

void GameWindow::proc() {
    bool test_b1 = grid.procBlocks();
    bool test_b2 = grid.procMoveDown();
    if(test_b1 || test_b2)
        repaint();  
}
  

void GameWindow::newGame() {
     int interval = 1000;
    if(difficulty_level == 1)
        interval = 750;
    else if(difficulty_level == 2)
        interval = 500;
    
    game_started = true;

    timer->setInterval(interval);
    background_proc->setInterval(10);
    timer->start();
    background_proc->start();
}

void GameWindow::setEasy() {
    diff_easy->setChecked(true);
    diff_med->setChecked(false);
    diff_hard->setChecked(false);
    difficulty_level = 0;
}

void GameWindow::setMedium() {
    diff_easy->setChecked(false);
    diff_med->setChecked(true);
    diff_hard->setChecked(false);
    difficulty_level = 1;
}

void GameWindow::setHard() {
    diff_easy->setChecked(false);
    diff_med->setChecked(false);
    diff_hard->setChecked(true);
    difficulty_level = 2;
}

void GameWindow::showAbout() {
    QMessageBox box;
    box.setText("(C) 2022 LostSideDead Software\n Programmed by Jared Bruni\n");
    QPixmap pix = QPixmap(":/img/red3.png");
    box.setIconPixmap(pix.scaled(QSize(64, 64)));
    box.setWindowTitle(tr("About Puzzle Drop"));
    box.exec();

}