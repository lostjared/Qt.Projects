#include "newdialog.h"
#include<QApplication>

int main(int argc, char **argv) {
    QApplication app(argc, argv);
    NewDialog main_window;
    main_window.show();
    return app.exec();
}
