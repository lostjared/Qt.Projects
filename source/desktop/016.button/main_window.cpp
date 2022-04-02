#include"main_window.hpp"
#include<QPainter>
#include<QMessageBox>
#include<QTextStream>
#include<QInputDialog>
#include<QCoreApplication>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    setWindowTitle("Click the Window");
    setFixedSize(800, 600);
    name = "World";
    count = 0;
    button1 = new QPushButton(tr("Quit"), this);
    button1->setGeometry(100, 100, 200, 50);
    connect(button1, SIGNAL(clicked()), this, SLOT(exitProg()));
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(tickTimer()));
    timer->setInterval(1000);
    timer->start();
}

void MainWindow::tickTimer() {
    ++count;
    if(count > 60)
        count = 0;
    repaint();
}

void MainWindow::exitProg() {
    QMessageBox box;
    box.setText("Goodbye!");
    QPixmap pix = QPixmap(":/img/red1.png");
    box.setIconPixmap(pix.scaled(QSize(64, 64)));
    box.setWindowIcon(pix.scaled(32, 32));
    box.setWindowTitle(tr("Goodbye"));
    box.exec();
    QCoreApplication::quit();
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

    QString counter;
    QTextStream stream(&counter);
    stream << count << " seconds...";
    paint.drawText(50, 50, "Hello, " + name + "! " + counter);
}

void MainWindow::mousePressEvent(QMouseEvent *ke) {

    bool ok;
    QString text = QInputDialog::getText(this, tr("Input Your Name"),tr("Your name:"), QLineEdit::Normal,"", &ok);
    if(ok == false) return;
    name = text;
    QString value;
    QTextStream stream(&value);
    stream << "Your name: " << text << "\nMouse pressed. Button: " << ke->button() << " x: " << ke->pos().x() << " y: " << ke->pos().y() << "\n";    
    QMessageBox box;
    box.setText(value);
    QPixmap pix = QPixmap(":/img/red1.png");
    box.setIconPixmap(pix.scaled(QSize(64, 64)));
    box.setWindowIcon(pix.scaled(32, 32));
    box.setWindowTitle(tr("About Example"));
    box.exec();
}
