//
// Created by 曾莛葳 on 2021/3/25.
//

#include "Game.h"

void Game::gameStart() {
    cout << "Welcome to 2048!" << endl
    << "Type u(up), d(down), l(left), r(right) to move numbers" << endl;
    string direction;
    board.generateCard();
    board.showBoard();
    while(!board.checkWin() && !board.isFull()){
        cout << "Type your direction(only one character): ";
        cin >> direction;
        if(direction.size() > 1){
            cout << "Sorry, illegal input, please try again." << endl;
            continue;
        }
        board.moveCards(direction[0]);
        board.generateCard();
        board.showBoard();
    }
    if(board.checkWin())
        gameEnd('w');
    else
        gameEnd('l');
}

void Game::gameEnd(char state) {
    if(state == 'l')
        cout << "Sorry, you lose the game." << endl;
    else if(state == 'w')
        cout << "You win!" << endl;
    else
        return;
}