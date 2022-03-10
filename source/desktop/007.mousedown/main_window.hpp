#ifndef __MAIN_WINDOW_H__
#define __MAIN_WINDOW_H__

#include<QMainWindow>
#include<QMouseEvent>

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    MainWindow(QWidget *parent = 0);
    void paintEvent(QPaintEvent *painter);
    void mousePressEvent(QMouseEvent *ke);
};


#endif

