#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(sayHello()));
    
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::sayHello() {
    QMessageBox::information(this, tr("Hello World"), tr("Hello World"));
    
}
