#ifndef _PUZZLE_SCORE_H_
#define _PUZZLE_SCORE_H_

#include<QDialog>


class HighScores : public QDialog {
Q_OBJECT
public:
    explicit HighScores(QWidget *parent = 0);
    void paintEvent(QPaintEvent *e);
};


#endif
