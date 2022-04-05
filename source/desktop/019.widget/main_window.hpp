#ifndef __MAIN_WINDOW_H__
#define __MAIN_WINDOW_H__

#include<QMainWindow>
#include<QKeyEvent>
#include<QLabel>
#include<QLineEdit>
#include<QWidget>

class InputBox : public QWidget {
    Q_OBJECT
public:
    explicit InputBox(const QString &text, QWidget *parent = 0);
    QString text();
private:
    QLabel *label;
    QLineEdit *input_box;
};

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);
    void mousePressEvent(QMouseEvent *ke);
private:
    InputBox *box;
};


#endif

