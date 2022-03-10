#include"main_window.hpp"
#include<QPainter>
#include<QMessageBox>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    setWindowTitle("Grid");
    setFixedSize(800, 600);
}

void MainWindow::paintEvent(QPaintEvent *e) {
    Q_UNUSED(e);
    QPainter paint(this);
    paint.fillRect(QRect(0, 0, 800, 600), QBrush("#FFFFFF"));
    for(int x = 0; x < 800; x += 16) {
        for(int y = 0; y < 600; y += 16) {
            paint.fillRect(QRect(x+1, y+1, 15, 15), QBrush("#000000"));
        }
    }
}

void MainWindow::keyPressEvent(QKeyEvent *ke) {
    if(ke->key() == Qt::Key_Escape)
        exit(0);
    
    QString value;
    QTextStream stream(&value);
    
    stream << "Key pressed. KeyCode: " << ke->key() << "\n";
    
    QMessageBox::information(this, value, value);
}
