#include"main_window.hpp"
#include<QPainter>
#include<QMessageBox>
#include<QTextStream>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    setWindowTitle("TextView");
    setGeometry(0, 0, 800, 600);

    file_menu = menuBar()->addMenu(tr("&File"));    
    file_menu_hello = new QAction(tr("Message Box Text"), this);
    file_menu->addAction(file_menu_hello);
    submenu = file_menu->addMenu(tr("Sub"));
    submenu_action = new QAction(tr("Item 1"), this);
    submenu_action->setCheckable(true);
    submenu_action->setChecked(true);
    submenu->addAction(submenu_action);
    connect(file_menu_hello, SIGNAL(triggered()), this, SLOT(sayHello()));    
    connect(submenu_action, SIGNAL(triggered()), this, SLOT(toggleItem()));
    edit1 = new QTextEdit(tr("Hello, World!"), this);
    edit1->setGeometry(this->rect());
}


void MainWindow::sayHello() {
    QString text = edit1->toPlainText();
    QMessageBox::information(this, tr("Text"), text);
}

void MainWindow::toggleItem() {
    if(submenu_action->isChecked())
        QMessageBox::information(this, tr("Checked"), tr("Checked"));
    else
        QMessageBox::information(this, tr("Not Checked"), tr("Not Checked"));
}
