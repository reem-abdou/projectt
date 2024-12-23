#ifndef _NUMERICal_TIC_TAC_TOE_H
#define _NUMERICal_TIC_TAC_TOE_H
#include <set>
#include "cmake-build-debug/BoardGame_Classes.h"

template <typename T>
class Numeric_Board : public Board<T> {
public:
    Numeric_Board();
    bool update_board(int x, int y, T number);
    void display_board();
    bool is_win();
    bool is_draw();
    bool game_is_over();
};

template <typename T>
class Numeric_Player : public Player<T> {
public:
    Numeric_Player(string name, T symbol, bool is_odd);
    void getmove(int& x, int& y);

private:
    set<T> available_numbers;
    static set<T> used_numbers;
    bool is_odd;
};


template <typename T>
class Numeric_Random_Player : public RandomPlayer<T> {
public:
    Numeric_Random_Player(string name, T symbol, bool is_odd);
    void getmove(int& x, int& y);

private:
    set<T> available_numbers;
    static set<T> used_numbers;
    bool is_odd;
};

template <typename T>
set<T> Numeric_Random_Player<T>::used_numbers;


#include <iostream>
#include <iomanip>
#include <cctype>

using namespace std;

template <typename T>
Numeric_Board<T>::Numeric_Board() {
    this->rows = this->columns = 3;
    this->board = new T*[this->rows];
    for (int i = 0; i < this->rows; i++) {
        this->board[i] = new T[this->columns];
        for (int j = 0; j < this->columns; j++) {
            this->board[i][j] = 0;
        }
    }
    this->n_moves = 0;
}

template <typename T>
bool Numeric_Board<T>::update_board(int x, int y, T number) {

    if (!(x < 0 || x >= this->rows || y < 0 || y >= this->columns) && (this->board[x][y] == 0 || number == 0)) {
        if (number == 0) {
            this->n_moves--;
            this->board[x][y] = 0;
        }
        else {
            this->n_moves++;
            this->board[x][y] = number;
        }

        return true;
    }
    return false;
}

template <typename T>
void Numeric_Board<T>::display_board() {
    for (int i = 0; i < this->rows; i++) {
        cout << "\n| ";
        for (int j = 0; j < this->columns; j++) {
            cout << "(" << i << "," << j << ")";
            cout << setw(2) << this->board[i][j] << " |";
        }
        cout << "\n-----------------------------";
    }
    cout << endl;
}


template <typename T>
bool Numeric_Board<T>::is_win() {

    auto belongs_to_one_player = [](T a, T b, T c) {
        return ((a % 2 == b % 2) && (b % 2 == c % 2) && a != 0 && b != 0 && c != 0);
    };

    for (int i = 0; i < this->rows; i++) {
        if (belongs_to_one_player(this->board[i][0], this->board[i][1], this->board[i][2]) &&
            (this->board[i][0] + this->board[i][1] + this->board[i][2] >= 15)) {
            return true;
        }
    }


    for (int i = 0; i < this->columns; i++) {
        if (belongs_to_one_player(this->board[0][i], this->board[1][i], this->board[2][i]) &&
            (this->board[0][i] + this->board[1][i] + this->board[2][i] >= 15)) {
            return true;
        }
    }


    if (belongs_to_one_player(this->board[0][0], this->board[1][1], this->board[2][2]) &&
        (this->board[0][0] + this->board[1][1] + this->board[2][2] >= 15)) {
        return true;
    }

    if (belongs_to_one_player(this->board[0][2], this->board[1][1], this->board[2][0]) &&
        (this->board[0][2] + this->board[1][1] + this->board[2][0] >= 15)) {
        return true;
    }

    return false;
}


template <typename T>
bool Numeric_Board<T>::is_draw() {
    return (this->n_moves == 9 && !is_win());
}

template <typename T>
bool Numeric_Board<T>::game_is_over() {
    return is_win() || is_draw();
}


template <typename T>
set<T> Numeric_Player<T>::used_numbers;


template <typename T>
Numeric_Player<T>::Numeric_Player(string name, T symbol, bool is_odd)
        : Player<T>(name, symbol), is_odd(is_odd) {

    for (T i = (is_odd ? 1 : 2); i <= 9; i += 2) {
        available_numbers.insert(i);
    }
}


template <typename T>
void Numeric_Player<T>::getmove(int& x, int& y) {
    T chosen_number;
    while (true) {
        cout << "\nPlease enter your move (x y) and your number ("
             << (is_odd ? "odd" : "even") << "): ";
        cin >> x >> y >> chosen_number;


        if (available_numbers.find(chosen_number) == available_numbers.end()) {
            cout << "Invalid number! Choose an available number.\n";
            continue;
        }
        if (used_numbers.find(chosen_number) != used_numbers.end()) {
            cout << "This number has already been used! Choose another number.\n";
            continue;
        }

        used_numbers.insert(chosen_number);
        available_numbers.erase(chosen_number);
        this->symbol = chosen_number;
        break;
    }
}
template <typename T>
Numeric_Random_Player<T>::Numeric_Random_Player(string name, T symbol, bool is_odd)
        : RandomPlayer<T>(symbol), is_odd(is_odd) {
    this->name = name;
    for (T i = (is_odd ? 1 : 2); i <= 9; i += 2) {
        available_numbers.insert(i);
    }
}

template <typename T>
void Numeric_Random_Player<T>::getmove(int& x, int& y) {
    while (true) {

        x = rand() % 3;
        y = rand() % 3;

        if (available_numbers.empty()) {
            cout << "No available numbers left for " << this->name << "!\n";
            break;
        }

        auto it = available_numbers.begin();
        std::advance(it, rand() % available_numbers.size());
        T chosen_number = *it;

        if (used_numbers.find(chosen_number) == used_numbers.end()) {
            used_numbers.insert(chosen_number);
            available_numbers.erase(chosen_number);
            this->symbol = chosen_number;
            break;
        }
    }
}


void game5_main() {
    srand(time(0));
    int choice;
    Player<int>* players[2];
    Numeric_Board<int>* board = new Numeric_Board<int>();
    string player1Name, player2Name;

    cout << "Welcome to FCAI Numerical Tic-Tac-Toe Game. :)\n";

    cout << "Enter Player 1 name (Odd Player): ";
    cin >> player1Name;
    cout << "Choose Player 1 type:\n";
    cout << "1. Human\n";
    cout << "2. Random Computer\n";
    cin >> choice;

    switch(choice) {
        case 1:
            players[0] = new Numeric_Player<int>(player1Name,0, true);
            break;
        case 2:
            players[0] = new Numeric_Random_Player<int>("Random Player 1", 1, true);
            break;
        default:
            cout << "Invalid choice for Player 1. Exiting the game.\n";

    }


    cout << "Enter Player 2 name (Even Player): ";
    cin >> player2Name;
    cout << "Choose Player 2 type:\n";
    cout << "1. Human\n";
    cout << "2. Random Computer\n";
    cin >> choice;

    switch(choice) {
        case 1:
            players[1] = new Numeric_Player<int>(player2Name,0, false);
            break;
        case 2:
            players[1] = new Numeric_Random_Player<int>("Random Player 1", 2, false);
            break;
        default:
            cout << "Invalid choice for Player 2. Exiting the game.\n";
    }

    GameManager<int> ticTacToeGame(board, players);
    ticTacToeGame.run();

    delete board;
    for (int i = 0; i < 2; ++i) {
        delete players[i];
    }
}


#endif