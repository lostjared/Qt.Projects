#include"hello_window.hpp"
#include<QFormLayout>
#include<QLineEdit>
#include<QPushButton>


HelloWorld::HelloWorld(QWidget *parent) : QDialog(parent) {
    setWindowTitle("Hello World");
    QPushButton *btn1 = new QPushButton("Hello One");
    QLineEdit *le1 = new QLineEdit();
    QPushButton *btn2 = new QPushButton("Hello Two");
    QLineEdit *le2 = new QLineEdit();
    QPushButton *btn3 = new QPushButton("Hello Three");
    QLineEdit *le3 = new QLineEdit();
    
    QFormLayout *layout = new QFormLayout;
    layout->addRow(btn1, le1);
    layout->addRow(btn2, le2);
    layout->addRow(btn3, le3);
    
    setLayout(layout);
}
