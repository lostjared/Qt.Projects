#ifndef __HELLO_WORLD_H__
#define __HELLO_WORLD_H__

#include<QDialog>

class HelloWorld : public QDialog {
    Q_OBJECT
public:
    explicit HelloWorld(QWidget *parent = 0);
};


#endif

