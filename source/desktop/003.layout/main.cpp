#include"hello_window.hpp"
#include<QApplication>

int main(int argc, char **argv) {
    QApplication app(argc, argv);
    HelloWorld hello_world;
    hello_world.show();
    return app.exec();
}
