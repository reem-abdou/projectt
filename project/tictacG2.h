#ifndef TOE_TAC_TIC_H
#define TOE_TAC_TIC_H
#include <iostream>
#include "cmake-build-debug/BoardGame_Classes.h"
#include <string>
#include <cctype>
using namespace std;
class toe_board : public Board<char> {
    string player_x_name, player_o_name;
    public:
    toe_board(string name1,string name2 ) {
        rows = 3;
        columns = 3;
        n_moves = 0;
        this->board = new char *[this->rows];
        for (int i = 0; i < rows; i++)
        {
            this->board[i] = new char[this->columns];
            for (int j = 0; j < columns; j++)
            {
                this->board[i][j] = ' ';
            }
        }
        player_x_name = name1;
        player_o_name = name2;
    }
    bool update_board(int x, int y, char symbol) override
    {

        if (x >= 0 && x < rows && y >= 0 && y < columns)
        {
            if (board[x][y] == ' ')
            {
                this->board[x][y] = toupper(symbol);
                this->n_moves++;
                return true;
            }
            else
            {
                cout << "This square busy try again" << endl;
                return false;
            }
        }
        else{
            cout << "Invalid row or column number be focus" << endl;
            return false;
        }
    }
    void display_board() override
    {

        cout << "  " << board[0][0] << "  |" << "  " << board[0][1] << "  |" << "  " << board[0][2]  << endl;
        cout << "-----|-----|-----\n";
        cout << "  " << board[1][0] << "  |" << "  " << board[1][1] << "  |" << "  " << board[1][2]  << endl;
        cout << "-----|-----|-----\n";

        cout << "  " << board[2][0] << "  |" << "  " << board[2][1] << "  |" << "  " << board[2][2] << endl;

    }
    bool is_win()override {
        //check horizontally
        for (int i = 0; i < rows; i++) {
           if (board[i][0] != ' '&&board[i][0]==board[i][1] && board[i][0]==board[i][2]&&board[i][1]==board[i][2]) {
               if (board[i][0] == 'X') {
                   cout << "player :" << player_o_name << "  wins!\nHard luck to player  " << player_x_name << endl;
                   exit(0);
               }else if (board[i][0] == 'O') {
                   cout << "player :" << player_x_name << "  wins!\nHard luck to player  " << player_o_name << endl;
                   return 0;
               }
           }
            //check vertically
            for (int i = 0; i < rows; i++) {
                if (board[0][i]!=' '&&board[0][i]==board[1][i]&&board[0][i]==board[2][i]&&board[1][i]==board[2][i]) {
                    if (board[0][i] == 'X') {
                        cout << "player :" << player_o_name << "  wins!\nHard luck to player  " << player_x_name << endl;
                        return 0;
                    }else if (board[0][i] == 'O') {
                        cout << "player :" << player_x_name << "  wins!\nHard luck to player  " << player_o_name << endl;
                        return 0;
                    }
                }
            }
            //check diagonal from top left to right
            if (board[0][0]!=' '&&board[0][0]==board[1][1]&&board[0][0]==board[2][2]&&board[1][1]==board[2][2]) {
                if (board[0][0] == 'X') {
                    cout << "player :" << player_o_name << "  wins!\nHard luck to player  " << player_x_name << endl;
                    return 0;
                }else if (board[0][0] == 'O') {
                    cout << "player :" << player_x_name << "  wins!\nHard luck to player  " << player_o_name << endl;
                    return 0;
                }
            }
            //check diagonal from top right to left
            if (board[0][2]!=' '&&board[0][2]==board[1][1]&&board[0][2]==board[2][0]&&board[1][1]==board[2][0]) {
                if (board[0][2] == 'X') {
                    cout << "player :" << player_o_name << "  wins!\nHard luck to player  " << player_x_name << endl;
                    return 0;
                }else if (board[0][2] == 'O') {
                    cout << "player :" << player_x_name << "  wins!\nHard luck to player  " << player_o_name << endl;
                    return 0;
                }
            }
        }return false;
    }
    bool is_draw() override {
        return (this->n_moves == 9 && !is_win());
    }
    bool game_is_over() override {
        return is_win() || is_draw();
    }
};
class toe_player : public Player<char> {
    public:
    toe_player(string n, char s) : Player<char>(n, s) {}
    void getmove(int &x, int &y) override {
        cout <<"player "<<this->getsymbol()<<"turn "<<endl;
        cout << "Please Enter your move(row column)from 0 to 2 separated by space :";
        cin >> x >> y;
    }

};
class toe_randomplayer : public RandomPlayer<char> {
    public:
    toe_randomplayer(char s) : RandomPlayer<char>(s) {
        this->dimension = 3;
        this->name = "Random Computer Player";
        srand(static_cast<unsigned int>(time(0)));
    }
    void getmove(int &x, int &y) override
    {
        x = rand() % this->dimension;
        y = rand() % this->dimension;
    }

};
void toe_main() {
    int choice;
    Player<char> *players[2];
    string playerXName, player2Name;
    cout << "Enter Player X name: ";
    cin >> playerXName;
    cout << "Choose Player X type:\n";
    cout << "1. Human\n";
    cout << "2. Random Computer\n";
    cin >> choice;
    switch (choice)
    {
        case 1:
            players[0] = new toe_player(playerXName, 'X');
        break;
        case 2:
            players[0] = new toe_randomplayer('X');
        break;
        default:
            cout << "Invalid choice for Player 1. Exiting the game.\n";
        return;
    }
    cout << "Enter Player 2 name: ";
    cin >> player2Name;
    cout << "Choose Player 2 type:\n";
    cout << "1. Human\n";
    cout << "2. Random Computer\n";
    cin >> choice;

    switch (choice)
    {
        case 1:
            players[1] = new toe_player(player2Name, 'O');
        break;
        case 2:
            players[1] = new toe_randomplayer('O');
        break;
        default:
            cout << "Invalid choice for Player 2. Exiting the game.\n";
        return;
    }

    Board<char> *B = new toe_board(playerXName, player2Name);
    GameManager<char> tic_game(B, players);
    tic_game.run();

    // Clean up
    delete B;
    for (int i = 0; i < 2; ++i)
    {
        delete players[i];
    }
}
#endif //TOE_TAC_TIC_H