#include"hello_window.hpp"
#include<QHBoxLayout>
#include<QLineEdit>
#include<QPushButton>
#include<QMessageBox>

HelloWorld::HelloWorld() {
    setWindowTitle("Hello World");
   
    QHBoxLayout *layout = new QHBoxLayout;
    btn1 = new QPushButton(tr("Hello"));
    btn2 = new QPushButton(tr("Exit"));
    layout->addWidget(btn1);
    layout->addWidget(btn2);
    
    connect(btn1, SIGNAL(clicked()), this, SLOT(sayHello()));
    connect(btn2, SIGNAL(clicked()), this, SLOT(exit_app()));
    
    setLayout(layout);
}

void HelloWorld::sayHello() {
    QMessageBox::information(this, tr("Hello, World!"), tr("Hello, World!"));
}

void HelloWorld::exit_app() {
    exit(0);
}
