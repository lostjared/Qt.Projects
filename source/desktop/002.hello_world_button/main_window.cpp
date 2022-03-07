#include"main_window.hpp"


HelloWorld::HelloWorld(QWidget *parent) : QMainWindow(parent) {
    setWindowTitle("Hello World");
    setFixedSize(125, 35);
    say_button = new QPushButton(tr("Say"), this);
    say_button->setGeometry(5, 5, 120, 25);
    connect(say_button, SIGNAL(clicked()), this, SLOT(sayHello()));
}

void HelloWorld::sayHello() {
    QMessageBox::information(this, tr("Hello, World!"), tr("Hello, World!"));
}
