#ifndef TIC_TAC_TOE_H
#define TIC_TAC_TOE_H

#include <iostream>
#include "cmake-build-debug/BoardGame_Classes.h"
#include <string>
#include <iomanip>
#include <vector>
#include <cctype>
using namespace std;

class tic_board : public Board<char>
{
    int x_wins = 0;
    int o_wins = 0;
    string player_x_name;
    string player_o_name;

public:
    tic_board(string name1, string name2)
    {
        rows = 5;
        columns = 5;
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
    int calculate_wins()
    {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < columns - 2; j++)
            {
                // check horizontally
                if (board[i][j] != ' ' && board[i][j] == board[i][j + 1] && board[i][j] == board[i][j + 2] && board[i][j + 1] == board[i][j + 2])
                {
                    if (board[i][j] == 'X')
                        x_wins++;
                    else if (board[i][j] == 'O')
                        o_wins++;
                }
            }
        }
        // Check vertically
        for (int j = 0; j < columns; j++)
        {
            for (int i = 0; i < rows - 2; i++)
            {
                if (board[i][j] != ' ' &&
                    board[i][j] == board[i + 1][j] &&
                    board[i][j] == board[i + 2][j])
                {
                    if (board[i][j] == 'X')
                        x_wins++;
                    else if (board[i][j] == 'O')
                        o_wins++;
                }
            }
        }
        // Check diagonally (top-left to bottom-right)
        for (int i = 0; i < rows - 2; i++)
        {
            for (int j = 0; j < columns - 2; j++)
            {
                if (board[i][j] != ' ' &&
                    board[i][j] == board[i + 1][j + 1] &&
                    board[i][j] == board[i + 2][j + 2])
                {
                    if (board[i][j] == 'X')
                        x_wins++;
                    else if (board[i][j] == 'O')
                        o_wins++;
                }
            }
        }
        // Check diagonally (top-right to bottom-left)
        for (int i = 0; i < rows - 2; i++)
        {
            for (int j = 2; j < columns; j++)
            {
                if (board[i][j] != ' ' &&
                    board[i][j] == board[i + 1][j - 1] &&
                    board[i][j] == board[i + 2][j - 2])
                {
                    if (board[i][j] == 'X')
                        x_wins++;
                    else if (board[i][j] == 'O')
                        o_wins++;
                }
            }
        }

        return (x_wins > o_wins) ? x_wins : o_wins;
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

        cout << "  " << board[0][0] << "  |" << "  " << board[0][1] << "  |" << "  " << board[0][2] << "  |" << "  " << board[0][3] << "  |" << "  " << board[0][4] << endl;
        cout << "-----|-----|-----|-----|-----\n";
        cout << "  " << board[1][0] << "  |" << "  " << board[1][1] << "  |" << "  " << board[1][2] << "  |" << "  " << board[1][3] << "  |" << "  " << board[1][4] << endl;
        cout << "-----|-----|-----|-----|-----\n";
        cout << "  " << board[2][0] << "  |" << "  " << board[2][1] << "  |" << "  " << board[2][2] << "  |" << "  " << board[2][3] << "  |" << "  " << board[2][4] << endl;
        cout << "-----|-----|-----|-----|-----\n";
        cout << "  " << board[3][0] << "  |" << "  " << board[3][1] << "  |" << "  " << board[3][2] << "  |" << "  " << board[3][3] << "  |" << "  " << board[3][4] << endl;
        cout << "-----|-----|-----|-----|-----\n";
        cout << "  " << board[4][0] << "  |" << "  " << board[4][1] << "  |" << "  " << board[4][2] << "  |" << "  " << board[4][3] << "  |" << "  " << board[4][4] << endl;
    }
    bool is_win() override
    {
        if (n_moves == 24)
        {
            int max = calculate_wins();
            if (max == x_wins)
            {
                cout << "player :" << player_x_name << "  wins!\nHard luck to player  " << player_o_name << endl;
                exit(0);
            }
            if (max == o_wins)
            {
                cout << "player :" << player_o_name << "  wins!\nHard luck to player  " << player_x_name << endl;
                exit(0);
            }
        }
        else
            return false;
    }
    bool is_draw() override
    {
       return (n_moves == 24&& !is_win());
    }
    bool game_is_over() override
    {
        return is_win() || is_draw() || (n_moves == 24);
    }
};
class tic_player : public Player<char>
{
public:
    tic_player(string n, char s) : Player<char>(n, s) {}
    void getmove(int &x, int &y) override
    {
        cout <<"player "<<this->getsymbol()<<"turn "<<endl;
        cout << "Please Enter your move(row column)from 0 to 4 separated by space :";
        cin >> x >> y;

    }
};
class tic_randomplayer : public RandomPlayer<char>
{
public:
    tic_randomplayer(char s) : RandomPlayer<char>(s)
    {
        this->dimension = 5;
        this->name = "Random Computer Player";
        srand(static_cast<unsigned int>(time(0)));
    }
    void getmove(int &x, int &y) override
    {
        x = rand() % this->dimension;
        y = rand() % this->dimension;
    }
};

void tic_main()
{
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
        players[0] = new tic_player(playerXName, 'X');
        break;
    case 2:
        players[0] = new tic_randomplayer('X');
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
        players[1] = new tic_player(player2Name, 'O');
        break;
    case 2:
        players[1] = new tic_randomplayer('O');
        break;
    default:
        cout << "Invalid choice for Player 2. Exiting the game.\n";
        return;
    }
    Board<char> *B = new tic_board(playerXName, player2Name);
    GameManager<char> tic_game(B, players);
    tic_game.run();

    // Clean up
    delete B;
    for (int i = 0; i < 2; ++i)
    {
        delete players[i];
    }
}
#endif