#ifndef __MAIN_WINDOW_H__
#define __MAIN_WINDOW_H__

#include<QMainWindow>
#include<QMouseEvent>
#include<QThread>

class Background : public QThread {
    Q_OBJECT
public:
    Background();
public slots:
    void process();
};

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);
    void paintEvent(QPaintEvent *painter);
    void mousePressEvent(QMouseEvent *ke);
private:
    Background *background;
    QThread *threadx;
};


#endif

