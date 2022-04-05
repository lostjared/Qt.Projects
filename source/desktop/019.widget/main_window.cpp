#include"main_window.hpp"
#include<QPainter>
#include<QMessageBox>
#include<QTextStream>


 InputBox::InputBox(const QString &text, QWidget *parent) : QWidget(parent) {
     label = new QLabel(text, this);
     label->setGeometry(15, 15, 100, 25);
     input_box = new QLineEdit("", this);
     input_box->setGeometry(125, 15, 100, 25);
     button = new QPushButton(tr("Ok"), this);
     button->setGeometry(250,15,50,25);

     connect(button, SIGNAL(clicked()), this, SLOT(onClick()));
 }

 QString InputBox::text() {
     return input_box->text();
 }

 void InputBox::onClick() {
     QMessageBox::information(this,  "Data", text());

 }

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    setWindowTitle("Enter text then click on window");
    setFixedSize(800, 600);
    box = new InputBox("Name", this);
    box->setGeometry(15, 15, 350, 50);
}
void MainWindow::mousePressEvent(QMouseEvent *ke) {
    QString value;
    QTextStream stream(&value);
    stream << "Mouse pressed. Button: " << ke->button() << " x: " << ke->pos().x() << " y: " << ke->pos().y() << "\n";
    stream << "Input box text: " << box->text() << "\n";
    QMessageBox::information(this, value, value);
}
