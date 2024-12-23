#ifndef GAME9_H
#define GAME9_H
#include <iostream>
#include "cmake-build-debug/BoardGame_Classes.h"
#include <string>
#include <iomanip>
#include <vector>
#include <cctype>
using namespace std;
static Player<char> *players[2];
static int currentPlayerIndex = 0;
class sus_board : public Board<char>
{
    static int s_wins;
    static int u_wins;

public:
    sus_board()
    {

        rows = 3;
        columns = 3;
        n_moves = 0;
        this->board = new char *[this->rows];
        for (int i = 0; i < this->rows; i++)
        {
            this->board[i] = new char[this->columns];
            for (int j = 0; j < this->columns; j++)
            {
                this->board[i][j] = ' ';
            }
        }
    }
    bool update_board(int x, int y, char symbol) override
    {
        symbol = toupper(symbol);
        if (symbol != 'S' && symbol != 'U')
        {
            cout << "\n❌ Invalid symbol! This is a SUS game. Use only 'S' or 'U'.\n";
            return false;
        }
        if (x >= 0 && x < rows && y >= 0 && y < columns)
        {

            if (board[x][y] == ' ')
            {
                board[x][y] = symbol;
                n_moves++;
                currentPlayerIndex = (currentPlayerIndex + 1) % 2;
                return true;
            }
            else
            {
                cout << "\n⚠️ This square is already occupied. Please choose another one.\n";
                return false;
            }
        }
        else
        {
            cout << "Invalid row or column number be focus...\n";
            return false;
        }
    }
    void display_board() override
    {
        cout << "\n📝 Here's the current game board:\n";
        cout << "    0  |  1  |  2  \n";
        cout << "-|------------------\n";
        cout << "0|  " << board[0][0] << "  |" << "  " << board[0][1] << "  |" << "  " << board[0][2] << endl;
        cout << "-|-----|-----|-----\n";
        cout << "1|  " << board[1][0] << "  |" << "  " << board[1][1] << "  |" << "  " << board[1][2] << endl;
        cout << "-|-----|-----|-----\n";

        cout << "2|  " << board[2][0] << "  |" << "  " << board[2][1] << "  |" << "  " << board[2][2] << endl;
        cout << "✨ Keep going! The game is getting interesting!\n";
    }
    void wins_counter()
    {
        char symbol = players[(currentPlayerIndex + 1) % 2]->getsymbol();
        // check rows
        for (int i = 0; i < rows; i++)
        {
            if (board[i][0] == 'S' && board[i][1] == 'U' && board[i][2] == 'S')
            {
                if (symbol == 'S')
                {
                    s_wins++;
                }
                else if (symbol == 'U')
                {
                    u_wins++;
                }
            }
            // check columns
            if (board[0][i] == 'S' && board[1][i] == 'U' && board[2][i] == 'S')
            {
                if (symbol == 'S')
                {
                    s_wins++;
                }
                else if (symbol == 'U')
                {
                    u_wins++;
                }
            }
        }
        // check diagonal from top left to right
        if (board[0][0] == 'S' && board[1][1] == 'U' && board[2][2] == 'S')
        {
            if (symbol == 'S')
            {
                s_wins++;
            }
            else if (symbol == 'U')
            {
                u_wins++;
            }
        }
        // check diagonals from top right to left
        if (board[0][2] == 'S' && board[1][1] == 'U' && board[2][0] == 'S')
        {
            if (symbol == 'S')
            {
                s_wins++;
            }
            else if (symbol == 'U')
            {
                u_wins++;
            }
        }

    }

    bool is_win() override
    {
        if (n_moves == 9)
        {
            if (s_wins > u_wins)
            {
                cout << "player : " << players[0]->getname() << " Wins...\n";
                exit(0);
            }
            else if (u_wins > s_wins)
            {
                cout << "🎉 Congratulations, player : " << players[1]->getname() << " Wins...\n";
                exit(0);
            }
        }
        wins_counter();
        return false;
    }
    bool is_draw() override
    {
        return (n_moves == 9 && !is_win());
    }
    bool game_is_over() override
    {
        return is_win() || is_draw() || (n_moves == 24);
    }
};
int sus_board::s_wins = 0;
int sus_board::u_wins = 0;
class sus_player : public Player<char>
{
public:
    sus_player(string n, char s) : Player(n, s) {}
    void getmove(int &x, int &y) override
    {
        cout << "player " << this->getsymbol() << " turn " << endl;
        cout << "Please Enter your move(row column)from 0 to 2 separated by space :";
        cin >> x >> y;
    }
};
class sus_randomplayer : public RandomPlayer<char>
{
public:
    sus_randomplayer(char s) : RandomPlayer(s)
    {
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
void game9_main()
{
    int choice;

    string playerXName, player2Name;
    cout << "Enter Player S name: \n ";
    cin >> playerXName;
    cout << "Choose Player S type:\n";
    cout << "1. Human\n";
    cout << "2. Random Computer\n";
    cin >> choice;
    switch (choice)
    {
    case 1:
        players[0] = new sus_player(playerXName, 'S');
        break;
    case 2:
        players[0] = new sus_randomplayer('S');
        break;
    default:
        cout << "❌Invalid choice for Player 1. Exiting the game.\n";
        return;
    }
    cout << "Enter Player U name: ";
    cin >> player2Name;
    cout << "Choose Player U type:\n";
    cout << "1. Human\n";
    cout << "2. Random Computer\n";
    cin >> choice;

    switch (choice)
    {
    case 1:
        players[1] = new sus_player(player2Name, 'U');
        break;
    case 2:
        players[1] = new sus_randomplayer('U');
        break;
    default:
        cout << "❌Invalid choice for Player 2. Exiting the game.\n";
        return;
    }
    Board<char> *B = new sus_board();
    GameManager<char> sus_game(B, players);
    sus_game.run();

    // Clean up
    delete B;
    for (int i = 0; i < 2; ++i)
    {
        delete players[i];
    }
}
#endif // GAME9_H