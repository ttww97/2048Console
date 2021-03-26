//
// Created by 曾莛葳 on 2021/3/25.
//
#include <random>
#include "Board.h"

Board::Board() {
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            Board::board[i][j] = cards::zero;
        }
    }
}

bool Board::isFull() {
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            if(Board::board[i][j] == cards::zero)
                return false;
        }
    }
    return true;
}

void Board::showBoard() {
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            cout << "|";
            if(Board::board[i][j] == cards::zero){
                cout << " " << "|";
            } else{
                cout << Board::board[i][j] << "|";
            }
        }
        cout << endl;
    }
}

void Board::generateCard() {
    vector<pair<int, int>> remainGrids;
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            if(board[i][j] == cards::zero){
                pair<int, int> temp(i, j);
                remainGrids.push_back(temp);
            }
        }
    }
    int number = remainGrids.size();
    int n = rand() % number;
    int x = remainGrids[n].first;
    int y = remainGrids[n].second;
    board[x][y] = cards::two;
}

void Board::moveCards(char direction) {
    switch (direction) {
        case 'u':
            moveUp();
            break;
        case 'd':
            moveDown();
            break;
        case 'l':
            moveLeft();
            break;
        case 'r':
            moveRight();
            break;
    }
}

Board::cards Board::merge(Board::cards card) {
    switch (card) {
        case cards::two:
            return cards::four;
        case cards::four:
            return cards::eight;
        case cards::eight:
            return cards::sixteen;
        case cards::sixteen:
            return cards::thirtyTwo;
        case cards::thirtyTwo:
            return cards::sixtyFour;
        case cards::sixtyFour:
            return cards::hundredTwentyEight;
        case cards::hundredTwentyEight:
            return cards::twoHFiftySix;
        case cards::twoHFiftySix:
            return cards::fiveHTwelve;
        case cards::fiveHTwelve:
            return cards::oneKTwentyFour;
        case cards::oneKTwentyFour:
            win = true;
            return cards::twoKFortyEight;
    }
}

void Board::moveUp() {
    for(int j = 0; j < 4; j++){
        vector<int> zeros;
        for(int i = 0; i < 4; i++){
            if(board[i][j] == cards::zero)
                zeros.push_back(i);
            else{
                if(zeros.empty())
                    continue;
                else{
                    swap(board[i][j], board[zeros[0]][j]);
                    zeros.erase(zeros.begin());
                    zeros.push_back(i);
                    sort(zeros.begin(), zeros.end());
                }
            }
        }
    }

    for(int j = 0; j < 4; j++){
        for(int i = 0; i < 3; i++){
            if(board[i][j] == cards::zero) continue;
            if(board[i][j] == board[i + 1][j]){
                board[i][j] = merge(board[i][j]);
                board[i + 1][j] = cards::zero;
            }
        }
    }

    for(int j = 0; j < 4; j++){
        vector<int> zeros;
        for(int i = 0; i < 4; i++){
            if(board[i][j] == cards::zero)
                zeros.push_back(i);
            else{
                if(zeros.empty())
                    continue;
                else{
                    swap(board[i][j], board[zeros[0]][j]);
                    zeros.erase(zeros.begin());
                    zeros.push_back(i);
                    sort(zeros.begin(), zeros.end());
                }
            }
        }
    }
}

void Board::moveRight() {
    for(int i = 3; i >= 0; i--){
        vector<int> zeros;
        for(int j = 3; j >= 0; j--){
            if(board[i][j] == cards::zero)
                zeros.push_back(j);
            else{
                if(zeros.empty())
                    continue;
                else{
                    swap(board[i][j], board[i][zeros[0]]);
                    zeros.erase(zeros.begin());
                    zeros.push_back(j);
                    sort(zeros.rbegin(), zeros.rend());
                }
            }
        }
    }

    for(int i = 3; i >= 0; i--){
        for(int j = 3; j > 0; j--){
            if(board[i][j] == cards::zero) continue;
            if(board[i][j] == board[i][j - 1]){
                board[i][j] = merge(board[i][j]);
                board[i][j - 1] = cards::zero;
            }
        }
    }

    for(int i = 3; i >= 0; i--){
        vector<int> zeros;
        for(int j = 3; j >= 0; j--){
            if(board[i][j] == cards::zero)
                zeros.push_back(j);
            else{
                if(zeros.empty())
                    continue;
                else{
                    swap(board[i][j], board[i][zeros[0]]);
                    zeros.erase(zeros.begin());
                    zeros.push_back(j);
                    sort(zeros.rbegin(), zeros.rend());
                }
            }
        }
    }
}

void Board::moveLeft() {
    for(int i = 0; i < 4; i++){
        vector<int> zeros;
        for(int j = 0; j < 4; j++){
            if(board[i][j] == cards::zero)
                zeros.push_back(j);
            else{
                if(zeros.empty())
                    continue;
                else{
                    swap(board[i][j], board[i][zeros[0]]);
                    zeros.erase(zeros.begin());
                    zeros.push_back(j);
                    sort(zeros.begin(), zeros.end());
                }
            }
        }
    }

    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 3; j++){
            if(board[i][j] == cards::zero) continue;
            if(board[i][j] == board[i][j + 1]){
                board[i][j] = merge(board[i][j]);
                board[i][j + 1] = cards::zero;
            }
        }
    }

    for(int i = 0; i < 4; i++){
        vector<int> zeros;
        for(int j = 0; j < 4; j++){
            if(board[i][j] == cards::zero)
                zeros.push_back(j);
            else{
                if(zeros.empty())
                    continue;
                else{
                    swap(board[i][j], board[i][zeros[0]]);
                    zeros.erase(zeros.begin());
                    zeros.push_back(j);
                    sort(zeros.begin(), zeros.end());
                }
            }
        }
    }
}

void Board::moveDown() {
    for(int j = 3; j >= 0; j--){
        vector<int> zeros;
        for(int i = 3; i >= 0; i--){
            if(board[i][j] == cards::zero)
                zeros.push_back(i);
            else{
                if(zeros.empty())
                    continue;
                else{
                    swap(board[i][j], board[zeros[0]][j]);
                    zeros.erase(zeros.begin());
                    zeros.push_back(i);
                    sort(zeros.rbegin(), zeros.rend());
                }
            }
        }
    }

    for(int j = 3; j >= 0; j--){
        for(int i = 3; i > 0; i--){
            if(board[i][j] == cards::zero) continue;
            if(board[i][j] == board[i - 1][j]){
                board[i][j] = merge(board[i][j]);
                board[i - 1][j] = cards::zero;
            }
        }
    }

    for(int j = 3; j >= 0; j--){
        vector<int> zeros;
        for(int i = 3; i >= 0; i--){
            if(board[i][j] == cards::zero)
                zeros.push_back(i);
            else{
                if(zeros.empty())
                    continue;
                else{
                    swap(board[i][j], board[zeros[0]][j]);
                    zeros.erase(zeros.begin());
                    zeros.push_back(i);
                    sort(zeros.rbegin(), zeros.rend());
                }
            }
        }
    }
}

