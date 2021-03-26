//
// Created by 曾莛葳 on 2021/3/25.
//

#ifndef INC_2048CONSOLE_BOARD_H
#define INC_2048CONSOLE_BOARD_H
#include <vector>
#include <iostream>
using namespace std;


class Board {
public:
    Board();
    bool isFull();
    void showBoard();
    enum cards{
        zero = 0,
        two = 2,
        four = 4,
        eight = 8,
        sixteen = 16,
        thirtyTwo = 32,
        sixtyFour = 64,
        hundredTwentyEight = 128,
        twoHFiftySix = 256,
        fiveHTwelve = 512,
        oneKTwentyFour = 1024,
        twoKFortyEight = 2048};
    void generateCard();
    void moveCards(char);
    void moveLeft();
    void moveRight();
    void moveUp();
    void moveDown();
    bool checkWin(){return win;}
    cards merge(cards);
private:
    cards board[4][4];
    bool win = false;
};


#endif //INC_2048CONSOLE_BOARD_H
