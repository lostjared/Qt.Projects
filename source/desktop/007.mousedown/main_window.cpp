#include"main_window.hpp"
#include<QPainter>
#include<QMessageBox>
#include<QTextStream>

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

void MainWindow::mousePressEvent(QMouseEvent *ke) {
    QString value;
    QTextStream stream(&value);
    
    stream << "Mouse pressed. Button: " << ke->button() << " x: " << ke->pos().x() << " y: " << ke->pos().y() << "\n";
    
    QMessageBox::information(this, value, value);
}
