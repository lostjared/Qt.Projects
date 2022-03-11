#ifndef __MAIN_WINDOW_H__
#define __MAIN_WINDOW_H__

#include<QMainWindow>
#include<QMouseEvent>
#include<QMenu>
#include<QMenuBar>
#include<QAction>

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);
    void paintEvent(QPaintEvent *painter);
    void mousePressEvent(QMouseEvent *ke);
    
    
public slots:
    void sayHello();
    
private:
    QMenu *file_menu;
    QAction *file_menu_hello;
    
};


#endif

