#ifndef __HELLO_WORLD_H__
#define __HELLO_WORLD_H__

#include<QMainWindow>
#include<QLabel>

class HelloWorld : public QMainWindow {
    Q_OBJECT
public:
    HelloWorld(QWidget *parent = 0);
    
};


#endif

