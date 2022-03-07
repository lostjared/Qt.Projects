#ifndef __HELLO_WORLD_H__
#define __HELLO_WORLD_H__

#include<QMainWindow>
#include<QPushButton>
#include<QMessageBox>

class HelloWorld : public QMainWindow {
    Q_OBJECT
public:
    HelloWorld(QWidget *parent = 0);
    
public slots:
    void sayHello();
    
private:
    QPushButton *say_button;
};


#endif

