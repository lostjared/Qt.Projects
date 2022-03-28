#include "high_scores.hpp"
#include<QPainter>


HighScores::HighScores(QWidget *parent) : QDialog(parent) {
    setFixedSize(640, 480);
    setWindowTitle("High Scores Window");
}

void HighScores::paintEvent(QPaintEvent *e) {
    Q_UNUSED(e);
    QPainter paint(this);
    paint.fillRect(0, 0, 640, 480, QBrush("#000000"));
}