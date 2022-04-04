#ifndef __MAIN_WINDOW_H__
#define __MAIN_WINDOW_H__

#include<QMainWindow>
#include<QMouseEvent>
#include<QMenu>
#include<QMenuBar>
#include<QAction>
#include<QTextEdit>

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);
       
public slots:
    void sayHello();
    void toggleItem();
    
private:
    QMenu *file_menu, *submenu;
    QAction *file_menu_hello;
    QAction *submenu_action;
    QTextEdit *edit1;
    
};


#endif

