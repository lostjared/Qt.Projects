#include "main_window.hpp"
#include<QApplication>


int main(int argc, char **argv) {
    
    QApplication app(argc, argv);
    GameWindow game_window;
    game_window.show();
    return app.exec();
}
