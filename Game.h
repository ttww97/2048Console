//
// Created by 曾莛葳 on 2021/3/25.
//
#include "Board.h"
#ifndef INC_2048CONSOLE_GAME_H
#define INC_2048CONSOLE_GAME_H


class Game {
public:
    void gameStart();
    void gameEnd(char);
private:
    Board board;
};


#endif //INC_2048CONSOLE_GAME_H
