#include"main_window.hpp"
#include<QPainter>
#include<QMessageBox>
#include<QTextStream>
MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    setWindowTitle("Click the Window");
    setFixedSize(800, 600);
}

void MainWindow::paintEvent(QPaintEvent *e) {
    Q_UNUSED(e);
    QPainter paint(this);
    paint.fillRect(QRect(0, 0, 800, 600), QBrush("#000000"));
    QFont font = paint.font();
    QPen pen = paint.pen();
    pen.setColor(QColor(QRgb(0xFF0000)));
    font.setPixelSize(40);
    font.setBold(true);
    paint.setFont(font);
    paint.setPen(pen);
    paint.drawText(50, 50, "Hello, World!");
}

void MainWindow::mousePressEvent(QMouseEvent *ke) {
    QString value;
    QTextStream stream(&value);
    stream << "Mouse pressed. Button: " << ke->button() << " x: " << ke->pos().x() << " y: " << ke->pos().y() << "\n";    
    QMessageBox box;
    box.setText(value);
    QPixmap pix = QPixmap(":/img/red1.png");
    box.setIconPixmap(pix.scaled(QSize(64, 64)));
    box.setWindowIcon(pix.scaled(32, 32));
    box.setWindowTitle(tr("About Example"));
    box.exec();
}
