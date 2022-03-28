#include"lib.h"
#include<iostream>
#include<QMessageBox>

void testFunc() {
    QMessageBox box;
    box.setText(QObject::tr("Hello, World!"));
    box.exec();
}