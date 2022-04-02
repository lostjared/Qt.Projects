#ifndef __MAIN_WINDOW_H__
#define __MAIN_WINDOW_H__

#include<QMainWindow>
#include<QMouseEvent>
#include<QTimer>
#include<QPushButton>

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);
    void paintEvent(QPaintEvent *painter);
    void mousePressEvent(QMouseEvent *ke);

public slots:
    void tickTimer();
    void exitProg();
private:
    QString name;
    unsigned int count;
    QTimer *timer;
    QPushButton *button1;
};


#endif

