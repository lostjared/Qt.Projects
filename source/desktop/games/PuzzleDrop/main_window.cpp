#include "main_window.hpp"
#include<QPainter>

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
    connect(file_menu_new, SIGNAL(triggered()), this, SLOT(newGame()));
}

QImage GameWindow::loadAndScale(QString filename) {
    QImage img = QImage(filename);
    return img.scaled(1280, 720);
}


void GameWindow::paintEvent(QPaintEvent *e) {
    Q_UNUSED(e);
    QPainter paint(this);

    paint.drawImage(0, 0, background[0]);
    
    for(int x = 0; x < grid.getWidth(); ++x) {
        for(int y = 0; y < grid.getHeight(); ++y) {
            puzzle::Block *b = grid.grid(x,y);
            if(b != 0 && b->getType() == puzzle::BlockType::BLOCK_NULL) {
                paint.fillRect(QRect(x*BLOCK_WIDTH+1, y*BLOCK_HEIGHT+1, BLOCK_WIDTH-1, BLOCK_HEIGHT-1), QBrush("#000000"));
            } else {
                //paint.fillRect(QRect(x*BLOCK_WIDTH, y*BLOCK_HEIGHT, BLOCK_WIDTH, BLOCK_HEIGHT), blockToBrush(b->getType()));
                paint.drawImage(x*BLOCK_WIDTH, y*BLOCK_HEIGHT, blocks[static_cast<int>(b->getType())-2]);
            }
        }
    }
    
    puzzle::Piece &p = grid.getPiece();
    paint.drawImage(p.blocks[0].getX()*BLOCK_WIDTH, p.blocks[0].getY()*BLOCK_HEIGHT, blocks[static_cast<int>(p.blocks[0].getType())-2]);
    paint.drawImage(p.blocks[1].getX()*BLOCK_WIDTH, p.blocks[1].getY()*BLOCK_HEIGHT, blocks[static_cast<int>(p.blocks[1].getType())-2]);
    paint.drawImage(p.blocks[2].getX()*BLOCK_WIDTH, p.blocks[2].getY()*BLOCK_HEIGHT, blocks[static_cast<int>(p.blocks[2].getType())-2]);

}

void GameWindow::keyPressEvent(QKeyEvent *ke) {
    
    if(ke->key() == Qt::Key_Escape)
        exit(0);
    
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
            break;
        case Qt::Key_S:
            grid.keyShiftDown();
            break;
    }
}

void GameWindow::update() {
    grid.update();
    repaint();
}

void GameWindow::newGame() {
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    int interval = 250;
    if(difficulty_level == 1)
        interval = 175;
    else if(difficulty_level == 2)
        interval = 100;
    
    timer->setInterval(interval);
    timer->start();
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

