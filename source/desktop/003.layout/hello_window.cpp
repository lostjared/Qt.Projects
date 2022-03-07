#include"hello_window.hpp"
#include<QFormLayout>
#include<QLineEdit>
#include<QPushButton>


HelloWorld::HelloWorld() {
    setWindowTitle("Hello World");
    QPushButton *button1 = new QPushButton("HelloOne");
    QLineEdit *lineEdit1 = new QLineEdit();
    QPushButton *button2 = new QPushButton("Hello Two");
    QLineEdit *lineEdit2 = new QLineEdit();
    QPushButton *button3 = new QPushButton("Hello Three");
    QLineEdit *lineEdit3 = new QLineEdit();
    
    QFormLayout *layout = new QFormLayout;
    layout->addRow(button1, lineEdit1);
    layout->addRow(button2, lineEdit2);
    layout->addRow(button3, lineEdit3);
    
    setLayout(layout);
}
