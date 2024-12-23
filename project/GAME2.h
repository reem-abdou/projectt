
#ifndef GAME2_H
#define GAME2_H

#include <iostream>
#include "cmake-build-debug/BoardGame_Classes.h"

using namespace std;



template <typename T>
class FourInARow: public Board<T> {
public:
    FourInARow();
    bool update_board(int x, int y, T symbol) override;
    void display_board() override;
    bool is_win() override;
    bool is_draw() override;
    bool game_is_over() override;
};

template <typename T>
class HumanPlayer : public Player<T> {
public:
    HumanPlayer(string n, T symbol);
    void getmove(int& x, int& y) override;
};

template <typename T>
class FourInARow_Random_Player : public RandomPlayer<T>{
public:
    FourInARow_Random_Player(T symbol);
    void getmove(int& x, int& y) override;
};

template <typename T>
FourInARow<T>::FourInARow() {
    this->rows = 6;
    this->columns = 7;
    this->board = new T*[this->rows];
    for (int i = 0; i < this->rows; ++i) {
        this->board[i] = new T[this->columns];
        for (int j = 0; j < this->columns; ++j) {
            this->board[i][j] = '-';
        }
    }
}

template <typename T>
bool FourInARow<T>::update_board(int x, int y, T symbol) {
    for (int i = this->rows - 1; i >= 0; --i) {
        if (this->board[i][y] == '-') {
            this->board[i][y] = symbol;
            return true;
        }
    }
    return false;
}

template <typename T>
void FourInARow<T>::display_board() {
    for (int i = 0; i < this->rows; ++i) {
        for (int j = 0; j < this->columns; ++j) {
            cout << this->board[i][j] << " ";
        }
        cout << endl;
    }
    cout<<endl;
}

template <typename T>
bool FourInARow<T>::is_win() {

    for (int i = 0; i < this->rows; ++i) {
        for (int j = 0; j < this->columns - 3; ++j) {
            if (this->board[i][j] != '-' && this->board[i][j] == this->board[i][j + 1] &&
                this->board[i][j] == this->board[i][j + 2] && this->board[i][j] == this->board[i][j + 3]) {
                return true;
            }
        }
    }

    for (int i = 0; i < this->rows - 3; ++i) {
        for (int j = 0; j < this->columns; ++j) {
            if (this->board[i][j] != '-' && this->board[i][j] == this->board[i + 1][j] &&
                this->board[i][j] == this->board[i + 2][j] && this->board[i][j] == this->board[i + 3][j]) {
                return true;
            }
        }
    }

    for (int i = 0; i < this->rows - 3; ++i) {
        for (int j = 0; j < this->columns - 3; ++j) {
            if (this->board[i][j] != '-' && this->board[i][j] == this->board[i + 1][j + 1] &&
                this->board[i][j] == this->board[i + 2][j + 2] && this->board[i][j] == this->board[i + 3][j + 3]) {
                return true;
            }
        }
    }

    for (int i = 3; i < this->rows; ++i) {
        for (int j = 0; j < this->columns - 3; ++j) {
            if (this->board[i][j] != '-' && this->board[i][j] == this->board[i - 1][j + 1] &&
                this->board[i][j] == this->board[i - 2][j + 2] && this->board[i][j] == this->board[i - 3][j + 3]) {
                return true;
            }
        }
    }

    return false;
}

template <typename T>
bool FourInARow<T>::is_draw() {
    for (int i = 0; i < this->rows; ++i) {
        for (int j = 0; j < this->columns; ++j) {
            if (this->board[i][j] == '-') {
                return false;
            }
        }
    }
    return true;
}

template <typename T>
bool FourInARow<T>::game_is_over() {

    return is_win() || is_draw();
}

template <typename T>
HumanPlayer<T>::HumanPlayer(string n, T symbol) : Player<T>(n, symbol) {}

template <typename T>
void HumanPlayer<T>::getmove(int& x, int& y) {

    cout << "Enter column (0-6): ";
    cin >> y;
    x = -1;
}

template <typename T>
FourInARow_Random_Player<T>::FourInARow_Random_Player(T symbol) : RandomPlayer<T>(symbol) {}

template <typename T>
void FourInARow_Random_Player<T>::getmove(int& x, int& y) {

    y = rand() % 7;
    x = -1;
}






void game2_main() {
    int choice;
    Player<char>* players[2];
    FourInARow<char>* B = new FourInARow<char>();
    string player1Name, player2Name;

    cout << "Welcome to FCAI Four_In_A_Row Game. :)\n";

    cout << "Enter Player 1 name: ";
    cin >> player1Name;
    cout << "Choose Player 1 type:\n";
    cout << "1. Human\n";
    cout << "2. Random Computer\n";
    cin >> choice;

    switch(choice) {
        case 1:
            players[0] = new HumanPlayer<char>(player1Name, 'X');
        break;
        case 2:
            players[0] = new FourInARow_Random_Player<char>('X');
        break;
        default:
            cout << "Invalid choice for Player 1. Exiting the game.\n";
        delete B;
    }

    cout << "Enter Player 2 name: ";
    cin >> player2Name;
    cout << "Choose Player 2 type:\n";
    cout << "1. Human\n";
    cout << "2. Random Computer\n";
    cin >> choice;

    switch(choice) {
        case 1:
            players[1] = new HumanPlayer<char>(player2Name, 'O');
        break;
        case 2:
            players[1] = new FourInARow_Random_Player<char>('O');
        break;
        default:
            cout << "Invalid choice for Player 2. Exiting the game.\n";
        delete players[0];
        delete B;
    }
    GameManager<char> x_o_game(B, players);
    x_o_game.run();

    delete B;
    for (int i = 0; i < 2; ++i) {
        delete players[i];
    }


}
#endif //GAME2_H
