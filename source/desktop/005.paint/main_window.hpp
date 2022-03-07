#ifndef __MAIN_WINDOW_H__
#define __MAIN_WINDOW_H__

#include<QMainWindow>


class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    MainWindow();
    void paintEvent(QPaintEvent *painter);
};


#endif

