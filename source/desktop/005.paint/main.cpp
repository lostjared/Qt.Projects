#include"main_window.hpp"
#include<QApplication>


int main(int argc, char **argv) {
    QApplication app(argc, argv);
    MainWindow main_w;
    main_w.show();
    return app.exec();
}
