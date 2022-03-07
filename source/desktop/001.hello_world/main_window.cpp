#include"main_window.hpp"


HelloWorld::HelloWorld(QWidget *parent) : QMainWindow(parent) {
    setWindowTitle("Hello World");
    setFixedSize(125, 100);
    QLabel *label = new QLabel(tr("Hello World"), this);
    label->setGeometry(25, 25, 75, 25);
}

