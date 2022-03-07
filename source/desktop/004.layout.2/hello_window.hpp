#ifndef __HELLO_WORLD_H__
#define __HELLO_WORLD_H__

#include<QDialog>
#include<QPushButton>

class HelloWorld : public QDialog {
    Q_OBJECT
public:
    HelloWorld();
public slots:
    void sayHello();
    void exit_app();
private:
    QPushButton *btn1, *btn2;
};


#endif

